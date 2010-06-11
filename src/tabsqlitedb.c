/*- coding: utf-8 -*-
 * vim:et sts=4 sw=4

 #  ibus-table - The Tables engine for IBus
 #
 # Copyright (c) 2008-2009 Yu Yuwei <acevery@gmail.com>
 #
 # This library is free software; you can redistribute it and/or
 # modify it under the terms of the GNU Lesser General Public
 # License as published by the Free Software Foundation; either
 # version 2.1 of the License, or (at your option) any later version.
 #
 # This library is distributed in the hope that it will be useful,
 # but WITHOUT ANY WARRANTY; without even the implied warranty of
 # MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 # Lesser General Public License for more details.
 #
 # You should have received a copy of the GNU Lesser General Public
 # License along with this library; if not, write to the Free Software
 # Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

 */

#include "tabsqlitedb.h"

tabsqlitedb *
tabsqlitedb_new(const gchar * db, const gchar * udb)
{
  static gsize sqlite_initialized = 0;
  if (g_once_init_enter(&sqlite_initialized))
    {
      g_once_init_leave(&sqlite_initialized, !sqlite3_initialize());
    }
  tabsqlitedb * ret = g_new0(tabsqlitedb,1);

  sqlite3_open(db, &ret->db);

  if (udb)
    {
      sqlite3_open(db, &ret->udb);
    }

  return ret;
}

//sqlite3_stmt *
//tabsqlitedb_prepare(tabsqlitedb * db, const char * sql)
//{
//
//}

gboolean
tabsqlitedb_getime(tabsqlitedb * db, const char * attr, char ** val)
{
  const gchar * sql, *tail;
  sqlite3_stmt * stm;

  sql = g_strdup_printf("select val from ime where attr=\'%s\'", attr);

  sqlite3_prepare(db->db, sql, strlen(sql), &stm, &tail);

  sqlite3_step(stm);

  *val = g_strdup(sqlite3_column_text(stm, 0));

  sqlite3_finalize(stm);
}

void
tabsqlitedb_destory(tabsqlitedb * db)
{
  sqlite3_close(db->db);
  if (db->udb)
    sqlite3_close(db->udb);
}

char *
tabsqlitedb_convert(tabsqlitedb * db, const char * keys)
{
  // concat query condition of keys
  int i;
  const int keylen = strlen(keys);
  GString * query_cond = g_string_new("");
  for (i = 0; i < keylen; i++)
    {
        g_string_append_printf(query_cond," m%d=\'%d\' ",i, keys[i]);
        if (i != keylen - 1)
        g_string_append(query_cond, "AND");
    }

  // prep query, then statement
  char *sql = g_strdup_printf("SELECT phrase FROM phrases WHERE %s", query_cond->str);
  g_string_free(query_cond,TRUE);
  sqlite3_stmt * stm;

  char *val=NULL;

  do
    {
      if (sqlite3_prepare(db->db, sql, strlen(sql), &stm, NULL))
        break;
      if (sqlite3_step(stm)==SQLITE_ERROR)
        break;
      val = g_strdup(sqlite3_column_text(stm, 0));
      sqlite3_finalize(stm);
    }
  while (0);
  g_free(sql);
  return val;
}

