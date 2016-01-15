/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>
#include "tablineedit.h"
#include "tagcontainer.h"
#include "tagtreewidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave_Data;
    QAction *actionExport_List;
    QAction *actionCreate_Backup;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QStackedWidget *mainStack;
    QWidget *page_Search;
    QGridLayout *gridLayout_2;
    QTreeWidget *tree_List;
    QFrame *frame_KeyTags;
    QGridLayout *gridLayout_3;
    QLabel *label_kTagGroup;
    QWidget *keyTagBox2;
    QFormLayout *formLayout_2;
    QLabel *label_keyTag2;
    TagButtonBox *button_keyTag2;
    QWidget *keyTagBox1;
    QFormLayout *formLayout_3;
    QLabel *label_keyTag1;
    TagButtonBox *button_keyTag1;
    QWidget *keyTagBox3;
    QFormLayout *formLayout;
    QLabel *label_keyTag3;
    TagButtonBox *button_keyTag3;
    QWidget *keyTagBox4;
    QFormLayout *formLayout_4;
    QLabel *label_keyTag4;
    TagButtonBox *button_keyTag4;
    QWidget *keyTagBox5;
    QFormLayout *formLayout_5;
    QLabel *label_keyTag5;
    TagButtonBox *button_keyTag5;
    QWidget *keyTagBox6;
    QFormLayout *formLayout_6;
    QLabel *label_keyTag6;
    TagButtonBox *button_keyTag6;
    QFrame *frame_SubTags;
    QGridLayout *gridLayout_4;
    QWidget *subTagBox1;
    QFormLayout *formLayout_7;
    QLabel *label_subTag1;
    TagButtonBox *button_subTag1;
    QWidget *subTagBox4;
    QFormLayout *formLayout_8;
    QLabel *label_subTag4;
    TagButtonBox *button_subTag4;
    QWidget *subTagBox6;
    QFormLayout *formLayout_11;
    QLabel *label_subTag6;
    TagButtonBox *button_subTag6;
    QWidget *subTagBox3;
    QFormLayout *formLayout_10;
    QLabel *label_subTag3;
    TagButtonBox *button_subTag3;
    QLabel *label_sTagGroup;
    QWidget *subTagBox2;
    QFormLayout *formLayout_9;
    QLabel *label_subTag2;
    TagButtonBox *button_subTag2;
    QWidget *subTagBox5;
    QFormLayout *formLayout_12;
    QLabel *label_subTag5;
    TagButtonBox *button_subTag5;
    TagTreeWidget *tree_Tags;
    QTreeWidget *tree_Clips;
    TabLineEdit *edit_KeyWords;
    QLabel *label_KeyWords;
    TabLineEdit *edit_SubTags;
    TabLineEdit *edit_KeyTags;
    QLabel *label_EpNum;
    TabLineEdit *edit_EpNum;
    QSpacerItem *horizontalSpacer;
    QLabel *label_SubTags;
    QPushButton *button_AddKeyTag;
    QLabel *label_KeyTags;
    QLabel *label_Name;
    TabLineEdit *edit_Name;
    QPushButton *button_AddSubTag;
    QPushButton *button_export;
    QPushButton *button_save;
    QLabel *title_Search;
    QWidget *page_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1234, 690);
        actionSave_Data = new QAction(MainWindow);
        actionSave_Data->setObjectName(QStringLiteral("actionSave_Data"));
        actionExport_List = new QAction(MainWindow);
        actionExport_List->setObjectName(QStringLiteral("actionExport_List"));
        actionCreate_Backup = new QAction(MainWindow);
        actionCreate_Backup->setObjectName(QStringLiteral("actionCreate_Backup"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        mainStack = new QStackedWidget(centralWidget);
        mainStack->setObjectName(QStringLiteral("mainStack"));
        page_Search = new QWidget();
        page_Search->setObjectName(QStringLiteral("page_Search"));
        gridLayout_2 = new QGridLayout(page_Search);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tree_List = new QTreeWidget(page_Search);
        tree_List->setObjectName(QStringLiteral("tree_List"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tree_List->sizePolicy().hasHeightForWidth());
        tree_List->setSizePolicy(sizePolicy);
        tree_List->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(tree_List, 7, 8, 1, 1);

        frame_KeyTags = new QFrame(page_Search);
        frame_KeyTags->setObjectName(QStringLiteral("frame_KeyTags"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_KeyTags->sizePolicy().hasHeightForWidth());
        frame_KeyTags->setSizePolicy(sizePolicy1);
        frame_KeyTags->setMinimumSize(QSize(380, 0));
        frame_KeyTags->setMaximumSize(QSize(16777215, 16777215));
        frame_KeyTags->setAcceptDrops(true);
        frame_KeyTags->setFrameShape(QFrame::Panel);
        frame_KeyTags->setFrameShadow(QFrame::Sunken);
        frame_KeyTags->setLineWidth(2);
        gridLayout_3 = new QGridLayout(frame_KeyTags);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_kTagGroup = new QLabel(frame_KeyTags);
        label_kTagGroup->setObjectName(QStringLiteral("label_kTagGroup"));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        label_kTagGroup->setFont(font);

        gridLayout_3->addWidget(label_kTagGroup, 0, 0, 1, 1);

        keyTagBox2 = new QWidget(frame_KeyTags);
        keyTagBox2->setObjectName(QStringLiteral("keyTagBox2"));
        formLayout_2 = new QFormLayout(keyTagBox2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_keyTag2 = new QLabel(keyTagBox2);
        label_keyTag2->setObjectName(QStringLiteral("label_keyTag2"));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        label_keyTag2->setFont(font1);
        label_keyTag2->setFocusPolicy(Qt::NoFocus);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_keyTag2);

        button_keyTag2 = new TagButtonBox(keyTagBox2);
        button_keyTag2->setObjectName(QStringLiteral("button_keyTag2"));
        button_keyTag2->setFont(font1);
        button_keyTag2->setFocusPolicy(Qt::ClickFocus);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, button_keyTag2);


        gridLayout_3->addWidget(keyTagBox2, 2, 0, 1, 1);

        keyTagBox1 = new QWidget(frame_KeyTags);
        keyTagBox1->setObjectName(QStringLiteral("keyTagBox1"));
        formLayout_3 = new QFormLayout(keyTagBox1);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label_keyTag1 = new QLabel(keyTagBox1);
        label_keyTag1->setObjectName(QStringLiteral("label_keyTag1"));
        label_keyTag1->setFont(font1);
        label_keyTag1->setFocusPolicy(Qt::NoFocus);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_keyTag1);

        button_keyTag1 = new TagButtonBox(keyTagBox1);
        button_keyTag1->setObjectName(QStringLiteral("button_keyTag1"));
        button_keyTag1->setFont(font1);
        button_keyTag1->setFocusPolicy(Qt::ClickFocus);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, button_keyTag1);


        gridLayout_3->addWidget(keyTagBox1, 1, 0, 1, 1);

        keyTagBox3 = new QWidget(frame_KeyTags);
        keyTagBox3->setObjectName(QStringLiteral("keyTagBox3"));
        keyTagBox3->setFocusPolicy(Qt::NoFocus);
        formLayout = new QFormLayout(keyTagBox3);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_keyTag3 = new QLabel(keyTagBox3);
        label_keyTag3->setObjectName(QStringLiteral("label_keyTag3"));
        label_keyTag3->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_keyTag3);

        button_keyTag3 = new TagButtonBox(keyTagBox3);
        button_keyTag3->setObjectName(QStringLiteral("button_keyTag3"));
        button_keyTag3->setFont(font1);
        button_keyTag3->setFocusPolicy(Qt::ClickFocus);

        formLayout->setWidget(0, QFormLayout::FieldRole, button_keyTag3);


        gridLayout_3->addWidget(keyTagBox3, 3, 0, 1, 1);

        keyTagBox4 = new QWidget(frame_KeyTags);
        keyTagBox4->setObjectName(QStringLiteral("keyTagBox4"));
        formLayout_4 = new QFormLayout(keyTagBox4);
        formLayout_4->setSpacing(6);
        formLayout_4->setContentsMargins(11, 11, 11, 11);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        label_keyTag4 = new QLabel(keyTagBox4);
        label_keyTag4->setObjectName(QStringLiteral("label_keyTag4"));
        label_keyTag4->setFont(font1);
        label_keyTag4->setFocusPolicy(Qt::NoFocus);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_keyTag4);

        button_keyTag4 = new TagButtonBox(keyTagBox4);
        button_keyTag4->setObjectName(QStringLiteral("button_keyTag4"));
        button_keyTag4->setFont(font1);
        button_keyTag4->setFocusPolicy(Qt::ClickFocus);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, button_keyTag4);


        gridLayout_3->addWidget(keyTagBox4, 1, 1, 1, 1);

        keyTagBox5 = new QWidget(frame_KeyTags);
        keyTagBox5->setObjectName(QStringLiteral("keyTagBox5"));
        formLayout_5 = new QFormLayout(keyTagBox5);
        formLayout_5->setSpacing(6);
        formLayout_5->setContentsMargins(11, 11, 11, 11);
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        label_keyTag5 = new QLabel(keyTagBox5);
        label_keyTag5->setObjectName(QStringLiteral("label_keyTag5"));
        label_keyTag5->setFont(font1);
        label_keyTag5->setFocusPolicy(Qt::NoFocus);

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_keyTag5);

        button_keyTag5 = new TagButtonBox(keyTagBox5);
        button_keyTag5->setObjectName(QStringLiteral("button_keyTag5"));
        button_keyTag5->setFont(font1);
        button_keyTag5->setFocusPolicy(Qt::ClickFocus);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, button_keyTag5);


        gridLayout_3->addWidget(keyTagBox5, 2, 1, 1, 1);

        keyTagBox6 = new QWidget(frame_KeyTags);
        keyTagBox6->setObjectName(QStringLiteral("keyTagBox6"));
        formLayout_6 = new QFormLayout(keyTagBox6);
        formLayout_6->setSpacing(6);
        formLayout_6->setContentsMargins(11, 11, 11, 11);
        formLayout_6->setObjectName(QStringLiteral("formLayout_6"));
        label_keyTag6 = new QLabel(keyTagBox6);
        label_keyTag6->setObjectName(QStringLiteral("label_keyTag6"));
        label_keyTag6->setFont(font1);
        label_keyTag6->setFocusPolicy(Qt::NoFocus);

        formLayout_6->setWidget(0, QFormLayout::LabelRole, label_keyTag6);

        button_keyTag6 = new TagButtonBox(keyTagBox6);
        button_keyTag6->setObjectName(QStringLiteral("button_keyTag6"));
        button_keyTag6->setFont(font1);
        button_keyTag6->setFocusPolicy(Qt::ClickFocus);

        formLayout_6->setWidget(0, QFormLayout::FieldRole, button_keyTag6);


        gridLayout_3->addWidget(keyTagBox6, 3, 1, 1, 1);


        gridLayout_2->addWidget(frame_KeyTags, 6, 0, 1, 4);

        frame_SubTags = new QFrame(page_Search);
        frame_SubTags->setObjectName(QStringLiteral("frame_SubTags"));
        sizePolicy1.setHeightForWidth(frame_SubTags->sizePolicy().hasHeightForWidth());
        frame_SubTags->setSizePolicy(sizePolicy1);
        frame_SubTags->setMinimumSize(QSize(380, 0));
        frame_SubTags->setMaximumSize(QSize(16777215, 16777215));
        frame_SubTags->setAcceptDrops(true);
        frame_SubTags->setFrameShape(QFrame::Panel);
        frame_SubTags->setFrameShadow(QFrame::Sunken);
        frame_SubTags->setLineWidth(2);
        gridLayout_4 = new QGridLayout(frame_SubTags);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        subTagBox1 = new QWidget(frame_SubTags);
        subTagBox1->setObjectName(QStringLiteral("subTagBox1"));
        formLayout_7 = new QFormLayout(subTagBox1);
        formLayout_7->setSpacing(6);
        formLayout_7->setContentsMargins(11, 11, 11, 11);
        formLayout_7->setObjectName(QStringLiteral("formLayout_7"));
        label_subTag1 = new QLabel(subTagBox1);
        label_subTag1->setObjectName(QStringLiteral("label_subTag1"));
        label_subTag1->setFont(font1);
        label_subTag1->setFocusPolicy(Qt::NoFocus);

        formLayout_7->setWidget(0, QFormLayout::LabelRole, label_subTag1);

        button_subTag1 = new TagButtonBox(subTagBox1);
        button_subTag1->setObjectName(QStringLiteral("button_subTag1"));
        button_subTag1->setFont(font1);
        button_subTag1->setFocusPolicy(Qt::ClickFocus);

        formLayout_7->setWidget(0, QFormLayout::FieldRole, button_subTag1);


        gridLayout_4->addWidget(subTagBox1, 1, 0, 1, 1);

        subTagBox4 = new QWidget(frame_SubTags);
        subTagBox4->setObjectName(QStringLiteral("subTagBox4"));
        formLayout_8 = new QFormLayout(subTagBox4);
        formLayout_8->setSpacing(6);
        formLayout_8->setContentsMargins(11, 11, 11, 11);
        formLayout_8->setObjectName(QStringLiteral("formLayout_8"));
        label_subTag4 = new QLabel(subTagBox4);
        label_subTag4->setObjectName(QStringLiteral("label_subTag4"));
        label_subTag4->setFont(font1);
        label_subTag4->setFocusPolicy(Qt::NoFocus);

        formLayout_8->setWidget(0, QFormLayout::LabelRole, label_subTag4);

        button_subTag4 = new TagButtonBox(subTagBox4);
        button_subTag4->setObjectName(QStringLiteral("button_subTag4"));
        button_subTag4->setFont(font1);
        button_subTag4->setFocusPolicy(Qt::ClickFocus);

        formLayout_8->setWidget(0, QFormLayout::FieldRole, button_subTag4);


        gridLayout_4->addWidget(subTagBox4, 1, 1, 1, 1);

        subTagBox6 = new QWidget(frame_SubTags);
        subTagBox6->setObjectName(QStringLiteral("subTagBox6"));
        formLayout_11 = new QFormLayout(subTagBox6);
        formLayout_11->setSpacing(6);
        formLayout_11->setContentsMargins(11, 11, 11, 11);
        formLayout_11->setObjectName(QStringLiteral("formLayout_11"));
        label_subTag6 = new QLabel(subTagBox6);
        label_subTag6->setObjectName(QStringLiteral("label_subTag6"));
        label_subTag6->setFont(font1);
        label_subTag6->setFocusPolicy(Qt::NoFocus);

        formLayout_11->setWidget(0, QFormLayout::LabelRole, label_subTag6);

        button_subTag6 = new TagButtonBox(subTagBox6);
        button_subTag6->setObjectName(QStringLiteral("button_subTag6"));
        button_subTag6->setFont(font1);
        button_subTag6->setFocusPolicy(Qt::ClickFocus);

        formLayout_11->setWidget(0, QFormLayout::FieldRole, button_subTag6);


        gridLayout_4->addWidget(subTagBox6, 3, 1, 1, 1);

        subTagBox3 = new QWidget(frame_SubTags);
        subTagBox3->setObjectName(QStringLiteral("subTagBox3"));
        formLayout_10 = new QFormLayout(subTagBox3);
        formLayout_10->setSpacing(6);
        formLayout_10->setContentsMargins(11, 11, 11, 11);
        formLayout_10->setObjectName(QStringLiteral("formLayout_10"));
        label_subTag3 = new QLabel(subTagBox3);
        label_subTag3->setObjectName(QStringLiteral("label_subTag3"));
        label_subTag3->setFont(font1);
        label_subTag3->setFocusPolicy(Qt::NoFocus);

        formLayout_10->setWidget(0, QFormLayout::LabelRole, label_subTag3);

        button_subTag3 = new TagButtonBox(subTagBox3);
        button_subTag3->setObjectName(QStringLiteral("button_subTag3"));
        button_subTag3->setFont(font1);
        button_subTag3->setFocusPolicy(Qt::ClickFocus);

        formLayout_10->setWidget(0, QFormLayout::FieldRole, button_subTag3);


        gridLayout_4->addWidget(subTagBox3, 3, 0, 1, 1);

        label_sTagGroup = new QLabel(frame_SubTags);
        label_sTagGroup->setObjectName(QStringLiteral("label_sTagGroup"));
        label_sTagGroup->setFont(font);

        gridLayout_4->addWidget(label_sTagGroup, 0, 0, 1, 1);

        subTagBox2 = new QWidget(frame_SubTags);
        subTagBox2->setObjectName(QStringLiteral("subTagBox2"));
        formLayout_9 = new QFormLayout(subTagBox2);
        formLayout_9->setSpacing(6);
        formLayout_9->setContentsMargins(11, 11, 11, 11);
        formLayout_9->setObjectName(QStringLiteral("formLayout_9"));
        label_subTag2 = new QLabel(subTagBox2);
        label_subTag2->setObjectName(QStringLiteral("label_subTag2"));
        label_subTag2->setFont(font1);
        label_subTag2->setFocusPolicy(Qt::NoFocus);

        formLayout_9->setWidget(0, QFormLayout::LabelRole, label_subTag2);

        button_subTag2 = new TagButtonBox(subTagBox2);
        button_subTag2->setObjectName(QStringLiteral("button_subTag2"));
        button_subTag2->setFont(font1);
        button_subTag2->setFocusPolicy(Qt::ClickFocus);

        formLayout_9->setWidget(0, QFormLayout::FieldRole, button_subTag2);


        gridLayout_4->addWidget(subTagBox2, 2, 0, 1, 1);

        subTagBox5 = new QWidget(frame_SubTags);
        subTagBox5->setObjectName(QStringLiteral("subTagBox5"));
        formLayout_12 = new QFormLayout(subTagBox5);
        formLayout_12->setSpacing(6);
        formLayout_12->setContentsMargins(11, 11, 11, 11);
        formLayout_12->setObjectName(QStringLiteral("formLayout_12"));
        label_subTag5 = new QLabel(subTagBox5);
        label_subTag5->setObjectName(QStringLiteral("label_subTag5"));
        label_subTag5->setFont(font1);
        label_subTag5->setFocusPolicy(Qt::NoFocus);

        formLayout_12->setWidget(0, QFormLayout::LabelRole, label_subTag5);

        button_subTag5 = new TagButtonBox(subTagBox5);
        button_subTag5->setObjectName(QStringLiteral("button_subTag5"));
        button_subTag5->setFont(font1);
        button_subTag5->setFocusPolicy(Qt::ClickFocus);

        formLayout_12->setWidget(0, QFormLayout::FieldRole, button_subTag5);


        gridLayout_4->addWidget(subTagBox5, 2, 1, 1, 1);


        gridLayout_2->addWidget(frame_SubTags, 6, 5, 1, 3);

        tree_Tags = new TagTreeWidget(page_Search);
        tree_Tags->setObjectName(QStringLiteral("tree_Tags"));
        sizePolicy.setHeightForWidth(tree_Tags->sizePolicy().hasHeightForWidth());
        tree_Tags->setSizePolicy(sizePolicy);
        tree_Tags->setFocusPolicy(Qt::NoFocus);
        tree_Tags->setAcceptDrops(true);
        tree_Tags->setDragEnabled(true);
        tree_Tags->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tree_Tags->setAutoExpandDelay(300);

        gridLayout_2->addWidget(tree_Tags, 3, 8, 4, 1);

        tree_Clips = new QTreeWidget(page_Search);
        tree_Clips->setObjectName(QStringLiteral("tree_Clips"));
        sizePolicy.setHeightForWidth(tree_Clips->sizePolicy().hasHeightForWidth());
        tree_Clips->setSizePolicy(sizePolicy);
        tree_Clips->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(tree_Clips, 7, 0, 1, 8);

        edit_KeyWords = new TabLineEdit(page_Search);
        edit_KeyWords->setObjectName(QStringLiteral("edit_KeyWords"));
        edit_KeyWords->setFocusPolicy(Qt::ClickFocus);

        gridLayout_2->addWidget(edit_KeyWords, 4, 1, 1, 7);

        label_KeyWords = new QLabel(page_Search);
        label_KeyWords->setObjectName(QStringLiteral("label_KeyWords"));
        QFont font2;
        font2.setPointSize(12);
        label_KeyWords->setFont(font2);

        gridLayout_2->addWidget(label_KeyWords, 4, 0, 1, 1);

        edit_SubTags = new TabLineEdit(page_Search);
        edit_SubTags->setObjectName(QStringLiteral("edit_SubTags"));
        edit_SubTags->setFocusPolicy(Qt::ClickFocus);

        gridLayout_2->addWidget(edit_SubTags, 5, 6, 1, 1);

        edit_KeyTags = new TabLineEdit(page_Search);
        edit_KeyTags->setObjectName(QStringLiteral("edit_KeyTags"));
        edit_KeyTags->setMinimumSize(QSize(0, 0));
        edit_KeyTags->setFocusPolicy(Qt::ClickFocus);

        gridLayout_2->addWidget(edit_KeyTags, 5, 1, 1, 2);

        label_EpNum = new QLabel(page_Search);
        label_EpNum->setObjectName(QStringLiteral("label_EpNum"));
        label_EpNum->setFont(font2);

        gridLayout_2->addWidget(label_EpNum, 3, 5, 1, 1);

        edit_EpNum = new TabLineEdit(page_Search);
        edit_EpNum->setObjectName(QStringLiteral("edit_EpNum"));
        edit_EpNum->setFocusPolicy(Qt::ClickFocus);

        gridLayout_2->addWidget(edit_EpNum, 3, 6, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 5, 4, 1, 1);

        label_SubTags = new QLabel(page_Search);
        label_SubTags->setObjectName(QStringLiteral("label_SubTags"));
        label_SubTags->setFont(font2);

        gridLayout_2->addWidget(label_SubTags, 5, 5, 1, 1);

        button_AddKeyTag = new QPushButton(page_Search);
        button_AddKeyTag->setObjectName(QStringLiteral("button_AddKeyTag"));
        QFont font3;
        font3.setPointSize(11);
        button_AddKeyTag->setFont(font3);
        button_AddKeyTag->setFocusPolicy(Qt::ClickFocus);

        gridLayout_2->addWidget(button_AddKeyTag, 5, 3, 1, 1);

        label_KeyTags = new QLabel(page_Search);
        label_KeyTags->setObjectName(QStringLiteral("label_KeyTags"));
        label_KeyTags->setFont(font2);

        gridLayout_2->addWidget(label_KeyTags, 5, 0, 1, 1);

        label_Name = new QLabel(page_Search);
        label_Name->setObjectName(QStringLiteral("label_Name"));
        label_Name->setFont(font2);

        gridLayout_2->addWidget(label_Name, 3, 0, 1, 1);

        edit_Name = new TabLineEdit(page_Search);
        edit_Name->setObjectName(QStringLiteral("edit_Name"));
        edit_Name->setFocusPolicy(Qt::ClickFocus);

        gridLayout_2->addWidget(edit_Name, 3, 1, 1, 4);

        button_AddSubTag = new QPushButton(page_Search);
        button_AddSubTag->setObjectName(QStringLiteral("button_AddSubTag"));
        button_AddSubTag->setFont(font3);
        button_AddSubTag->setFocusPolicy(Qt::ClickFocus);

        gridLayout_2->addWidget(button_AddSubTag, 5, 7, 1, 1);

        button_export = new QPushButton(page_Search);
        button_export->setObjectName(QStringLiteral("button_export"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(button_export->sizePolicy().hasHeightForWidth());
        button_export->setSizePolicy(sizePolicy2);
        QFont font4;
        font4.setPointSize(14);
        button_export->setFont(font4);

        gridLayout_2->addWidget(button_export, 0, 8, 1, 1);

        button_save = new QPushButton(page_Search);
        button_save->setObjectName(QStringLiteral("button_save"));
        sizePolicy2.setHeightForWidth(button_save->sizePolicy().hasHeightForWidth());
        button_save->setSizePolicy(sizePolicy2);
        button_save->setFont(font4);

        gridLayout_2->addWidget(button_save, 1, 8, 1, 1);

        title_Search = new QLabel(page_Search);
        title_Search->setObjectName(QStringLiteral("title_Search"));
        QFont font5;
        font5.setFamily(QStringLiteral("Impact"));
        font5.setPointSize(40);
        font5.setUnderline(true);
        title_Search->setFont(font5);

        gridLayout_2->addWidget(title_Search, 0, 0, 2, 7);

        mainStack->addWidget(page_Search);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        mainStack->addWidget(page_2);

        gridLayout->addWidget(mainStack, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1234, 21));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        mainStack->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionSave_Data->setText(QApplication::translate("MainWindow", "Save Data", 0));
        actionExport_List->setText(QApplication::translate("MainWindow", "Export List", 0));
        actionCreate_Backup->setText(QApplication::translate("MainWindow", "Create Backup", 0));
        QTreeWidgetItem *___qtreewidgetitem = tree_List->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "List", 0));
        label_kTagGroup->setText(QApplication::translate("MainWindow", "Key Tags:", 0));
        label_keyTag2->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        button_keyTag2->setText(QApplication::translate("MainWindow", "X", 0));
        label_keyTag1->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        button_keyTag1->setText(QApplication::translate("MainWindow", "X", 0));
        label_keyTag3->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        button_keyTag3->setText(QApplication::translate("MainWindow", "X", 0));
        label_keyTag4->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        button_keyTag4->setText(QApplication::translate("MainWindow", "X", 0));
        label_keyTag5->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        button_keyTag5->setText(QApplication::translate("MainWindow", "X", 0));
        label_keyTag6->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        button_keyTag6->setText(QApplication::translate("MainWindow", "X", 0));
        label_subTag1->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        button_subTag1->setText(QApplication::translate("MainWindow", "X", 0));
        label_subTag4->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        button_subTag4->setText(QApplication::translate("MainWindow", "X", 0));
        label_subTag6->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        button_subTag6->setText(QApplication::translate("MainWindow", "X", 0));
        label_subTag3->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        button_subTag3->setText(QApplication::translate("MainWindow", "X", 0));
        label_sTagGroup->setText(QApplication::translate("MainWindow", "Sub Tags:", 0));
        label_subTag2->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        button_subTag2->setText(QApplication::translate("MainWindow", "X", 0));
        label_subTag5->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        button_subTag5->setText(QApplication::translate("MainWindow", "X", 0));
        QTreeWidgetItem *___qtreewidgetitem1 = tree_Tags->headerItem();
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", "Tags", 0));
        QTreeWidgetItem *___qtreewidgetitem2 = tree_Clips->headerItem();
        ___qtreewidgetitem2->setText(8, QApplication::translate("MainWindow", "ID", 0));
        ___qtreewidgetitem2->setText(7, QApplication::translate("MainWindow", "Errors", 0));
        ___qtreewidgetitem2->setText(6, QApplication::translate("MainWindow", "ClipsUsed", 0));
        ___qtreewidgetitem2->setText(5, QApplication::translate("MainWindow", "TimeStamp", 0));
        ___qtreewidgetitem2->setText(4, QApplication::translate("MainWindow", "Comment", 0));
        ___qtreewidgetitem2->setText(3, QApplication::translate("MainWindow", "Tags", 0));
        ___qtreewidgetitem2->setText(2, QApplication::translate("MainWindow", "Link", 0));
        ___qtreewidgetitem2->setText(1, QApplication::translate("MainWindow", "Ep.", 0));
        ___qtreewidgetitem2->setText(0, QApplication::translate("MainWindow", "Show Name", 0));
        label_KeyWords->setText(QApplication::translate("MainWindow", "Key Words:", 0));
        label_EpNum->setText(QApplication::translate("MainWindow", "Episode:", 0));
        label_SubTags->setText(QApplication::translate("MainWindow", "Sub Tags:", 0));
        button_AddKeyTag->setText(QApplication::translate("MainWindow", "Add Key Tag", 0));
        label_KeyTags->setText(QApplication::translate("MainWindow", "Key Tags:", 0));
        label_Name->setText(QApplication::translate("MainWindow", "Show Name:", 0));
        button_AddSubTag->setText(QApplication::translate("MainWindow", "Add Sub Tag", 0));
        button_export->setText(QApplication::translate("MainWindow", "Export List", 0));
        button_save->setText(QApplication::translate("MainWindow", "Save Data", 0));
        title_Search->setText(QApplication::translate("MainWindow", "Search", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
