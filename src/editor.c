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

/*
 * -1 非中文模式
 * 0 简体中文
 * 1 繁体中文
 * 2 is Big charset mode, but simplify Chinese first
 * 3 is Big charset mode, but traditional Chinese first
 * 4 is Big charset mode.
 */
gint editor_get_chinese_mode()
{
  //到环境变量拿
  char * lc = getenv("LC_CTYPE");
  if(!lc)
    lc = getenv("LANG");
  lc = g_utf8_strdown(g_strdup(lc),-1);

  char * zh = strstr(lc,"zh_");

  if (zh)
    {
      //简体？繁体？
      GStrv v = g_strsplit(zh,"_",3);

      g_free(lc);

      if(g_strcmp0(v[1],"cn")==0)
      {
        g_strfreev(v);
        return 0;
      }
      g_strfreev(v);
      return 1;
    }
  return -1;
}
