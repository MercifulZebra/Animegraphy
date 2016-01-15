#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QTime>
#include <QTreeWidgetItem>
#include <QMenu>
#include "apptypes.h"
#include "clip.h"
#include "tagcontainer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QString config,QWidget *parent = 0);
    ~MainWindow();

    void init();
    void init_config();
    void init_objects();
    void init_lists();
    void init_eventFilters();
    void init_completers();
    void init_connections();
    void init_tagBoxes();
    void init_clipTree();
    void init_tagTree();
    void init_listTree();
    void init_contextMenus();

    void save_files();
    void backup_files();
    void export_list();
    void save_mainList(QString path, QString identifiers);
    void save_clipLists(QString path, QString identifiers);
    void save_listIndex(QString path, QString identifiers);
    void save_tagIndex(QString path, QString identifiers);

    void setWorkingDirectory(QString path);

    void clearSearchBoxes();
    bool eventFilter(QObject *, QEvent *);

    void setActiveTreePool(ClipList* nList);

    void updateClipTreeList();
    void updateTreeByName();
    void updateTreeByNum();
    void updateTreeByKeyword();
    void updateTreeByTags();
    void showClipTree(ClipList* nClips);

    void showListTree();
    void addList(QString nList);
    void duplicateList(QString oList);
    void removeList(QString rList);
    void clearList(QString cList);
    QStringList getListNames();
    QVector<Clip*> getClipsFromList(QString listName);

    void addKeyTags(QString nTag);
    void addSubTags(QString nTag);

    void updateCompleterLists();

    void setStackPage(int index);
    //Parse.cpp

public:
    QString config_filename;
    QString index_filename;
    QString list_filename;
    QString showHistory_filename;
    QString tagHistory_filename;
    QString tagGroup_filename;

    bool save_flag;

    ClipDatabase    *clipDB;

    //ClipTree
    ClipList       *activeTreePool;
    ClipList       *currTreeList;
    QString         currShowString;
    int             currEpMin;
    int             currEpMax;
    QStringList     currKeyWordList;
    QStringList     currKeyTags;
    QStringList     currSubTags;
    char            updated_flags;

    // Tag Widgets
    int             nextKeyTagBox;
    int             nextSubTagBox;
    TagContainer   *keyTagContainer;
    TagContainer   *subTagContainer;

    //Context Menus
    QMenu          *tagItemContextMenu;
    QMenu          *clipItemContextMenu;
    QMenu          *clipAddMenu;
    QMenu          *clipRemoveMenu;
    QMenu          *listItemContextMenu;

private slots:
    void tabSwitch(bool);

    void on_edit_Name_textChanged(const QString &arg1);
    void onKeyTag_entered();
    void onSubTag_entered();
    void onTagDelete_pressed(QString, int);
    void on_edit_EpNum_textChanged(const QString);
    void on_edit_KeyWords_textChanged(const QString);

    void onTreeWidgetItem_doubleclicked(QTreeWidgetItem *item, int );
    void onTreeContextMenu(const QPoint &);
    void onTreeContextMenuSelect(QAction*);
    void onListTreeItemChanged(QTreeWidgetItem *item, int column);

    void onClipTreeContextMenu(const QPoint &);
    void onClipTreeContextMenuSelect(QAction*);

    void onListTreeContextMenu(const QPoint &);
    void onListTreeContextMenuSelect(QAction*);

    void onSaveRequested();
    void onBackupRequested();
    void onExportRequested();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
