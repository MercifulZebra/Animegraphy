#include "clip.h"
#include <QTextStream>
#include <QFile>
#include <QTime>

Clip::Clip(QWidget *parent) :
    QWidget(parent),
    index_line(""),
    //error_flags(""),
    showName(""),
    episodeNum(0),
    timeStart(0,0,0),
    timeEnd(0,0,0),
    link(""),
    tags(),
    comment("")
{

}

Clip::~Clip(){

}

bool Clip::hasTag(QString nTag){
    for (int i = 0; i < tags.size(); i++ ){
        if(tags.at(i) == nTag)
            return true;
    }
    return false;
}

ClipList::ClipList(QWidget *parent) :
    QWidget(parent),
    list(),
    invalidList(),
    listName()
{
}

bool ClipList::importClipFile(QString index_filename) {
    bool flag = true;

    QFile textFile(index_filename);

    if (textFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream textStream(&textFile);
        while (true)
        {
            QString line = textStream.readLine();
            bool validClip_flag = true;

            if ( !line.isNull()) {
                if ( !line.startsWith("#")){
                    QStringList newClipString = line.split("|");
                    Clip* newClip = new Clip();

                    if (newClipString.size() == 8) {

                        //////////////////////////////////////////////////////////////////////////////////////////////// Show Name
                        QString sect = newClipString.at(0);
                        sect = sect.trimmed();

                        newClip->showName = sect;
                        //////////////////////////////////////////////////////////////////////////////////////////////// Episode Num
                        bool validInt;
                        newClip->episodeNum = newClipString.at(1).toInt(&validInt);
                        validClip_flag = validClip_flag && validInt;
                        //////////////////////////////////////////////////////////////////////////////////////////////// Link
                        newClip->link = newClipString.at(3).trimmed();
                        //////////////////////////////////////////////////////////////////////////////////////////////// TimeStamp
                        QStringList timeFrame = newClipString.at(2).split(" - ");
                        if (timeFrame.size()==2) {
                            QStringList time = timeFrame.at(0).split(":");

                            int tInt[3];
                            tInt[2] = 0; tInt[1] = 0; tInt[0] = 0;
                            int t = 0;
                            if (time.size() > 2){
                                tInt[0] = time.at(t).toInt(&validInt);
                                t++;
                            }
                            tInt[1] = time.at(t++).toInt(&validInt);
                            validClip_flag = validClip_flag && validInt;
                            tInt[2] = time.at(t).toInt(&validInt);
                            validClip_flag = validClip_flag && validInt;

                            newClip->timeStart = QTime(tInt[0],tInt[1],tInt[2]);

                            time = timeFrame.at(1).split(":");
                            tInt[2] = 0; tInt[1] = 0; tInt[0] = 0;
                            t = 0;
                            if (time.size() > 2){
                                tInt[0] = time.at(t).toInt(&validInt);
                                t++;
                            }
                            tInt[1] = time.at(t++).toInt(&validInt);
                            validClip_flag = validClip_flag && validInt;
                            tInt[2] = time.at(t).toInt(&validInt);
                            validClip_flag = validClip_flag && validInt;

                            newClip->timeEnd = QTime(tInt[0],tInt[1],tInt[2]);

                        }
                        //////////////////////////////////////////////////////////////////////////////////////////////// Find Tags

                        QString tags = newClipString.at(4).trimmed();
                        QStringList nTags = tags.split(",");
                        newClip->tags.append(nTags);
                        newClip->tags.removeDuplicates();
                        //////////////////////////////////////////////////////////////////////////////////////////////// Comment
                        newClip->comment = newClipString.at(5).trimmed();
                        //////////////////////////////////////////////////////////////////////////////////////////////// ClipsUsed
                        newClip->ClipsUsed = newClipString.at(6).trimmed();
                        //////////////////////////////////////////////////////////////////////////////////////////////// REPAIRS
                        newClip->Errors = newClipString.at(7).trimmed();

                    } else {
                        validClip_flag = false;
                    }

                    if (validClip_flag){
                        //////////////////////////////////////////////////////////////////////////////////////////////// Interpret Clip as necessary (Check for overlap, Check For errors etc)
                        QString nameShort = newClip->showName.simplified();
                        nameShort = nameShort.replace(" ","");
                        newClip->ID = nameShort.toUpper() + QString::number(newClip->episodeNum) + newClip->timeStart.toString("hhmmss") + newClip->timeEnd.toString("hhmmss");
                        list.append(newClip);

                    }

                }

            } else {
                break;
            }
        }
    }


    return flag;
}

bool ClipList::exportClipFile(QString index_filename) {
    if (index_filename.isEmpty()) {
        index_filename = listName;
    }

    if (!index_filename.endsWith(".txt")) {
        index_filename.append(".txt");
    }

    QFile textFile(index_filename);

    if (textFile.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream textStream(&textFile);
        textFile.resize(0);
        textStream<<"## "<<index_filename<<endl<<endl;
        QMutableVectorIterator<Clip*>i(list);

        while(i.hasNext()){
            Clip* clip = i.next();
            textStream<<clip->showName<<" | ";
            textStream<<clip->episodeNum<<" | ";
            textStream<<clip->timeStart.toString("hh:mm:ss")<<" - "<<clip->timeEnd.toString("hh:mm:ss")<<" | ";
            textStream<<clip->link<<" | ";
            textStream<<clip->tags.at(0);
            for(int k = 1; k < clip->tags.count(); k++){
                textStream<<","<<clip->tags.at(k);
            }
            textStream<<" | ";
            textStream<<clip->comment<<" | ";
            textStream<<clip->ClipsUsed<<" | ";
            textStream<<clip->Errors;
            textStream<<"\n";

        }

    }
    return true;
}

bool ClipList::getTagList(QStringList *line, QStringList *nTags) {


    bool validTags = true;
    bool foundStart = false;
    bool validEnd = false;

    QStringList::iterator tagStart;
    QStringList::iterator tagEnd;

    for ( QStringList::iterator i = line->begin(); i != line->end(); i++){

        QString sect = *i;
        sect = sect.trimmed();

        if ( sect == "TAGEND"){
            validEnd = true;
            tagEnd = i;
            break;
        }else if (foundStart){
            nTags->append(sect);
        } else if ( sect == "TAGSTART"){
            foundStart = true;
            tagStart = i;
        }
    }
    if (validEnd && foundStart){
        line->erase(tagStart,++tagEnd);
    } else {
        validTags = false;
    }

    return validTags;
}

Clip* ClipList::getClipFromID(QString id) {
    QMutableVectorIterator<Clip *>i(list);
    while(i.hasNext()){
        Clip *next = i.next();
        if (next->ID == id){
            return next;
        }
    }

    return NULL;
}

void ClipList::removeDuplicates() {
    QMutableVectorIterator<Clip *>i(list);
    QMutableVectorIterator<Clip *>j(list);
    QStringList idList;
    while(i.hasNext()){
        Clip* next = i.next();
        if (!idList.contains(next->ID)){
            idList.append(next->ID);
        }
        else {
            i.remove();
        }
    }
}

ClipDatabase::ClipDatabase(QWidget *parent) :
    QWidget(parent),
    database(),
    mainList(NULL),
    activeList(NULL)
{
    activeList = new ClipList(this);
}

void ClipDatabase::updateActiveList(QVector<ClipList *> nLists) {
    QMutableVectorIterator<ClipList *> i(nLists);
    activeList->list.clear();
    while ( i.hasNext() ) {
         QMutableVectorIterator<Clip *> j(i.next()->list);
         while ( j.hasNext() ) {
             activeList->list.append(j.next());
         }
    }

}

void ClipDatabase::updateSuggestionLists(ClipList *nList) {
    for (int i = 0; i < nList->list.size(); i++) {
        updateSuggestionLists(nList->list.at(i));
    }
}

void ClipDatabase::updateSuggestionLists(Clip *nClip) {
    tag_list.append(nClip->tags);
    tag_list.removeDuplicates();

    showName_list.append(nClip->showName);
    showName_list.removeDuplicates();

}

void ClipDatabase::updateMainIDs() {
    QMutableVectorIterator<Clip *> i(mainList->needIDList);
    while (i.hasNext()) {
        Clip *next = i.next();
        QString name = next->showName.simplified();
        QString nameend = next->showName.simplified();
        name.replace(" ","");
        nameend.replace(" ","");
        name = name.leftJustified(4,'X',true) ;
        nameend = nameend.right(5);
        next->ID = name.toUpper() + nameend.toUpper() + QString::number(next->episodeNum) + next->timeStart.toString("mmss") + next->timeEnd.toString("mmss") + QDateTime::currentDateTime().toString("hms");
        mainList->list.append(next);
        i.remove();
    }
}

ClipList* ClipDatabase::getListByName(QString name) {
    QMutableVectorIterator<ClipList *>i(database);
    while(i.hasNext()){
        ClipList *next = i.next();
        if (next->listName == name){
            return next;
        }
    }

    return NULL;
}
