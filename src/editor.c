/*
 * editor.c -- Hold user inputs chars and preedit string
 *
 */

#ifdef HAVE_CONFIG_H
#include <config.h> // autotools
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h> // *nix
#include <execinfo.h> // dbg

// gettext
#ifdef HAVE_GETTEXT
#include <locale.h>
#include <libintl.h>
#define _(String) gettext (String)
#define gettext_noop(String) String
#define N_(String) gettext_noop (String)
#else
#define _(x) (x)
#define N_(x) (x)
#endif

#include "editor.h"

static void editor_class_init(EditorClass*);
static void editor_init(Editor*);

G_DEFINE_TYPE(Editor,editor,G_TYPE_OBJECT)

static void editor_class_init(EditorClass*klass)
{

}

static void editor_init(Editor* editor)
{

}
