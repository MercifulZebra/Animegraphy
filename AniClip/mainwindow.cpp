#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "tablineedit.h"

#include <QFile>
#include <QTextStream>
#include <QCompleter>
#include <QStringListModel>
#include <QKeyEvent>
#include <QFocusEvent>
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QMimeData>
#include <QMetaEnum>
#include <QMap>
#include <QEvent>
#include <QDebug>
#include <QMutableVectorIterator>
#include <QDesktopServices>
#include <QInputDialog>
#include <QDir>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    index_filename("index.txt"),
    list_filename("listIndex.txt"),
    showHistory_filename("showHistory.txt"),
    tagHistory_filename("tagHistory.txt"),
    tagGroup_filename("tagGroups.txt"),
    clipDB(NULL),
    activeTreePool(NULL),
    currTreeList(NULL),
    currShowString(""),
    currEpMin(0),
    currEpMax(1000),
    currKeyWordList(),
    currKeyTags(),
    currSubTags(),
    updated_flags(),
    nextKeyTagBox(),
    nextSubTagBox(),
    keyTagContainer(NULL),
    subTagContainer(NULL),
    tagItemContextMenu(NULL),
    clipItemContextMenu(NULL),
    clipAddMenu(NULL),
    clipRemoveMenu(NULL)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{

    clipDB->mainList->exportClipFile("index.txt");
    QMutableVectorIterator<ClipList *>i(clipDB->database);
    while(i.hasNext()){
        ClipList *next = i.next();
        next->exportClipFile("");
    }
    delete ui;
}

void MainWindow::init() {
    qDebug()<<"MW"<<QDir::current();

    init_objects();
    init_lists();
    init_completers();
    init_eventFilters();
    init_listTree();
    init_connections();
    init_tagBoxes();
    init_tagTree();
    init_contextMenus();

}

void MainWindow::init_objects() {
    clipDB = new ClipDatabase(this);
    currTreeList = new ClipList(this);
}

void MainWindow::init_lists() {
    // Read Main List
    ClipList *nList = new ClipList(this);
    nList->importClipFile(index_filename);
    nList->listName = "Main Index";
    clipDB->mainList = nList;
    if (!clipDB->mainList->needIDList.isEmpty()){
        clipDB->updateMainIDs();
    }
    clipDB->updateSuggestionLists(nList);

    //setActiveTreePool(nList);
    QVector<ClipList*> v;
    v.append(nList);
    clipDB->updateActiveList(v);
    updateClipTreeList();

    // Read listIndex

    bool flag = true;

    QFile textFile(list_filename);

    if (textFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream textStream(&textFile);
        while (true)
        {
            QString line = textStream.readLine();

            if ( !line.isNull()) {
                if ( !line.startsWith("#")){
                    ClipList *nClipList = new ClipList(this);
                    nClipList->importClipFile(line);
                    nClipList->listName = line;
                    clipDB->database.append(nClipList);
                }
            }
            else {
                break;
            }
        }
    }
}

void MainWindow::init_eventFilters() {
    ui->frame_KeyTags->installEventFilter(this);
    ui->frame_SubTags->installEventFilter(this);
}

void MainWindow::init_completers() {
    QStringListModel *tagModel = new QStringListModel(this);
    tagModel->setStringList(clipDB->tag_list);
    QCompleter *tagCompleter = new QCompleter(tagModel, this);
    tagCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    ui->edit_KeyTags->setCompleter(tagCompleter);
    ui->edit_SubTags->setCompleter(tagCompleter);

    QStringListModel *nameModel = new QStringListModel(this);
    nameModel->setStringList(clipDB->showName_list);
    QCompleter* nameCompleter = new QCompleter(nameModel, this);
    nameCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    ui->edit_Name->setCompleter(nameCompleter);
}

void MainWindow::init_connections() {
    connect(ui->edit_Name,SIGNAL(switchFocus(bool)),this,SLOT(tabSwitch(bool)));
    connect(ui->edit_EpNum,SIGNAL(switchFocus(bool)),this,SLOT(tabSwitch(bool)));
    connect(ui->edit_KeyTags,SIGNAL(switchFocus(bool)),this,SLOT(tabSwitch(bool)));
    connect(ui->edit_SubTags,SIGNAL(switchFocus(bool)),this,SLOT(tabSwitch(bool)));
    connect(ui->edit_KeyWords,SIGNAL(switchFocus(bool)),this,SLOT(tabSwitch(bool)));

    connect(ui->edit_KeyTags,SIGNAL(returnPressed()),this,SLOT(onKeyTag_entered()));
    connect(ui->button_AddKeyTag,SIGNAL(clicked()),this,SLOT(onKeyTag_entered()));

    connect(ui->edit_SubTags,SIGNAL(returnPressed()),this,SLOT(onSubTag_entered()));
    connect(ui->button_AddSubTag,SIGNAL(clicked()),this,SLOT(onSubTag_entered()));

    connect(ui->button_keyTag1,SIGNAL(removeBox(QString,int)),this,SLOT(onTagDelete_pressed(QString,int)));
    connect(ui->button_keyTag2,SIGNAL(removeBox(QString,int)),this,SLOT(onTagDelete_pressed(QString,int)));
    connect(ui->button_keyTag3,SIGNAL(removeBox(QString,int)),this,SLOT(onTagDelete_pressed(QString,int)));
    connect(ui->button_keyTag4,SIGNAL(removeBox(QString,int)),this,SLOT(onTagDelete_pressed(QString,int)));
    connect(ui->button_keyTag5,SIGNAL(removeBox(QString,int)),this,SLOT(onTagDelete_pressed(QString,int)));
    connect(ui->button_keyTag6,SIGNAL(removeBox(QString,int)),this,SLOT(onTagDelete_pressed(QString,int)));

    connect(ui->button_subTag1,SIGNAL(removeBox(QString,int)),this,SLOT(onTagDelete_pressed(QString,int)));
    connect(ui->button_subTag2,SIGNAL(removeBox(QString,int)),this,SLOT(onTagDelete_pressed(QString,int)));
    connect(ui->button_subTag3,SIGNAL(removeBox(QString,int)),this,SLOT(onTagDelete_pressed(QString,int)));
    connect(ui->button_subTag4,SIGNAL(removeBox(QString,int)),this,SLOT(onTagDelete_pressed(QString,int)));
    connect(ui->button_subTag5,SIGNAL(removeBox(QString,int)),this,SLOT(onTagDelete_pressed(QString,int)));
    connect(ui->button_subTag6,SIGNAL(removeBox(QString,int)),this,SLOT(onTagDelete_pressed(QString,int)));

    connect(ui->tree_Clips,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),this,SLOT(onTreeWidgetItem_doubleclicked(QTreeWidgetItem*,int)));

    connect(ui->tree_List,SIGNAL(itemChanged(QTreeWidgetItem*,int)),this,SLOT(onListTreeItemChanged(QTreeWidgetItem*,int)));

}

void MainWindow::init_tagBoxes() {

    nextKeyTagBox = 1;
    nextSubTagBox = 1;

    keyTagContainer = new TagContainer(this);
    subTagContainer = new TagContainer(this);

    keyTagContainer->box1 = ui->button_keyTag1;
    keyTagContainer->box1->label = ui->label_keyTag1;
    keyTagContainer->box2 = ui->button_keyTag2;
    keyTagContainer->box2->label = ui->label_keyTag2;
    keyTagContainer->box3 = ui->button_keyTag3;
    keyTagContainer->box3->label = ui->label_keyTag3;
    keyTagContainer->box4 = ui->button_keyTag4;
    keyTagContainer->box4->label = ui->label_keyTag4;
    keyTagContainer->box5 = ui->button_keyTag5;
    keyTagContainer->box5->label = ui->label_keyTag5;
    keyTagContainer->box6 = ui->button_keyTag6;
    keyTagContainer->box6->label = ui->label_keyTag6;

    subTagContainer->box1 = ui->button_subTag1;
    subTagContainer->box1->label = ui->label_subTag1;
    subTagContainer->box2 = ui->button_subTag2;
    subTagContainer->box2->label = ui->label_subTag2;
    subTagContainer->box3 = ui->button_subTag3;
    subTagContainer->box3->label = ui->label_subTag3;
    subTagContainer->box4 = ui->button_subTag4;
    subTagContainer->box4->label = ui->label_subTag4;
    subTagContainer->box5 = ui->button_subTag5;
    subTagContainer->box5->label = ui->label_subTag5;
    subTagContainer->box6 = ui->button_subTag6;
    subTagContainer->box6->label = ui->label_subTag6;

    keyTagContainer->box1->id = 1;
    keyTagContainer->box2->id = 2;
    keyTagContainer->box3->id = 3;
    keyTagContainer->box4->id = 4;
    keyTagContainer->box5->id = 5;
    keyTagContainer->box6->id = 6;

    subTagContainer->box1->id = 1;
    subTagContainer->box2->id = 2;
    subTagContainer->box3->id = 3;
    subTagContainer->box4->id = 4;
    subTagContainer->box5->id = 5;
    subTagContainer->box6->id = 6;

    subTagContainer->assembleBox();
    keyTagContainer->assembleBox();

    subTagContainer->deactivateAllTags();
    keyTagContainer->deactivateAllTags();


}

void MainWindow::init_clipTree() {

}

void MainWindow::init_tagTree() {
    ui->tree_Tags->setTagInfoFilename(tagGroup_filename);
    ui->tree_Tags->readTagInfo();
    ui->tree_Tags->updateAllTagList(clipDB->tag_list);
    ui->tree_Tags->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->tree_Tags->updateTree();

}

void MainWindow::init_listTree() {

    showListTree();
}

void MainWindow::init_contextMenus() {
    tagItemContextMenu = new QMenu(this);
    tagItemContextMenu->addAction("New Tag Group");
    tagItemContextMenu->addAction("Duplicate Group");
    tagItemContextMenu->addAction("Remove Tag");
    tagItemContextMenu->addSeparator();
    tagItemContextMenu->addAction(" - Key Tag");
    tagItemContextMenu->addAction(" - Sub Tag");
    ui->tree_Tags->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(ui->tree_Tags,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(onTreeContextMenu(QPoint)));
    connect(tagItemContextMenu,SIGNAL(triggered(QAction*)),this,SLOT(onTreeContextMenuSelect(QAction*)));

    clipItemContextMenu = new QMenu(this);
    ui->tree_Clips->setContextMenuPolicy(Qt::CustomContextMenu);
    clipAddMenu = new QMenu(this);
    clipItemContextMenu->addMenu(clipAddMenu);
    clipRemoveMenu = new QMenu(this);
    clipItemContextMenu->addMenu(clipRemoveMenu);
    connect(ui->tree_Clips,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(onClipTreeContextMenu(QPoint)));
    connect(clipItemContextMenu,SIGNAL(triggered(QAction*)),this,SLOT(onClipTreeContextMenuSelect(QAction*)));



}

void MainWindow::clearSearchBoxes() {
    ui->edit_Name->clear();
    ui->edit_EpNum->clear();
    ui->edit_KeyWords->clear();
    ui->edit_KeyTags->clear();
    ui->edit_SubTags->clear();
    currKeyWordList.clear();
    currSubTags.clear();
    keyTagContainer->deactivateAllTags();
    subTagContainer->deactivateAllTags();
}

bool MainWindow::eventFilter(QObject *target, QEvent *event) {

    if (target->objectName() == "frame_KeyTags" || target->objectName() == "frame_SubTags") {
        QFrame *nFrame = static_cast<QFrame*>(target);

        if (event->type() == QEvent::DragEnter) {
            QDragEnterEvent* nEnter = static_cast<QDragEnterEvent *>(event);
            if (nEnter->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist")){
                nFrame->setLineWidth(nFrame->lineWidth() + 2);
                nEnter->acceptProposedAction();
            }
        }
        else if (event->type() == QEvent::DragLeave) {
            QDragLeaveEvent* nLeave = static_cast<QDragLeaveEvent *>(event);
            nFrame->setLineWidth(nFrame->lineWidth() - 2);
            nLeave->accept();
        }
        else if (event->type() == QEvent::Drop ) {
            QDropEvent *nDrop = static_cast<QDropEvent *>(event);
            nFrame->setLineWidth(nFrame->lineWidth() - 2);

            QByteArray encoded = nDrop->mimeData()->data("application/x-qabstractitemmodeldatalist");
            QDataStream stream(&encoded, QIODevice::ReadOnly);

            while(!stream.atEnd()) {
                int row, col;
                QMap<int, QVariant> roleDataMap;
                stream>>row>>col>>roleDataMap;

                QString tag = roleDataMap.value(0,"Error").toString();
                if (tag.contains(" :: ")) {
                    tag.chop(tag.length() - tag.indexOf(" ::"));
                }
                if (target->objectName() == "frame_KeyTags"){
                    addKeyTags(tag);
                }
                else {
                    addSubTags(tag);
                }
            }
            nDrop->accept();
        }

    }
    return QMainWindow::eventFilter(target,event);
}

void MainWindow::updateClipTreeList() {

    currTreeList->list = clipDB->activeList->list;

    updateTreeByName();
    updateTreeByNum();
    updateTreeByKeyword();
    updateTreeByTags();

    showClipTree(currTreeList);

}

void MainWindow::updateTreeByName() {
    QMutableVectorIterator<Clip *> i(currTreeList->list);
    while ( i.hasNext() ) {
        if ( !(i.next()->showName.contains(currShowString))) {
            i.remove();
        }
    }


}

void MainWindow::updateTreeByNum() {
    QMutableVectorIterator<Clip *> i(currTreeList->list);
    while ( i.hasNext() ) {
        if ( !(i.peekNext()->episodeNum >= currEpMin && i.peekNext()->episodeNum <= currEpMax)) {
            i.next();
            i.remove();
        } else {
            i.next();
        }
    }
}

void MainWindow::updateTreeByKeyword() {
    QMutableVectorIterator<Clip *> i(currTreeList->list);

    while ( i.hasNext() ) {
        bool remove_flag = false;
        for (int j = 0; j < currKeyWordList.count(); j++){
            if (!i.peekNext()->comment.contains(currKeyWordList.at(j),Qt::CaseInsensitive)){
                remove_flag = true;
            }
        }
        i.next();
        if ( remove_flag ) {
            i.remove();
        }
    }
}

void MainWindow::updateTreeByTags() {

    QMutableVectorIterator<Clip *> i(currTreeList->list);
    while ( i.hasNext() ) {
        bool flag = false;

        QString currTag;
        if (currKeyTags.size() > 0){
            for ( int j = 0; j < currKeyTags.size(); j++){
                currTag = currKeyTags.at(j);
                if ( !(i.peekNext()->tags.contains(currTag,Qt::CaseInsensitive))) {
                    flag = true;
                }
            }
        }

        if ( flag == true ) {
            i.next();
            i.remove();
        }
        else {
            if ( currSubTags.size() > 0) {
                for ( int j = 0; j < currSubTags.size(); j++){
                    currTag = currSubTags.at(j);
                    if ( (i.peekNext()->tags.contains(currTag,Qt::CaseInsensitive))) {
                        flag = true;
                    }
                }

                i.next();
                if (!flag) {
                    i.remove();
                }
            }
            else {
                i.next();
            }
        }
    }

}

void MainWindow::showClipTree(ClipList* nClip) {

    QTreeWidget *tree = ui->tree_Clips;
    QStringList addedShowNames;
    tree->clear();
    for (int i = 0; i < nClip->list.size(); i++){

        QTreeWidgetItem *nTop;
        bool flag = false;
        if (addedShowNames.contains(nClip->list.at(i)->showName,Qt::CaseInsensitive)) {
            for (int j = 0; j < tree->topLevelItemCount(); j++){
                if (tree->topLevelItem(j)->text(0).contains(nClip->list.at(i)->showName + " : ")){
                    nTop = tree->topLevelItem(j);
                    tree->topLevelItem(j)->setText(0,nClip->list.at(i)->showName + QString(" : %1 clips").arg(tree->topLevelItem(j)->childCount() + 1));
                    flag = true;
                    break;
                }
            }
        }
        else {
            nTop = new QTreeWidgetItem(tree);
            nTop->setText(0,nClip->list.at(i)->showName + QString(" : %1 clip").arg(nTop->childCount() + 1));
            tree->addTopLevelItem(nTop);
            addedShowNames.append(nClip->list.at(i)->showName);
            flag = true;
        }

        if (flag) {
            QTreeWidgetItem *nItem = new QTreeWidgetItem(nTop);
            nItem->setText(0,nClip->list.at(i)->showName);
            nItem->setText(1,QString::number(nClip->list.at(i)->episodeNum));
            nItem->setText(2,nClip->list.at(i)->link);
            nItem->setText(3,nClip->list.at(i)->tags.join(" | "));
            nItem->setText(4,nClip->list.at(i)->comment);
            nItem->setText(5,nClip->list.at(i)->timeStart.toString("hh:mm:ss") + " - " +nClip->list.at(i)->timeEnd.toString("hh:mm:ss"));
            nItem->setText(6,nClip->list.at(i)->Errors);
            nItem->setText(7,nClip->list.at(i)->ClipsUsed);
            nItem->setText(8,nClip->list.at(i)->ID);

            nTop->addChild(nItem);
        }
        else {
            qDebug()<<"QTreeWidget addItem error: "<<nClip->list.at(i)->showName;
        }

    }
    tree->resizeColumnToContents(0);
}

void MainWindow::showListTree() {

    QTreeWidgetItem *nTopMain = new QTreeWidgetItem(ui->tree_List);
    nTopMain->setText(0,clipDB->mainList->listName);
    nTopMain->setFlags(nTopMain->flags() | Qt::ItemIsUserCheckable);
    nTopMain->setCheckState(0,Qt::Checked);
    ui->tree_List->addTopLevelItem(nTopMain);

    QMutableVectorIterator<ClipList *>i(clipDB->database);
    while(i.hasNext()){
        QTreeWidgetItem *nTop = new QTreeWidgetItem(ui->tree_List);
        nTop->setText(0,i.next()->listName);
        nTop->setFlags(nTop->flags() | Qt::ItemIsUserCheckable);
        nTop->setCheckState(0,Qt::Unchecked);
        ui->tree_List->addTopLevelItem(nTop);
    }
}

void MainWindow::addKeyTags(QString nTag) {
    if ( nextKeyTagBox < 7 ){
        //Check is valid tag

        if (clipDB->tag_list.contains(nTag) && !currKeyTags.contains(nTag,Qt::CaseInsensitive)) {
            keyTagContainer->activateTag(nTag,nextKeyTagBox++);
            currKeyTags.append(nTag);
            updateClipTreeList();
        }
        else {
            QStringList groups = ui->tree_Tags->getTagGroupNames();
            if (groups.contains(nTag,Qt::CaseInsensitive) && nTag != ui->tree_Tags->allTags->listName){
                QStringList nTags = ui->tree_Tags->getTagsFromGroup(nTag);
                keyTagContainer->activateTag(nTag,nextKeyTagBox++);
                for (int i = 0; i < nTags.count(); i++){
                    if (clipDB->tag_list.contains(nTags.at(i),Qt::CaseInsensitive) && !currKeyTags.contains(nTags.at(i),Qt::CaseInsensitive)) {
                        currKeyTags.append(nTags.at(i));
                    }
                }
                updateClipTreeList();
            }
        }

    }
}

void MainWindow::addSubTags(QString nTag) {
    if ( nextSubTagBox < 7) {
        if (clipDB->tag_list.contains(nTag) && !currSubTags.contains(nTag,Qt::CaseInsensitive)) {
            subTagContainer->activateTag(nTag,nextSubTagBox++);
            currSubTags.append(nTag);
            updateClipTreeList();
        }
        else {
            QStringList groups = ui->tree_Tags->getTagGroupNames();
            if (groups.contains(nTag,Qt::CaseInsensitive) && nTag != ui->tree_Tags->allTags->listName){
                QStringList nTags = ui->tree_Tags->getTagsFromGroup(nTag);
                subTagContainer->activateTag(nTag,nextSubTagBox++);
                for (int i = 0; i < nTags.count(); i++){
                    if (clipDB->tag_list.contains(nTags.at(i),Qt::CaseInsensitive) && !currSubTags.contains(nTags.at(i),Qt::CaseInsensitive)) {
                        currSubTags.append(nTags.at(i));
                    }
                }
                updateClipTreeList();
            }
        }
    }
}

void MainWindow::updateCompleterLists() {
    QStringListModel *model;

    model = static_cast<QStringListModel *>(ui->edit_KeyTags->completer()->model());
    model->setStringList(clipDB->tag_list);

    model = static_cast<QStringListModel *>(ui->edit_SubTags->completer()->model());
    model->setStringList(clipDB->tag_list);

    model = static_cast<QStringListModel *>(ui->edit_Name->completer()->model());
    model->setStringList(clipDB->showName_list);

}

void MainWindow::setStackPage(int index) {
    ui->mainStack->setCurrentIndex(index);
}

void MainWindow::tabSwitch(bool forward){
    QString sName = sender()->objectName();
    if (forward){
        if ( sName == "edit_Name") {
            ui->edit_EpNum->setFocus();
        } else if ( sName == "edit_EpNum") {
            ui->edit_KeyWords->setFocus();
        } else if ( sName == "edit_KeyTags") {
            ui->edit_SubTags->setFocus();
        } else if ( sName == "edit_SubTags") {
            ui->edit_Name->setFocus();
        } else if ( sName == "edit_KeyWords") {
            ui->edit_KeyTags->setFocus();
        } else {
            qDebug()<<"Invalid object name: "<<sName;
        }
    } else {
        if ( sName == "edit_Name") {
            ui->edit_SubTags->setFocus();
        } else if ( sName == "edit_EpNum") {
            ui->edit_Name->setFocus();
        } else if ( sName == "edit_KeyTags") {
            ui->edit_KeyWords->setFocus();
        } else if ( sName == "edit_SubTags") {
            ui->edit_KeyTags->setFocus();
        } else if ( sName == "edit_KeyWords") {
            ui->edit_EpNum->setFocus();
        } else {
            qDebug()<<"Invalid object name: "<<sName;
        }
    }
}

void MainWindow::on_edit_Name_textChanged(const QString &arg1)
{
    currShowString = arg1;
    updateClipTreeList();
}

void MainWindow::on_edit_EpNum_textChanged(const QString)
{
    QString text = ui->edit_EpNum->text();
    QStringList textSplit = text.split("-");
    bool success = true;
    bool flag = true;

    if (text == "") {
        currEpMin = 0;
        currEpMax = 1000;
    }
    else {
        if ( textSplit.size() == 1 ) {

            currEpMin = text.toInt(&flag);
            success = success & flag;
            currEpMax = text.toInt(&flag);
            success = success & flag;
        }
        else if ( textSplit.size() == 2){
            int min = textSplit.at(0).toInt(&flag);
            success = success & flag;
            int max = textSplit.at(1).toInt(&flag);
            success = success & flag;

            if (success) {
                currEpMin = min;
                currEpMax = max;
            }
        } else {
            success = false;
        }
    }

    if (!success) {
        qDebug()<<"Invalid input";
        currEpMin = 0;
        currEpMax = 1000;
    } else {
        updateClipTreeList();
    }
}

void MainWindow::onKeyTag_entered() {

    QString simpleTag = ui->edit_KeyTags->text();
    ui->edit_KeyTags->clear();
    addKeyTags(simpleTag);
}

void MainWindow::onSubTag_entered() {

    QString simpleTag = ui->edit_SubTags->text();
    ui->edit_SubTags->clear();
    addSubTags(simpleTag);
}

void MainWindow::onTagDelete_pressed(QString label, int index) {

    if (sender()->objectName().contains("subTag")) {
        nextSubTagBox--;
        subTagContainer->deactivateTag(index);

        QStringList groups = ui->tree_Tags->getTagGroupNames();
        if (groups.contains(label,Qt::CaseInsensitive)){
            QStringList nTags = ui->tree_Tags->getTagsFromGroup(label);
            for (int i = 0; i < nTags.count(); i++){
                currSubTags.removeOne(nTags.at(i));
            }
        }
        else {
            currSubTags.removeOne(label);
        }

        //removeTagFromString(simpleTag);
    }
    else if (sender()->objectName().contains("keyTag")) {
        nextKeyTagBox--;
        keyTagContainer->deactivateTag(index);

        QStringList groups = ui->tree_Tags->getTagGroupNames();
        if (groups.contains(label,Qt::CaseInsensitive)){
            QStringList nTags = ui->tree_Tags->getTagsFromGroup(label);
            for (int i = 0; i < nTags.count(); i++){
                currKeyTags.removeOne(nTags.at(i));
            }
        }
        else {
            currKeyTags.removeOne(label);
        }
        //removeTagFromString(simpleTag);
    }
    else {
        qDebug()<<"Invalid Delete button pressed?? "<<label<<" "<<index;
    }

    updateClipTreeList();
}

void MainWindow::on_edit_KeyWords_textChanged(const QString)
{
    currKeyWordList = ui->edit_KeyWords->text().split(",");
    updateClipTreeList();

}

void MainWindow::onTreeWidgetItem_doubleclicked(QTreeWidgetItem *item, int ){
    if(!item->text(2).isEmpty()){
        QString sUrl= item->text(2);
        QUrl url(sUrl);
        qDebug()<<url.isValid();
        bool success = QDesktopServices::openUrl(url);//QUrl(item->text(2)));
        qDebug()<<success;
    }
}

void MainWindow::onTreeContextMenu(const QPoint &point) {
    QModelIndex index = ui->tree_Tags->indexAt(point);

    if (index.isValid()) {
        QPoint nPoint(point.x()+15, point.y()+20);
        QTreeWidgetItem *nItem = ui->tree_Tags->itemAt(point);
        QString itemData;
        QString parentData;
        if ( !nItem->parent() ){
            tagItemContextMenu->actions().at(REMOVE_INDEX)->setText("Remove Group");
            tagItemContextMenu->actions().at(ADD_KEY_INDEX)->setText("Add Group - Key Tag");
            tagItemContextMenu->actions().at(ADD_SUB_INDEX)->setText("Add Group - Sub Tag");
        }
        else {
            parentData = nItem->parent()->text(0);
            tagItemContextMenu->actions().at(REMOVE_INDEX)->setText("Remove Tag");
            tagItemContextMenu->actions().at(ADD_KEY_INDEX)->setText("Add Item - Key Tag");
            tagItemContextMenu->actions().at(ADD_SUB_INDEX)->setText("Add Item - Sub Tag");
        }
        itemData = nItem->text(0);

        tagItemContextMenu->actions().at(REMOVE_INDEX)->setData(parentData + " -- " + itemData);
        tagItemContextMenu->actions().at(ADD_KEY_INDEX)->setData(itemData);
        tagItemContextMenu->actions().at(ADD_SUB_INDEX)->setData(itemData);
        tagItemContextMenu->actions().at(DUP_GROUP_INDEX)->setData(itemData);
        tagItemContextMenu->exec(ui->tree_Tags->mapToGlobal(nPoint));
    }
}

void MainWindow::onTreeContextMenuSelect(QAction *action) {
    if (action->text().contains("- Key Tag",Qt::CaseInsensitive)){
        QString tag = action->data().toString();
        if (tag.contains(" :: ")) {
            tag.chop(tag.length() - tag.indexOf(" ::"));
        }
        addKeyTags(tag);
    }
    else if (action->text().contains("- Sub Tag",Qt::CaseInsensitive)){
        QString tag = action->data().toString();
        if (tag.contains(" :: ")) {
            tag.chop(tag.length() - tag.indexOf(" ::"));
        }
        addSubTags(tag);
    }
    else if (action->text().contains("Remove",Qt::CaseInsensitive)){
        QStringList dataSplit = action->data().toString().split(" -- ");
        if (action->text().contains("Group",Qt::CaseInsensitive)) {
            ui->tree_Tags->removeGroup(dataSplit.at(1));
        }
        else {
            ui->tree_Tags->removeTagFromGroup(dataSplit.at(0),dataSplit.at(1));
        }
    }
    else if (action->text().contains("New",Qt::CaseInsensitive)){
        QString title = "New Group Name";
        QString request = "Group Name: ";
        bool ok;
        while (true) {
            QString groupName = QInputDialog::getText(this,tr(title.toLatin1()),tr(request.toLatin1()),QLineEdit::Normal,"New Group", &ok);
            if (!ok){
                break;
            }
            else if(!groupName.contains(" :: ") && !groupName.contains(" -- ")){
                // Create new group
                ui->tree_Tags->addGroup(groupName);
                break;
            }
            request = "Group Name: // Cannot contain \" :: \" or \" -- \"";
        }
    }
    else if (action->text().contains("Duplicate",Qt::CaseInsensitive)){
        QString group = action->data().toString();
        if (group.contains(" :: ")) {
            group.chop(group.length() - group.indexOf(" ::"));
        }

        ui->tree_Tags->duplicateGroup(group);
    }
}

void MainWindow::onListTreeItemChanged(QTreeWidgetItem * /*item*/, int /*column*/) {
    QVector<ClipList *> nActiveList;


    for (int i = 0; i < ui->tree_List->topLevelItemCount(); i++) {
        QTreeWidgetItem *nItem = ui->tree_List->topLevelItem(i);
        if (nItem->checkState(0) == Qt::Checked) {
            if (clipDB->mainList->listName == nItem->text(0)) {
                nActiveList.append(clipDB->mainList);
            }
            else {
                for (int j = 0; j < clipDB->database.count(); j++) {
                    if (clipDB->database.at(j)->listName == nItem->text(0)) {
                        nActiveList.append(clipDB->database.at(j));
                        break;
                    }

                }
            }
        }
    }
    clipDB->updateActiveList(nActiveList);
    clipDB->activeList->removeDuplicates();
    updateClipTreeList();
}

void MainWindow::onClipTreeContextMenu(const QPoint &point) {

    QModelIndex index = ui->tree_Clips->indexAt(point);

    if (index.isValid()){
        QTreeWidgetItem *nItem = ui->tree_Clips->itemAt(point);
        QStringList idList;
        if ( !nItem->parent()){
            for (int i = 0; i < nItem->childCount(); i++){
                idList.append(nItem->child(i)->text(8));
            }
        }
        else {
            idList.append(nItem->text(8));
        }

        clipAddMenu->setTitle("Add clips to ...");
        clipAddMenu->clear();
        QVariantList dataList;
        for (int j = 1; j < ui->tree_List->topLevelItemCount(); j++){
            QAction *action1 = new QAction(this);
            clipAddMenu->addAction(action1);
            action1->setText(ui->tree_List->topLevelItem(j)->text(0));

            dataList.clear();
            dataList.append("Add");
            dataList.append(ui->tree_List->topLevelItem(j)->text(0));
            dataList.append(idList);
            action1->setData(dataList);
        }

        //Remove Option
        clipRemoveMenu->setTitle("Remove clips from ... ");
        clipRemoveMenu->clear();
        for (int j = 1; j < ui->tree_List->topLevelItemCount(); j++){
            QAction *action1 = new QAction(this);
            clipRemoveMenu->addAction(action1);
            action1->setText(ui->tree_List->topLevelItem(j)->text(0));

            dataList.clear();
            dataList.append("Remove");
            dataList.append(ui->tree_List->topLevelItem(j)->text(0));
            dataList.append(idList);
            action1->setData(dataList);
        }

        clipItemContextMenu->exec(ui->tree_Clips->mapToGlobal(point));
    }
}

void MainWindow::onClipTreeContextMenuSelect(QAction *action) {

    QVariantList varList = action->data().toList();

    QString command = varList.at(0).toString();

    if (command == "Add") {
        QString targetList = varList.at(1).toString();
        QStringList targetClips = varList.at(2).toStringList();

        for ( int i = 0; i < targetClips.count(); i++){
            ClipList* list = clipDB->getListByName(targetList);
            if (list != NULL){
                Clip* clip = list->getClipFromID(targetClips.at(i));
                if (clip == NULL){
                    Clip* nClip = clipDB->mainList->getClipFromID(targetClips.at(i));
                    list->list.append(nClip);
                }
            }
        }
        updateClipTreeList();
    }
    else if (command == "Remove") {
        QString targetList = varList.at(1).toString();
        QStringList targetClips = varList.at(2).toStringList();

        for ( int i = 0; i < targetClips.count(); i++){
            ClipList* list = clipDB->getListByName(targetList);
            if (list != NULL){
                Clip* clip = list->getClipFromID(targetClips.at(i));
                if (clip != NULL){
                    list->list.removeAll(clip);
                }
            }
        }
        onListTreeItemChanged(NULL,0);
    }
}
