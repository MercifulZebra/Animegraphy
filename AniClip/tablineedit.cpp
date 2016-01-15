#include "tablineedit.h"
#include <QKeyEvent>
#include <QCompleter>
#include <QAbstractItemView>
#include <QDebug>

TabLineEdit::TabLineEdit(QWidget *parent) : QLineEdit(parent)
{

}

void TabLineEdit::keyPressEvent(QKeyEvent *event){
    bool shift_key = false;
    int mod = 0;
    if (event->modifiers() == Qt::ShiftModifier){
        shift_key = true;
        mod = -1;
    }
    if ((event->key() + mod) == Qt::Key_Tab){

        if ( completer() != NULL) {
            if ( completer()->popup()->isVisible()){
                setText(completer()->currentCompletion());
            } else {
                emit switchFocus(!shift_key);
                return;
            }
        } else {
            emit switchFocus(!shift_key);
        }

    }
    QLineEdit::keyPressEvent(event);
}
