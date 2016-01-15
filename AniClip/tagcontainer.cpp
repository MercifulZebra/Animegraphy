#include "tagcontainer.h"

TagButtonBox::TagButtonBox(QWidget *parent) :
    QToolButton(parent),
    id(0),
    label(NULL)
{
    connect(this,SIGNAL(clicked(bool)),this,SLOT(custom_clicked()));
}

void TagButtonBox::custom_clicked() {
    emit removeBox(label->text(),id);
}


TagContainer::TagContainer(QWidget *parent) :
    QFrame(parent),
    boxBox(),
    currTop(6),
    box1(),
    box2(),
    box3(),
    box4(),
    box5(),
    box6()
{

}

void TagContainer::activateTag(QString tagName, int index) {
    switch(index) {
    case 1:
        box1->label->setText(tagName);
        box1->label->show();
        box1->show();
        break;

    case 2:
        box2->label->setText(tagName);
        box2->label->show();
        box2->show();
        break;

    case 3:
        box3->label->setText(tagName);
        box3->label->show();
        box3->show();
        break;

    case 4:
        box4->label->setText(tagName);
        box4->label->show();
        box4->show();
        break;

    case 5:
        box5->label->setText(tagName);
        box5->label->show();
        box5->show();
        break;

    case 6:
        box6->label->setText(tagName);
        box6->label->show();
        box6->show();
        break;
    }
    currTop = index;
}

void TagContainer::assembleBox() {
    boxBox.append(box1);
    boxBox.append(box2);
    boxBox.append(box3);
    boxBox.append(box4);
    boxBox.append(box5);
    boxBox.append(box6);
}

void TagContainer::deactivateTag(int index) {
    currTop--;
    for (int i = currTop; i < 6; i++){
        boxBox.at(i)->label->hide();
        boxBox.at(i)->hide();
    }

    for (int i = index - 1; i < 5; i++) {
        boxBox.at(i)->label->setText(boxBox.at(i+1)->label->text());
    }
}

void TagContainer::deactivateAllTags() {
    for(int i = 1; i <= 6; i ++) {
        deactivateTag(i);
    }
}

