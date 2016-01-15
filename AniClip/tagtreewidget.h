#ifndef TAGTREEWIDGET_H
#define TAGTREEWIDGET_H

#include <QWidget>
#include <QTreeWidget>
#include <QString>
#include <QStringList>
#include <QVector>
#include <QAction>

enum {
    NEW_GROUP_INDEX = 0,
    DUP_GROUP_INDEX = 1,
    REMOVE_INDEX = 2,
    ADD_KEY_INDEX = 4,
    ADD_SUB_INDEX = 5
};

class TagGroup : public QWidget {

    Q_OBJECT
public :
    explicit TagGroup(QWidget *parent = 0);

public:
    QString listName;
    QStringList tagList;
};

class TagTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    explicit TagTreeWidget(QWidget *parent = 0);

    void setTagInfoFilename(QString fn);
    void readTagInfo();

    void dropEvent(QDropEvent *event);

    QStringList getTagGroupNames();
    QStringList getTagsFromGroup(QString);

    void addTagToGroup(QString group, QString ntag);
    void removeTagFromGroup(QString group, QString ntag);
    void removeGroup(QString group);
    void addGroup(QString group);
    void duplicateGroup(QString group);

    void updateTree();
    void updateAllTagList(QStringList list);

public:
    QString     tagInfo_filename;

    TagGroup           *allTags;
    QVector<TagGroup *> tagGroups;
    QStringList         ignoreList;

signals:

public slots:
};

#endif // TAGTREEWIDGET_H
