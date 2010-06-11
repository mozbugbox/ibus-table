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

#include <ibus.h>
#include "editor.h"
#include "tabdict.h"

static void
editor_class_init(EditorClass*);
static void
editor_init(Editor*);
static void
editor_finalize(Editor* editor);
static void
editor_set_property(Editor *object, guint property_id, const GValue *value,
    GParamSpec *pspec);

G_DEFINE_TYPE(Editor,editor,G_TYPE_OBJECT)

static void editor_class_init(EditorClass*klass)
  {
    GParamSpec * spec;

    G_OBJECT_CLASS(klass)->finalize = (gpointer)editor_finalize;

    G_OBJECT_CLASS(klass)->set_property = (gpointer)editor_set_property;

    spec = g_param_spec_object("config","config","config",IBUS_TYPE_CONFIG,G_PARAM_WRITABLE);

    g_object_class_install_property(G_OBJECT_CLASS(klass),1,spec);

    spec = g_param_spec_pointer("db","db","db",G_PARAM_WRITABLE);

    g_object_class_install_property(G_OBJECT_CLASS(klass),2,spec);

    spec = g_param_spec_string("valid_input_chars","valid_input_chars","valid_input_chars","abcdefghijklmnopqrstuvwxz",G_PARAM_WRITABLE);

    g_object_class_install_property(G_OBJECT_CLASS(klass),3,spec);
  }

static void
editor_init(Editor* editor)
{
  editor->input = g_string_new("");
}

static void
editor_finalize(Editor* editor)
{
  g_string_free(editor->input, 1);
}

static void
editor_set_property(Editor *object, guint property_id, const GValue *value,
    GParamSpec *pspec)
{
  switch (property_id)
    {
  case 1:

    break;
  case 2:
    object->db = g_value_get_pointer(value);
    break;
  case 3:
    g_free(object->valid_input_chars);
    object->valid_input_chars = g_value_dup_string(value);
    }
}

Editor *
editor_new(IBusConfig * config, gchar * valid_inputchars, gint max_key_length,
    tabsqlitedb * db)
{
  return g_object_new(G_TYPE_EDITOR, "db", db, "config", config,
      "valid_input_chars", valid_inputchars, NULL);
}

static void
editor_do_prasese(Editor * editor)
{
  // del previous
  g_list_foreach(editor->prased, (GFunc) g_free, NULL);
  g_list_free(editor->prased);

  // parse new
  editor->prased = tabsqlitedb_prase(editor->db, editor->inputed);
}

gboolean
editor_append_input(Editor * editor, gchar key)
{
  Tab_key * tkey = tab_key_new(key);
  editor->inputed = g_list_append(editor->inputed, tkey);
  g_string_append_c(editor->input, key);
  if (strchr(editor->valid_input_chars, key))
    {
      Tab_key * tkey = tab_key_new(key);
      editor->inputed = g_list_append(editor->inputed, tkey);
      g_string_append_c(editor->input, key);
      editor_do_prasese(editor);
      return TRUE;
    }
  return FALSE;
}

gboolean
editor_backspace_input(Editor * editor)
{
  if (g_list_length(editor->inputed))
    {

      g_object_unref(g_list_last(editor->inputed)->data);

      editor->inputed = g_list_delete_link(editor->inputed, g_list_last(
          editor->inputed));

      g_string_truncate(editor->input, editor->input->len - 1);

      editor_do_prasese(editor);
      return TRUE;
    }
  return FALSE;
}

IBusText *
editor_get_auxiliary_text(Editor * editor)
{
  return ibus_text_new_from_string(editor->input->str);
}

IBusText *
editor_get_prasese(Editor * editor, guint page, guint index)
{
  gchar * str;

  if (g_list_length(editor->prased) >= page * 6 + index)
    return ibus_text_new_from_string(g_list_nth_data(editor->prased, page * 6
        + index));
  return NULL;
}

gint
editor_get_prasesed_count(Editor * editor)
{
  return g_list_length(editor->prased);
}

/*
 * -1 非中文模式
 * 0 简体中文
 * 1 繁体中文
 * 2 is Big charset mode, but simplify Chinese first
 * 3 is Big charset mode, but traditional Chinese first
 * 4 is Big charset mode.
 */
gint
editor_get_chinese_mode(Editor * editor)
{
  // get from env var
  char * lc = getenv("LC_CTYPE");
  if (!lc)
    lc = getenv("LANG");
  lc = g_utf8_strdown(g_strdup(lc), -1);

  char * zh = strstr(lc, "zh_");

  if (zh)
    {
      // SC | TC
      GStrv v = g_strsplit(zh, "_", 3);

      g_free(lc);

      if (g_strcmp0(v[1], "cn") == 0)
        {
          g_strfreev(v);
          return 0;
        }
      g_strfreev(v);
      return 1;
    }
  return -1;
}
