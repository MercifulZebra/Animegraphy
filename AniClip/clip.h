#ifndef CLIP_H
#define CLIP_H

#include <QWidget>
#include <QTime>

class Clip : public QWidget{
    Q_OBJECT
public:
    Clip(QWidget* parent = 0);
    ~Clip();

    bool hasTag(QString nTag);

public:
    QString     index_line;
    //char        error_flags;
    QString     showName;
    int         episodeNum;
    QTime       timeStart;
    QTime       timeEnd;
    QString     link;
    QStringList tags;
    QString     comment;
    QString     ClipsUsed;
    QString     Errors;
    QString     ID;
};

class ClipList : public QWidget{
    Q_OBJECT
public:
    ClipList(QWidget* parent = 0);

    bool importClipFile(QString index_filename);
    bool exportClipFile(QString index_filename);
    bool getTagList(QStringList *line, QStringList *nTags);
    Clip* getClipFromID(QString id);
    void removeDuplicates();
public:
    QVector<Clip *> list;
    QVector<Clip *> invalidList;
    QVector<Clip *> needIDList;
    QString         listName;

};

class ClipDatabase : public QWidget{
    Q_OBJECT
public:
    ClipDatabase(QWidget* parent = 0);

    void updateActiveList(QVector<ClipList *> nLists);
    void updateSuggestionLists(ClipList *nList);
    void updateSuggestionLists(Clip *nClip);
    void updateMainIDs();
    ClipList* getListByName(QString name);

public:
    QVector<ClipList *>     database;

    ClipList               *mainList;
    ClipList               *activeList;

    QStringList showName_list;
    QStringList tag_list;
};
#endif // CLIP_H
