/*
 * editor.h -- Hold user inputs chars and preedit string
 */

#ifndef EDITOR_H_
#define EDITOR_H_

#include <ibus.h>

typedef struct _Editor{
  GObject parent;

}Editor;

typedef struct _EditorClass{
  GObjectClass parent_class;

}EditorClass;

#endif /* EDITOR_H_ */
