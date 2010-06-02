/* vim:set et sts=4: */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h> // *nix
#include <execinfo.h> // dbg
#include <config.h> // autotools
// gettext
#ifdef HAVE_GETTEXT

#include <locale.h>
#include <libintl.h>

#define _(String) gettext (String)
#define gettext_noop(String) String
#define N_(String) gettext_noop (String)

#else

#define _(x) (x)

#endif

#include "engine.h"

int
main(int argc, char* argv[])
{
  // default if nth spec
  const gchar *datafile = PKGDATADIR"/tables/table.txt";
  const char *iconfile = PKGDATADIR"/icons/ibus-table.svg";

  gboolean have_ibus = FALSE;
  gchar *locale_dir = NULL;

  setlocale(LC_ALL, "");
  textdomain(GETTEXT_PACKAGE);

  GOptionEntry parameters[] =
    {
      { "ibus", '\0', 0, G_OPTION_ARG_NONE, &have_ibus },
      { "icon", '\0', 0, G_OPTION_ARG_STRING, &iconfile,
          _("Location of the logo."), N_("logofile") },
      { "table", '\0', 0, G_OPTION_ARG_STRING, &datafile,
          _("Location of the table."), N_("tablefile") },
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

  // create bus, factory, component
  IBusBus *bus = ibus_bus_new();
  g_signal_connect(bus, "disconnected", G_CALLBACK(ibus_quit), NULL);
  IBusFactory *factory = ibus_factory_new(ibus_bus_get_connection(bus));
  ibus_bus_request_name(bus, "org.freedesktop.IBus.Table", 0);
  IBusComponent *component = ibus_component_new("org.freedesktop.IBus.Table",
      _("Table Input Method"), PACKAGE_VERSION, "GPL", AUTHOR_EMAIL,
      PACKAGE_BUGREPORT, argv[0], GETTEXT_PACKAGE);

  if (!have_bus)
    {
      // as no daemon, create desc instantly; add eng to component
      IBusEngineDesc *desc = ibus_engine_desc_new("Table", "ibus-table",
          _("Table Input Method"), "zh_CN", "GPL", AUTHOR_EMAIL, iconfile,
          "us");
      ibus_component_add_engine(component, desc);
    }

  // reg component to daemon; add eng to factory
  ibus_bus_register_component(bus, component);
  ibus_factory_add_engine(factory, "Table", IBUS_TYPE_TABLE_ENGINE);

  g_object_unref(component);

  printf(_("ibus-table Version %s started.\n"), PACKAGE_VERSION);

  // call ibus after all sent
  ibus_main();
  return 0;
}
