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

#ifndef TABDICT_H_
#define TABDICT_H_

#include <glib-object.h>

typedef struct _Tab_key{
  GObject parent_class;
  guint   key;
  guint   id;
}Tab_key;

typedef struct _tab_key_class{
  GObjectClass parent_class;
  GTree * tab_dict;
}Tab_keyClass;

#define G_TYPE_TAB_KEY    tab_key_get_type()

#define TAB_KEY(obj)    (G_TYPE_CHECK_INSTANCE_CAST ((object), G_TYPE_TAB_KEY, Tab_key))

#define TAB_KEY_GET_CLASS(object)  (G_TYPE_INSTANCE_GET_CLASS ((object), G_TYPE_TAB_KEY, Tab_keyClass))

GType
tab_key_get_type();

Tab_key *
tab_key_new(gint m_key);

GList *
tab_key_parse(gchar * input); // Tab_key* 构成的列队


#endif /* TABDICT_H_ */
