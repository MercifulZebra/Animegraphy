#ifndef TAGCONTAINER_H
#define TAGCONTAINER_H

#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QToolButton>
#include <QString>
#include <QVector>

class TagButtonBox : public QToolButton
{
    Q_OBJECT
public:
    explicit TagButtonBox(QWidget *parent = 0);

public:
    int id;
    QLabel *label;

public slots:
    void custom_clicked();

signals:
    void removeBox(QString,int);

};

class TagContainer : public QFrame
{
    Q_OBJECT
public:
    explicit TagContainer(QWidget *parent = 0);

    void activateTag(QString tagName, int index);
    void assembleBox();
    void deactivateTag(int index);
    void deactivateAllTags();

public:
//    QLabel *label_tag1;
//    QLabel *label_tag2;
//    QLabel *label_tag3;
//    QLabel *label_tag4;
//    QLabel *label_tag5;
//    QLabel *label_tag6;

//    QToolButton *button_tag1;
//    QToolButton *button_tag2;
//    QToolButton *button_tag3;
//    QToolButton *button_tag4;
//    QToolButton *button_tag5;
//    QToolButton *button_tag6;

    QVector<TagButtonBox *> boxBox;
    int currTop;

    TagButtonBox *box1;
    TagButtonBox *box2;
    TagButtonBox *box3;
    TagButtonBox *box4;
    TagButtonBox *box5;
    TagButtonBox *box6;
signals:

public slots:
};

#endif // TAGCONTAINER_H
