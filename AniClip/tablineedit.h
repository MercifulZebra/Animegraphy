#ifndef TABLINEEDIT_H
#define TABLINEEDIT_H

#include <QWidget>
#include <QLineEdit>

class TabLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit TabLineEdit(QWidget *parent = 0);

    void keyPressEvent(QKeyEvent *);

signals:
    void switchFocus(bool);

public slots:
};

#endif // TABLINEEDIT_H
