#include "tagtreewidget.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMimeData>
#include <QStringListModel>
#include <QDropEvent>

TagGroup::TagGroup(QWidget *parent) : QWidget(parent),
    listName(),
    tagList()
{

}

TagTreeWidget::TagTreeWidget(QWidget *parent) : QTreeWidget(parent),
    tagInfo_filename(),
    allTags(NULL),
    tagGroups(),
    ignoreList()
{
    allTags = new TagGroup(this);
    allTags->listName = "All Tags";

}

void TagTreeWidget::setTagInfoFilename(QString fn) {
    tagInfo_filename = fn;
}

void TagTreeWidget::readTagInfo() {
    QFile textFile(tagInfo_filename);

    if (textFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream textStream(&textFile);
        while (true)
        {
            QString line = textStream.readLine();

            if ( !line.isNull()) {
                QStringList lineSplit = line.split("::");
                if (lineSplit.count() == 2){
                    TagGroup *nGroup = new TagGroup(this);
                    nGroup->listName = lineSplit.at(0);

                    nGroup->tagList = lineSplit.at(1).split("|");
                    tagGroups.append(nGroup);
                }
            }
            else {
                break;
            }

        }
    }

}

void TagTreeWidget::dropEvent(QDropEvent *event) {
    bool flag = false;

    QByteArray encoded = event->mimeData()->data("application/x-qabstractitemmodeldatalist");
    QDataStream stream(&encoded, QIODevice::ReadOnly);

    QTreeWidgetItem *item = this->itemAt(event->pos());
    if (item != NULL){
        QString target = item->text(0);
        if (target.contains(" :: ")){
            target.chop(target.length() - target.indexOf(" :: "));
        }
        if (!item->parent()){
            if (target != allTags->listName){
                QStringList tags = getTagsFromGroup(target);
                while(!stream.atEnd()) {
                    int row, col;
                    QMap<int, QVariant> roleDataMap;
                    stream>>row>>col>>roleDataMap;

                    QString tag = roleDataMap.value(0,"Error").toString();
                    if (!tag.contains(" :: ")) {
                        if (!tags.contains(tag,Qt::CaseInsensitive)){
                            //item->setText(0,target + " :: " + QString::number(item->childCount() + 1) + " tags");
                            flag = true;
                            addTagToGroup(target,tag);
                        }
                    }
                }

            }
        }

        if (!flag){
            event->accept();
        } else {
            event->ignore();
        }
    }
    QTreeWidget::dropEvent(event);

    updateTree();
    //
}

QStringList TagTreeWidget::getTagGroupNames() {
    QStringList groups;

    groups.append(allTags->listName);
    QMutableVectorIterator<TagGroup *> i(tagGroups);
    while(i.hasNext()){
        groups.append(i.peekNext()->listName);
        i.next();
    }
    return groups;
}

QStringList TagTreeWidget::getTagsFromGroup(QString group) {
    QStringList tags;

    if (allTags->listName == group) {
        return allTags->tagList;
    }
    else {
        QMutableVectorIterator<TagGroup *> i(tagGroups);
        while(i.hasNext()){
            if (i.peekNext()->listName == group){
                tags = i.peekNext()->tagList;
                break;
            }
            i.next();
        }
    }

    return tags;
}

void TagTreeWidget::addTagToGroup(QString group, QString ntag) {
    if (allTags->listName == group) {
        return;
    }
    else {
        QMutableVectorIterator<TagGroup *> i(tagGroups);
        while(i.hasNext()){
            if (i.peekNext()->listName == group){
                if (!i.peekNext()->tagList.contains(ntag)) {
                    i.peekNext()->tagList.append(ntag);
                }
                break;
            }
            i.next();
        }
    }

}

void TagTreeWidget::removeTagFromGroup(QString group, QString ntag) {

    if (group.contains(" :: ")) {
        group.chop(group.length() - group.indexOf(" ::"));
    }
    if (allTags->listName == group) {
        return;
    }
    else {
        QMutableVectorIterator<TagGroup *> i(tagGroups);
        while(i.hasNext()){
            if (i.peekNext()->listName == group){
                i.peekNext()->tagList.removeOne(ntag);
                break;
            }
            i.next();
        }
    }

    updateTree();
}

void TagTreeWidget::removeGroup(QString group) {
    if (group.contains(" :: ")) {
        group.chop(group.length() - group.indexOf(" ::"));
    }
    if (allTags->listName == group) {
        return;
    }
    else {
        QMutableVectorIterator<TagGroup *> i(tagGroups);
        while(i.hasNext()){
            if (i.next()->listName == group){
                i.remove();
                break;
            }
        }
    }
    updateTree();
}

void TagTreeWidget::updateTree() {
    this->clear();

    int tagCount = 0;
    if (allTags->tagList.count() > 0){
        QTreeWidgetItem *nTop = new QTreeWidgetItem(this);
        for(int j = 0; j < allTags->tagList.count(); j++){
            QTreeWidgetItem *nItem = new QTreeWidgetItem(nTop);
            nItem->setText(0,allTags->tagList.at(j));
            tagCount++;
        }
        nTop->setText(0,allTags->listName + " :: " + QString::number(tagCount) + " tags");
    }

    QMutableVectorIterator<TagGroup *> i(tagGroups);
    while(i.hasNext()) {
        TagGroup *cGroup = i.next();
        if ( !ignoreList.contains(cGroup->listName)) {
            QTreeWidgetItem *nTop = new QTreeWidgetItem(this);
            tagCount = 0;
            for(int j = 0; j < cGroup->tagList.count(); j++){
                if (allTags->tagList.count() == 0 || allTags->tagList.contains(cGroup->tagList.at(j),Qt::CaseInsensitive)){
                    QTreeWidgetItem *nItem = new QTreeWidgetItem(nTop);
                    nItem->setText(0,cGroup->tagList.at(j));
                    tagCount++;
                }
            }
            nTop->setText(0,cGroup->listName + " :: " + QString::number(tagCount) + " tags");
        }

    }

    sortItems(0,Qt::AscendingOrder);
}

void TagTreeWidget::addGroup(QString group) {
    TagGroup *nGroup = new TagGroup(this);
    int i = 1;
    QStringList gNames = getTagGroupNames();
    if ( gNames.contains(group)){
        while (gNames.contains(group + QString("(%1)").arg(i))){
            i++;
        }

        group.append(QString("(%1)").arg(i));
    }

    nGroup->listName = group;
    tagGroups.append(nGroup);
    updateTree();
}

void TagTreeWidget::duplicateGroup(QString group) {
    TagGroup *nGroup = new TagGroup(this);
    nGroup->tagList = getTagsFromGroup(group);

    int i = 1;
    while (getTagGroupNames().contains(group + QString("(%1)").arg(i))){
        i++;
    }
    group.append(QString("(%1)").arg(i));
    nGroup->listName = group;
    tagGroups.append(nGroup);
    updateTree();
}

void TagTreeWidget::updateAllTagList(QStringList list) {

    if (allTags != NULL) {
        allTags->tagList = list;
    }

}
