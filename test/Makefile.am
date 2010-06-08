
LIBS = @IBUS_LIBS@ @SQLITE3_LIBS@

testdir=$(pwd)

test_PROGRAMS = test_tabsqlitedb testsqlite3

test_tabsqlitedb_CFLAGS = @IBUS_CFLAGS@ -I$(top_srcdir)/src

test_tabsqlitedb_SOURCES = ../src/tabsqlitedb.c  test_tabsqlitedb.c

testsqlite3_SOURCES = testsqlite3.c

