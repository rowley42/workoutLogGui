/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *windowTabs;
    QWidget *generalTab;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QTextEdit *outputEdit;
    QLineEdit *setInput;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QLineEdit *exerciseInput;
    QLabel *label;
    QLabel *logoLabel1;
    QWidget *routineTab;
    QTextEdit *routineEdit;
    QLabel *label_5;
    QLabel *label_3;
    QWidget *recordTab;
    QLabel *label_4;
    QLabel *searchIcon;
    QTextEdit *recordEdit;
    QWidget *recordTabGraph;
    QPushButton *chartButton;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_6;
    QLineEdit *chartInput;
    QFrame *frame;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(616, 526);
        MainWindow->setMaximumSize(QSize(616, 526));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        windowTabs = new QTabWidget(centralwidget);
        windowTabs->setObjectName(QString::fromUtf8("windowTabs"));
        windowTabs->setGeometry(QRect(0, 0, 661, 591));
        generalTab = new QWidget();
        generalTab->setObjectName(QString::fromUtf8("generalTab"));
        gridLayoutWidget = new QWidget(generalTab);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(40, 100, 461, 331));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        outputEdit = new QTextEdit(gridLayoutWidget);
        outputEdit->setObjectName(QString::fromUtf8("outputEdit"));
        outputEdit->setReadOnly(true);

        gridLayout->addWidget(outputEdit, 3, 1, 1, 1);

        setInput = new QLineEdit(gridLayoutWidget);
        setInput->setObjectName(QString::fromUtf8("setInput"));

        gridLayout->addWidget(setInput, 2, 1, 1, 1);

        comboBox = new QComboBox(gridLayoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 0, 0, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 4, 1, 1, 1);

        exerciseInput = new QLineEdit(gridLayoutWidget);
        exerciseInput->setObjectName(QString::fromUtf8("exerciseInput"));

        gridLayout->addWidget(exerciseInput, 1, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        logoLabel1 = new QLabel(generalTab);
        logoLabel1->setObjectName(QString::fromUtf8("logoLabel1"));
        logoLabel1->setGeometry(QRect(240, 10, 221, 91));
        logoLabel1->setPixmap(QPixmap(QString::fromUtf8("dumbell.png")));
        windowTabs->addTab(generalTab, QString());
        routineTab = new QWidget();
        routineTab->setObjectName(QString::fromUtf8("routineTab"));
        routineEdit = new QTextEdit(routineTab);
        routineEdit->setObjectName(QString::fromUtf8("routineEdit"));
        routineEdit->setGeometry(QRect(60, 80, 491, 371));
        routineEdit->setMinimumSize(QSize(491, 371));
        routineEdit->setMaximumSize(QSize(491, 16777215));
        routineEdit->setReadOnly(true);
        label_5 = new QLabel(routineTab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(210, 20, 131, 31));
        QFont font;
        font.setPointSize(18);
        label_5->setFont(font);
        label_3 = new QLabel(routineTab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(350, 0, 81, 71));
        label_3->setPixmap(QPixmap(QString::fromUtf8("exIcon.png")));
        windowTabs->addTab(routineTab, QString());
        recordTab = new QWidget();
        recordTab->setObjectName(QString::fromUtf8("recordTab"));
        label_4 = new QLabel(recordTab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(140, 30, 261, 31));
        label_4->setFont(font);
        searchIcon = new QLabel(recordTab);
        searchIcon->setObjectName(QString::fromUtf8("searchIcon"));
        searchIcon->setGeometry(QRect(410, 10, 81, 81));
        searchIcon->setPixmap(QPixmap(QString::fromUtf8("recordIcon.png")));
        recordEdit = new QTextEdit(recordTab);
        recordEdit->setObjectName(QString::fromUtf8("recordEdit"));
        recordEdit->setGeometry(QRect(70, 100, 481, 321));
        recordEdit->setReadOnly(true);
        windowTabs->addTab(recordTab, QString());
        recordTabGraph = new QWidget();
        recordTabGraph->setObjectName(QString::fromUtf8("recordTabGraph"));
        chartButton = new QPushButton(recordTabGraph);
        chartButton->setObjectName(QString::fromUtf8("chartButton"));
        chartButton->setGeometry(QRect(190, 400, 231, 28));
        formLayoutWidget = new QWidget(recordTabGraph);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 20, 421, 31));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_6);

        chartInput = new QLineEdit(formLayoutWidget);
        chartInput->setObjectName(QString::fromUtf8("chartInput"));

        formLayout->setWidget(0, QFormLayout::FieldRole, chartInput);

        frame = new QFrame(recordTabGraph);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(19, 69, 581, 311));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        windowTabs->addTab(recordTabGraph, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 616, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        windowTabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gym Progress Tracker", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Enter Set|Rep|Weight:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Add Exercise", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Enter Record", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Search Exercise", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Search Record", nullptr));

        pushButton->setText(QCoreApplication::translate("MainWindow", "Go", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Enter Exercise:", nullptr));
        logoLabel1->setText(QString());
        windowTabs->setTabText(windowTabs->indexOf(generalTab), QCoreApplication::translate("MainWindow", "General", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Exercise List", nullptr));
        label_3->setText(QString());
        windowTabs->setTabText(windowTabs->indexOf(routineTab), QCoreApplication::translate("MainWindow", "Routine", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "List of Previous Records", nullptr));
        searchIcon->setText(QString());
        windowTabs->setTabText(windowTabs->indexOf(recordTab), QCoreApplication::translate("MainWindow", "Records", nullptr));
        chartButton->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Search Exercise:", nullptr));
        windowTabs->setTabText(windowTabs->indexOf(recordTabGraph), QCoreApplication::translate("MainWindow", "Progression", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
