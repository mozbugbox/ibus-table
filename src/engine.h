/* vim:set et sts=4: */
#ifndef __ENGINE_H__
#define __ENGINE_H__

#include <ibus.h>

typedef struct _PHRASER PHRASER;
typedef struct _IBusTableEngine IBusTableEngine;
typedef struct _IBusTableEngineClass IBusTableEngineClass;

typedef struct _MATCHED MATCHED;

struct _MATCHED{
  char  code[64-16];
  char  hanzi[16];
};

struct _IBusTableEngine
{
  IBusEngine parent;

  /* members */

  IBusLookupTable *table;
};

struct _IBusTableEngineClass
{
  IBusEngineClass parent;
  GString * icondir;
  PHRASER * phraser;
  int  (*commit_string)(IBusTableEngine *engine, guint index);
};

#define IBUS_TYPE_TABLE_ENGINE	\
	(ibus_table_engine_get_type ())

GType
ibus_table_engine_get_type(void);

#define IBUS_TABLE_ENGINE_GET_CLASS(obj)	((IBusTableEngineClass*)(IBUS_ENGINE_GET_CLASS(obj)))

#define IBUS_TABLE_ENGINE(obj)             \
    (G_TYPE_CHECK_INSTANCE_CAST ((obj), IBUS_TYPE_TABLE_ENGINE, IBusTableEngine))

struct _PHRASER
{
  char * filename;
  char * start_ptr; // for nmaped access
  size_t fsize; //for nmaped access
};
PHRASER * phraser_new(const gchar * file);
void phraser_free(PHRASER*phraser);
int phraser_optimise(PHRASER * phraser);
int phraser_get_phrases(GArray * result, GString * input, PHRASER * phraser);

extern const gchar * datafile;
extern const char * icondir;
extern IBusBus *bus;

#endif
