/* vim:set et sts=4: */

#include <config.h>

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

/* functions prototype */
static void
ibus_table_engine_class_init(IBusTableEngineClass *klass);

static GObject *
ibus_table_constructor(GType type, guint n_construct_properties,GObjectConstructParam *construct_properties);

static void
ibus_table_engine_init(IBusTableEngine *engine);
static void
ibus_table_engine_destroy(IBusTableEngine *engine);
static gboolean
ibus_table_engine_process_key_event(IBusEngine *engine, guint keyval,
    guint keycode, guint modifiers);
static void
ibus_table_engine_focus_in(IBusEngine *engine);
static void
ibus_table_engine_focus_out(IBusEngine *engine);
static void
ibus_table_engine_reset(IBusEngine *engine);
static void
ibus_engine_set_cursor_location(IBusEngine *engine, gint x, gint y, gint w,
    gint h);
static void
ibus_table_engine_set_capabilities(IBusEngine *engine, guint caps);
static void
ibus_table_engine_page_up(IBusEngine *engine);
static void
ibus_table_engine_page_down(IBusEngine *engine);
static void
ibus_table_engine_cursor_up(IBusEngine *engine);
static void
ibus_table_engine_cursor_down(IBusEngine *engine);
static void
ibus_enchant_property_activate(IBusEngine *engine, const gchar *prop_name,
    gint prop_state);
static void
ibus_table_engine_property_show(IBusEngine *engine, const gchar *prop_name);
static void
ibus_table_engine_property_hide(IBusEngine *engine, const gchar *prop_name);
static int
ibus_table_engine_commit_string(IBusTableEngine *engine, guint index);

G_DEFINE_TYPE(IBusTableEngine,ibus_table_engine,IBUS_TYPE_ENGINE);

static void
ibus_table_engine_class_init(IBusTableEngineClass *klass)
{
  IBusObjectClass *ibus_object_class = IBUS_OBJECT_CLASS (klass);
  IBusEngineClass *engine_class = IBUS_ENGINE_CLASS (klass);

  G_OBJECT_CLASS(klass)->constructor = ibus_table_constructor ;

  ibus_object_class->destroy = (IBusObjectDestroyFunc) ibus_table_engine_destroy;

  engine_class->process_key_event = ibus_table_engine_process_key_event;

  engine_class->enable = ibus_table_engine_focus_in;

  engine_class->disable = ibus_table_engine_focus_out;

  engine_class->focus_in = ibus_table_engine_focus_in;

  engine_class->focus_out = ibus_table_engine_focus_out;

  klass->icondir = g_string_new(icondir);

  klass->commit_string = ibus_table_engine_commit_string;
}

static void
ibus_table_engine_init(IBusTableEngine *engine)
{
  size_t i;
  IBusTableEngineClass* klass;

  engine->page_size = 6 ;

  engine->proplist = ibus_prop_list_new();

  g_object_ref_sink(engine->proplist);

  GString * iconname = g_string_new("");

  g_string_printf(iconname,"%s/chinese.svg",icondir);

  IBusProperty * property = ibus_property_new("im-mode",PROP_TYPE_NORMAL,
      ibus_text_new_from_static_string(_("switch to english")),
      iconname->str,ibus_text_new_from_static_string(_("switch to english")),
      TRUE,TRUE,PROP_STATE_INCONSISTENT,NULL);

  ibus_prop_list_append(engine->proplist,property);

  g_string_printf(iconname,"%s/sc-mode.svg",icondir);

  property = ibus_property_new("im-mode",PROP_TYPE_NORMAL,
      ibus_text_new_from_static_string(_("简繁模式")),
      iconname->str,ibus_text_new_from_static_string(_("toggle chinese")),
      TRUE,TRUE,PROP_STATE_INCONSISTENT,NULL);

  ibus_prop_list_append(engine->proplist,property);

  g_string_printf(iconname,"%s/half-letter.svg",icondir);

  property = ibus_property_new("letter-mode", PROP_TYPE_NORMAL,
      ibus_text_new_from_static_string(_("半角")), iconname->str,
      ibus_text_new_from_static_string(_("toggle half/full")), TRUE, TRUE,
      PROP_STATE_INCONSISTENT, NULL);

  ibus_prop_list_append(engine->proplist,property);

  g_string_free(iconname,TRUE);

  engine->table = ibus_lookup_table_new(engine->page_size,0,TRUE,0);



  klass = IBUS_TABLE_ENGINE_GET_CLASS(engine);

}

static GObject *
ibus_table_constructor(GType type, guint n_construct_properties,GObjectConstructParam *construct_properties)
{
  GObject *  obj =  G_OBJECT_CLASS(ibus_table_engine_parent_class)->constructor(type,n_construct_properties,construct_properties);

  const gchar * name = ibus_engine_get_name(IBUS_ENGINE(obj));

  //TODO: open .db file according to engine name

  gchar * dbname = g_hash_table_lookup(name_2_db,name);

  g_print("Engine: %s,DB File: %s\n",name,dbname);

  IBUS_TABLE_ENGINE(obj)->db =  tabsqlitedb_new(dbname,0);

  return obj;
}

static void
ibus_table_engine_destroy(IBusTableEngine *engine)
{
  g_print("%s\n", __func__);//, engine->laststate.x, engine->laststate.y);

  IBUS_OBJECT_CLASS(ibus_table_engine_parent_class)->destroy(IBUS_OBJECT(engine));
}

static int ibus_table_engine_commit_string(IBusTableEngine *engine, guint index)
{
//	if (engine->matched->len > index)
//	{
//		ibus_engine_commit_text((IBusEngine *) engine,
//				ibus_text_new_from_static_string(
//						g_array_index(engine->matched,MATCHED,index).hanzi));
//		g_string_truncate(engine->inputed, 0);
//		return TRUE;
//	}
	return FALSE;
}

static gboolean
ibus_table_engine_update(IBusTableEngine *engine)
{
//	gtk_container_remove(GTK_CONTAINER(engine->box),engine->tables);
 //gdk_window_invalidate_rect(engine->LookupTable->window,0,0);
 return TRUE;
}

#define is_alpha(c) (((c) >= IBUS_a && (c) <= IBUS_z) || ((c) >= IBUS_A && (c) <= IBUS_Z))

static gboolean
ibus_table_engine_process_key_event(IBusEngine *ibusengine, guint keyval,
    guint keycode, guint modifiers)
{

  IBusText *text;
  IBusTableEngine *engine = (IBusTableEngine *) ibusengine;

  if (modifiers & IBUS_RELEASE_MASK)
    return FALSE;

  modifiers &= (IBUS_CONTROL_MASK | IBUS_MOD1_MASK);

  g_print("%s\n",__func__);

  switch (keyval)
    {
  case IBUS_space:
  case IBUS_Return:
//	  if(engine->inputed->len)
		  return ibus_table_engine_commit_string(engine, 0);
//	  else return FALSE;
  case IBUS_Escape:

    return TRUE;

  case IBUS_Left:
    return TRUE;

  case IBUS_Up:

    return TRUE;

  case IBUS_Down:

    return TRUE;

  case IBUS_BackSpace:
//    if (engine->inputed->len)
      {
//        g_string_truncate(engine->inputed, (engine->inputed->len) -1);
        return ibus_table_engine_update(engine);
      }
    return FALSE;
  case IBUS_0 ... IBUS_9:
    return ibus_table_engine_commit_string(engine, keyval - IBUS_0);
    }

  return FALSE;
}

static void
ibus_table_engine_focus_in(IBusEngine *engine)
{
  IBusTableEngine * ibus_table = IBUS_TABLE_ENGINE(engine);

  ibus_engine_register_properties(engine,ibus_table->proplist);

  IBUS_ENGINE_CLASS(ibus_table_engine_parent_class)->focus_in(engine);
}

static void
ibus_table_engine_focus_out(IBusEngine *engine)
{
  IBusTableEngine * ibus_table = IBUS_TABLE_ENGINE(engine);

  IBUS_ENGINE_CLASS(ibus_table_engine_parent_class)->focus_out(engine);
}
