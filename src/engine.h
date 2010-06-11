/* vim:set et sts=4: */
#ifndef __ENGINE_H__
#define __ENGINE_H__

#include <glib.h>
#include <ibus.h>
#include "tabsqlitedb.h"
#include "tabdict.h"

typedef struct _IBusTableEngine IBusTableEngine;
typedef struct _IBusTableEngineClass IBusTableEngineClass;

// eng data struct funcs
struct _IBusTableEngine
{
  IBusEngine parent;
  IBusLookupTable *table;
  IBusPropList * proplist;
  Editor * editor;
  gchar * valid_input_chars;
  guint page_size;
  tabsqlitedb * db;
};

struct _IBusTableEngineClass
{
  IBusEngineClass parent;
  GString *icondir;
  int
  (*commit_string)(IBusTableEngine *engine, guint index);
};

#define IBUS_TYPE_TABLE_ENGINE (ibus_table_engine_get_type ())
#define IBUS_TABLE_ENGINE_GET_CLASS(obj) ((IBusTableEngineClass*)(IBUS_ENGINE_GET_CLASS(obj)))
#define IBUS_TABLE_ENGINE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), IBUS_TYPE_TABLE_ENGINE, IBusTableEngine))

GType
ibus_table_engine_get_type(void);

// extern vars
extern const gchar *datafile;
extern const char *icondir;
extern IBusBus *bus;
extern GHashTable *name_2_db;

#endif
