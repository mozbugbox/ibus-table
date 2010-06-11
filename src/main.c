/* vim:set et sts=4: */

#ifdef HAVE_CONFIG_H
#include <config.h> // autotools
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h> // *nix
#include <execinfo.h> // dbg
#include <glob.h>
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

#include "engine.h"

// extern vars
IBusBus *bus = NULL;
const gchar *tabledbdir = PKGDATADIR"/tables";
const char *icondir = PKGDATADIR"/icons/";
GHashTable *name_2_db;

IBusEngineDesc *
ibus_table_make_engine(const gchar * tablename)
{
  gchar * name, *longname, *description, *license, *author, *icon;
  // open db file
  tabsqlitedb * db = tabsqlitedb_new(tablename, NULL);

  tabsqlitedb_getime(db, "name", &name);
  tabsqlitedb_getime(db, "name.zh_cn", &longname);
  tabsqlitedb_getime(db, "description", &description);
  tabsqlitedb_getime(db, "author", &author);
  tabsqlitedb_getime(db, "license", &license);
  tabsqlitedb_getime(db, "icon", &icon);

  char * iconfile = g_strdup_printf("%s/%s", icondir, icon);

  IBusEngineDesc * desc = ibus_engine_desc_new(name, longname, description,
      "zh", license, author, iconfile, "us");

  g_free(longname);
  g_free(description);
  g_free(author);
  g_free(icon);
  g_free(license);

  tabsqlitedb_destory(db);

  g_hash_table_insert(name_2_db, name, g_strdup(tablename));
  return desc;
}

static IBusComponent *
ibus_table_get_component(const gchar * execfile, const gchar * table)
{
  glob_t globs =
    { 0 };

  IBusComponent * component = ibus_component_new("org.freedesktop.IBus.Table",
      _("Table Input Method"), PACKAGE_VERSION, "GPL", AUTHOR_EMAIL,
      PACKAGE_BUGREPORT, execfile, GETTEXT_PACKAGE);

  // change to table directory
  chdir(tabledbdir);

  name_2_db = g_hash_table_new(g_str_hash, g_str_equal);

  if (table)
    {
      IBusEngineDesc * desc = ibus_table_make_engine(table);
      ibus_component_add_engine(component, desc);
    }
  else
    {
      glob("*.db", GLOB_DOOFFS, NULL, &globs);

      for (int i = 0; i < globs.gl_pathc; i++)
        {
          IBusEngineDesc * desc = ibus_table_make_engine(globs.gl_pathv[i]);
          ibus_component_add_engine(component, desc);
        }
      globfree(&globs);
    }
  return component;

}

static void
print_engines_xml(IBusComponent *component)
{
  GString *output;

  output = g_string_new("");

  ibus_component_output_engines(component, output, 0);

  write(STDOUT_FILENO, output->str, output->len);

  exit(EXIT_SUCCESS);
}

int
main(int argc, char* argv[])
{
  // default if nth spec

  IBusComponent *component;
  gboolean have_ibus = FALSE;
  gboolean have_xml = FALSE;
  gchar *locale_dir = NULL;
  gchar *dbname = NULL;

  setlocale(LC_ALL, "");
  textdomain(GETTEXT_PACKAGE);

  GOptionEntry parameters[] =
    {
      { "ibus", '\0', 0, G_OPTION_ARG_NONE, &have_ibus },
      { "xml", '\0', 0, G_OPTION_ARG_NONE, &have_xml },
      { "table", 't', 0, G_OPTION_ARG_STRING, &dbname, _("name of the table."),
          N_("table name") },
    //========= for test
          { "icon", '\0', 0, G_OPTION_ARG_STRING, &icondir,
              _("Location of the logo."), N_("logofile") },
          { "tabledir", '\0', 0, G_OPTION_ARG_STRING, &tabledbdir,
              _("Location of the tables."), N_("table dir") },
          { "locale", '\0', 0, G_OPTION_ARG_STRING, &locale_dir,
              _("Path of the locale."), N_("locale") },
          { 0 } };

  ibus_init();

  // arg params
  GOptionContext *context = g_option_context_new("");
  g_option_context_add_main_entries(context, parameters, GETTEXT_PACKAGE);
  g_assert(g_option_context_parse(context, &argc, &argv, NULL));
  g_option_context_free(context);

  if (locale_dir)
    bindtextdomain(GETTEXT_PACKAGE, locale_dir);

  component = ibus_table_get_component(argv[0],dbname);

  if (have_xml) // according to *.db generation for ibus usable xml desc file in dir
    {
      print_engines_xml(component);
    }

  // create bus, factory, component
  bus = ibus_bus_new();
  g_signal_connect(bus, "disconnected", G_CALLBACK(ibus_quit), NULL);

  IBusFactory *factory = ibus_factory_new(ibus_bus_get_connection(bus));

  GList *p, *engines = ibus_component_get_engines(component);
  for (p = engines; p != NULL; p = p->next)
    {
      IBusEngineDesc *engine = (IBusEngineDesc *) p->data;
      ibus_factory_add_engine(factory, engine->name, IBUS_TYPE_TABLE_ENGINE);
    }

  if (!have_ibus)
    {
      // reg component to daemon; add eng to factory
      ibus_bus_register_component(bus, component);
    }

  ibus_bus_request_name(bus, "org.freedesktop.IBus.Table", 0);

  g_object_unref(component);

  printf(_("ibus-table Version %s started.\n"), PACKAGE_VERSION);

  // call ibus after all sent
  ibus_main();
  return 0;
}

