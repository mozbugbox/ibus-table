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
#ifdef HAVE_CONFIG_H
#include <config.h> // autotools
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h> // *nix
#include <execinfo.h> // dbg

#include <ibus.h>

#include "tabdict.h"

static void
tab_key_class_init(Tab_keyClass * klass);

static void
tab_key_init(Tab_key * tabkey);

static void
tab_key_set_porperty(GObject *object, guint property_id, const GValue *value,GParamSpec *pspec);

G_DEFINE_TYPE(Tab_key,tab_key,G_TYPE_OBJECT);

static gchar tab_dict_id_key_map[] =
  {
      '0',
      'a', 'b', 'c', 'd', 'e',
      'f', 'g', 'h', 'i', 'j',
      'k', 'l', 'm', 'n', 'o',
      'p', 'q', 'r', 's', 't',
      'u', 'v', 'w', 'x', 'y',
      'z', '\'', ';', '`', '~',
      '!', '@', '#', '$', '%',
      '^', '&', '*', '(', ')',
      '-', '_', '=', '+', '[',
      ']', '{', '}', '|', '/',
      ':', '\"',  '<', '>', ',',
      '.', '?', '\\', 'A', 'B',
      'C', 'D', 'E', 'F', 'G',
      'H', 'I', 'J', 'K', 'L',
      'M', 'N', 'O', 'P', 'Q',
      'R', 'S', 'T', 'U', 'V',
      'W', 'X', 'Y', 'Z', '0',
      '1', '2', '3', '4', '5',
      '6', '7', '8', '9'
  };

static gint
tab_dict_val_comp(gconstpointer a, gconstpointer b)
{
  return GPOINTER_TO_INT(a) - GPOINTER_TO_INT(b);
}

static void tab_key_class_init(Tab_keyClass * klass)
{
  int i;
  GParamSpec * spec;
  GTree * tab_dict =  klass->tab_dict = g_tree_new(tab_dict_val_comp);

  for (i; i < G_N_ELEMENTS(tab_dict_id_key_map); i++)
    {
      g_tree_insert(tab_dict,GINT_TO_POINTER(tab_dict_id_key_map[i]),GINT_TO_POINTER(i));
    }

  G_OBJECT_CLASS(klass)->set_property = tab_key_set_porperty;

  spec = g_param_spec_int("key","key","key",0,255,0,G_PARAM_WRITABLE);

  g_object_class_install_property(G_OBJECT_CLASS(klass),1,spec);

  spec = g_param_spec_int("id","id","id",0,94,0,G_PARAM_WRITABLE);

  g_object_class_install_property(G_OBJECT_CLASS(klass),2,spec);
}

static void tab_key_init(Tab_key * tabkey)
{

}

static void
tab_key_set_porperty(GObject *object, guint property_id, const GValue *value,GParamSpec *pspec)
{
  switch (property_id)
    {
  case 1:
    TAB_KEY(object)->key = g_value_get_int(value);
    TAB_KEY(object)->id = GPOINTER_TO_INT(g_tree_lookup(TAB_KEY_GET_CLASS(object)->tab_dict,GINT_TO_POINTER(TAB_KEY(object)->key)));
    break;
  case 2:
    TAB_KEY(object)->id = g_value_get_int(value);
    TAB_KEY(object)->key = tab_dict_id_key_map[TAB_KEY(object)->id];
    break;
  default:
    break;
    }
}

Tab_key *
tab_key_new(gint m_key)
{
  return g_object_new(G_TYPE_TAB_KEY,"key",m_key,NULL);
}

Tab_key *
tab_key_new_with_id(gint m_key_id)
{
  return g_object_new(G_TYPE_TAB_KEY,"id",m_key_id,NULL);
}

GList *
tab_key_parse(gchar * input)
{
  int i;
  int len = strlen(input);

  GList * list = NULL;

  for (i = 0; i < len; i++)
    {
      list = g_list_append(list, tab_key_new(input[i]));
    }
  return list;
}

gchar tab_key_deparse(gint key_id)
{
  return tab_dict_id_key_map[key_id];
}

static gchar * chinese_nocheck_chars =
"“”‘’《》〈〉〔〕「」『』【】〖〗（）［］｛｝"
"．。，、；：？！…—·ˉˇ¨々～‖∶＂＇｀｜"
"⒈⒉⒊⒋⒌⒍⒎⒏⒐⒑⒒⒓⒔⒕⒖⒗⒘⒙⒚⒛"
"АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯЁ"
"ⅠⅡⅢⅣⅤⅥⅦⅧⅨⅩⅪⅫ"
"⒈⒉⒊⒋⒌⒍⒎⒏⒐⒑⒒⒓⒔⒕⒖⒗⒘⒙⒚⒛"
"㎎㎏㎜㎝㎞㎡㏄㏎㏑㏒㏕"
"ΑΒΓΔΕΖΗΘΙΚΛΜΝΞΟΠΡΣΤΥΦΧΨΩ"
"⑴⑵⑶⑷⑸⑹⑺⑻⑼⑽⑾⑿⒀⒁⒂⒃⒄⒅⒆⒇"
"€＄￠￡￥"
"¤→↑←↓↖↗↘↙"
"ァアィイゥウェエォオカガキギクグケゲコゴサザシジ"
"スズセゼソゾタダチヂッツヅテデトドナニヌネノハバパ"
"ヒビピフブプヘベペホボポマミムメモャヤュユョヨラ"
"リルレロヮワヰヱヲンヴヵヶーヽヾ"
"ぁあぃいぅうぇえぉおかがきぎぱくぐけげこごさざしじ"
"すずせぜそぞただちぢっつづてでとどなにぬねのはば"
"ひびぴふぶぷへべぺほぼぽまみむめもゃやゅゆょよらり"
"るれろゎわゐゑをん゛゜ゝゞ"
"勹灬冫艹屮辶刂匚阝廾丨虍彐卩钅冂冖宀疒肀丿攵凵犭"
"亻彡饣礻扌氵纟亠囗忄讠衤廴尢夂丶"
"āáǎàōóǒòêēéěèīíǐìǖǘǚǜüūúǔù"
"＋－＜＝＞±×÷∈∏∑∕√∝∞∟∠∣∥∧∨∩∪∫∮"
"∴∵∶∷∽≈≌≒≠≡≤≥≦≧≮≯⊕⊙⊥⊿℃°‰"
"♂♀§№☆★○●◎◇◆□■△▲※〓＃＆＠＼＾＿￣"
"абвгдежзийклмнопрстуфхцчшщъыьэюяё"
"ⅰⅱⅲⅳⅴⅵⅶⅷⅸⅹβγδεζηαικλμνξοπρστυφθψω"
"①②③④⑤⑥⑦⑧⑨⑩①②③④⑤⑥⑦⑧⑨⑩"
"㈠㈡㈢㈣㈤㈥㈦㈧㈨㈩㈠㈡㈢㈣㈤㈥㈦㈧㈨㈩"
"ㄅㄆㄇㄈㄉㄊㄋㄌㄍㄎㄏㄐㄑㄒㄓㄔㄕㄖㄗㄘㄙㄧㄨㄩ"
"ㄚㄛㄜㄝㄞㄟㄠㄡㄢㄣㄤㄥㄦ";
