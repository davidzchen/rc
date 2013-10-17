// var.c: provide "public" functions for adding and removing variables from 
// the symbol table.

#include "common.h"
#include "nalloc.h"
#include "utils.h"
#include "list.h"
#include "convert.h"
#include "print.h"
#include "wait.h"
#include "status.h"
#include "hash.h"
#include "variable.h"

static void variable_colon_assign(char *, List *, bool);
static void variable_list_assign(char *, List *, bool);
static int variable_has_alias(char *);

static char *const aliases[] = {
  "home", "HOME", "path", "PATH", "cdpath", "CDPATH"
};

// assign a variable in List form to a name, stacking if appropriate.
extern void variable_assign(char *name, List *def, bool stack) {
  Variable *new;
  // Important to do the listcpy first; get_var_place() frees old values.
  List *newdef = listcpy(def, ealloc); 
  new = get_var_place(name, stack);
  new->def = newdef;
  new->extdef = NULL;
  set_exportable(name, TRUE);
#if READLINE
  if (interactive && (streq(name, "TERM") || streq(name, "TERMCAP"))) {
    rl_reset_terminal(NULL);
  }
#endif
}

// Assign a variable in string form. Check to see if it is aliased 
// (e.g., PATH and path).
extern bool variable_assign_string(char *extdef) {
  static bool aliasset[arraysize(aliases)] = {
    FALSE, FALSE, FALSE, FALSE, FALSE, FALSE
  };
  char *name = get_name(extdef);
  Variable *new;
  int i;
  if (name == NULL) {
    // Add it to bozo env.
    return FALSE; 
  }
  if ((i = variable_has_alias(name)) != -1) {
    aliasset[i] = TRUE;
    // Set i to the "opposite" case subscript.
    i ^= 1;
    // don't alias variables that are already set in upper case.
    if (i&1 && aliasset[i]) {
      return TRUE;
    }
  }
  new = get_var_place(name, FALSE);
  new->def = NULL;
  new->extdef = ealloc(strlen(extdef) + 1);
  strcpy(new->extdef, extdef);
  if (i != -1) {
    variable_alias(name, variable_lookup(name), FALSE);
  }
  set_exportable(name, TRUE);
  return TRUE;
}

// Return a List based on a name lookup. If the list is in external (string) 
// form, convert it to internal (List) form. Treat $n (n is an integer) 
// specially as $*(n). Also check to see if $status is being dereferenced. 
// (we lazily evaluate the List associated with $status)
extern List *variable_lookup(char *name) {
  Variable *look;
  List *ret, *l;
  int sub;
  if (streq(name, "apids")) {
    return sgetapids();
  }
  if (streq(name, "status")) {
    return sgetstatus();
  }
  // handle $1, $2, etc.
  if (*name != '\0' && (sub = a2u(name)) != -1) { 
    for (l = variable_lookup("*"); l != NULL && sub != 0; --sub) {
      l = l->n;
    }
    if (l == NULL) {
      return NULL;
    }
    ret = nnew(List);
    ret->w = l->w;
    ret->m = NULL;
    ret->n = NULL;
    return ret;
  }
  look = lookup_var(name);
  if (look == NULL) {
    // not found
    return NULL;
  }
  if (look->def != NULL) {
    return look->def;
  }
  if (look->extdef == NULL) {
    // Variable was set to null, e.g., a=() echo foo.
    return NULL; 
  }
  ret = parse_var(look->extdef);
  if (ret == NULL) {
    look->extdef = NULL;
    return NULL;
  }
  return look->def = ret;
}

// lookup a variable in external (string) form, converting if necessary. Used 
// by makeenv().
extern char *variable_lookup_string(char *name) {
  Variable *look;
  look = lookup_var(name);
  if (look == NULL) {
    return NULL;
  }
  if (look->extdef != NULL) {
    return look->extdef;
  }
  if (look->def == NULL) {
    return NULL;
  }
  return look->extdef = mprint("%F=%W", name, look->def);
}

// remove a variable from the symtab. "stack" determines whether a level of 
// scoping is popped or not.
extern void variable_remove(char *name, bool stack) {
  int i = variable_has_alias(name);
  if (streq(name, "*") && !stack) { 
    // when assigning () to $*, we want to preserve $0.
    variable_assign("*", variable_lookup("0"), FALSE);
    return;
  }
  delete_var(name, stack);
  if (i != -1) {
    delete_var(aliases[i^1], stack);
  }
}

// assign a value (List) to a variable, using array "a" as input. Used to 
// assign $*
extern void variable_star_assign(char *dollarzero, char **a, bool stack) {
  List *s, *var;
  var = nnew(List);
  var->w = dollarzero;
  if (*a == NULL) {
    var->n = NULL;
    variable_assign("*", var, stack);
    return;
  }
  var->n = s = nnew(List);
  while (1) {
    s->w = *a++;
    if (*a == NULL) {
      s->n = NULL;
      break;
    } else {
      s = s->n = nnew(List);
    }
  }
  variable_assign("*", var, stack);
}

// (ugly name, huh?) assign a colon-separated value to a variable (e.g., PATH) 
// from a List (e.g., path)
static void variable_colon_assign(char *name, List *def, bool stack) {
  List dud;
  if (def == NULL) {
    variable_assign(name, NULL, stack);
    return;
  }
  dud.w = nprint("%-L", def, ":");
  dud.n = NULL;
  variable_assign(name, &dud, stack);
}

// assign a List variable (e.g., path) from a colon-separated string
// (e.g., PATH).
static void variable_list_assign(char *name, List *def, bool stack) {
  List *val, *r;
  char *v, *w;
  if (def == NULL) {
    variable_assign(name, NULL, stack);
    return;
  }
  v = def->w;
  r = val = nnew(List);
  while ((w = strchr(v, ':')) != NULL) {
    *w = '\0';
    r->w = ncpy(v);
    *w = ':';
    v = w + 1;
    r = r->n = nnew(List);
  }
  r->w = ncpy(v);
  r->n = NULL;
  variable_assign(name, val, stack);
}

// Check to see if a particular variable is aliased; return -1 on failure, or 
// the index.
static int variable_has_alias(char *name) {
  int i;
  for (i = 0; i < arraysize(aliases); i++) {
    if (streq(name, aliases[i])) {
      return i;
    }
  }
  return -1;
}

// Alias a variable to its lowercase equivalent. function pointers are used to 
// specify the conversion function.
extern void variable_alias(char *name, List *s, bool stack) {
  static void (*vectors[])(char *, List *, bool) = {
    variable_assign, 
    variable_assign, 
    variable_colon_assign, 
    variable_list_assign, 
    variable_colon_assign, 
    variable_list_assign
  };
  int i = variable_has_alias(name);
  if (i != -1) {
    // xor hack to reverse case of alias entry.
    (*vectors[i])(aliases[i ^ 1], s, stack);
  }
}

extern void variable_prettyprint(int fd, char *name, List *s) {
  int i;
  static const char * const keywords[] = {
    "if", "in", "fn", "for", "else", "switch", "while", "case"
  };
  if (s == NULL) {
    fprint(fd, "%S=()\n", name);
    return;
  }
  if (streq(name, "*")) {
    s = s->n;
    // Don't print $0, and if $* is not set, skip it.
    if (s == NULL) {
      return;
    }
  }
  for (i = 0; i < arraysize(keywords); i++)
    if (streq(keywords[i], name)) {
      fprint(fd, "%#S=", name);
      goto value;
    }
  fprint(fd, "%S=", name);
value:
  fprint(fd, s->n == NULL ? "%L\n" : "(%L)\n", s, " ");
}
