# vim:set et ts=4:
#
# ibus-table - The table engine for IBus
#
# Copyright (c) 2007 Yu Yuwei <acevery at gmail.com>
# Copyright (c) 2010 microcai  <microcai at fedoraproject.org>
# Copyright (c) 2010 Caius 'kaio' Chance <kaio at fedoraproject.net>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

libexecdir = ${prefix}/share/ibus/engine

INCLUDES =  @IBUS_CFLAGS@ -DPKGDATADIR=\"$(pkgdatadir)\" -DPREFIX=\"$(prefix)\"

LIBS = @IBUS_LIBS@ @SQLITE3_LIBS@

libexec_PROGRAMS = ibus-engine-table

ibus_engine_table_SOURCES =  main.c 	engine.c 	engine.h tabdict.c tabdict.h tabsqlitedb.c tabsqlitedb.h

component_DATA = table.xml 

componentdir = @datadir@/ibus/component

EXTRA_DIST = table.xml.in

CLEANFILES = \
	table.xml \
	$(NULL)

table.xml : table.xml.in
	( \
		libexecdir=${libexecdir}; \
		pkgdatadir=${pkgdatadir}; \
		s=`cat $<`; \
		eval "echo \"$${s}\""; \
	) > $@

test: ibus-engine-table
	$(builddir)/$<  --icon $(top_srcdir)/icons/ --table $(top_srcdir)/tables/table.txt
