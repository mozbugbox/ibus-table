/*
 * test_tabsqlitedb.c
 *
 *  Created on: 2010/06/08
 *      Author: cchance
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tabsqlitedb.h"

int
main(int argc, char ** argv)
{
  // load db
  char *dbfile = "./cangjie5.db";
  tabsqlitedb *ret = tabsqlitedb_new(dbfile, NULL);
  if (ret)
    printf("db is loaded: %s\n", dbfile);
  else
    printf("db load failed.\n");

  // 25, 13, 13, 18 -> 言 (for num:key refer to tabdict class)
  char keys[] =
    { 25, 13, 13, 18, '\0' };
  if (keys)
    printf("Keys in tabdict num: %d %d %d %d\n", keys[0], keys[1], keys[2], keys[3]);

  // test conversion
  char *val = tabsqlitedb_convert(ret, keys);
  if (val)
    printf("Converted phrase: %s\n", val);
  else
    printf("Conversion failed.\n");

  return 1;
}
