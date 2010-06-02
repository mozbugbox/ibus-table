/* vim:set et sts=4: */
#ifndef __ENGINE_H__
#define __ENGINE_H__

#include <ibus.h>

typedef struct
{
  char code[64 - 16];
  char hanzi[16];
} MATCHED;

// eng data struct funcs
typedef struct
{
  IBusEngine parent;
  IBusLookupTable *table;
} IBusTableEngine;

typedef struct
{
  IBusEngineClass parent;
  GString *icondir;
  PHRASER *phraser;
  int
  (*commit_string)(IBusTableEngine *engine, guint index);
} IBusTableEngineClass;

#define IBUS_TYPE_TABLE_ENGINE (ibus_table_engine_get_type ())
#define IBUS_TABLE_ENGINE_GET_CLASS(obj) ((IBusTableEngineClass*)(IBUS_ENGINE_GET_CLASS(obj)))
#define IBUS_TABLE_ENGINE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), IBUS_TYPE_TABLE_ENGINE, IBusTableEngine))

GType
ibus_table_engine_get_type(void);

// PHRASER data struct and funcs
struct
{
  char *filename;
  char *start_ptr; // for nmaped access
  size_t fsize; //for nmaped access
} PHRASER;

PHRASER *
phraser_new(const gchar * file);
void
phraser_free(PHRASER*phraser);
int
phraser_optimise(PHRASER * phraser);
int
phraser_get_phrases(GArray * result, GString * input, PHRASER * phraser);

// extern vars
extern const gchar *datafile;
extern const char *iconfile;
extern IBusBus *bus;

#endif
