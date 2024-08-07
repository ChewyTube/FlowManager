/********************************************************************************
** Form generated from reading UI file 'FlowManager.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLOWMANAGER_H
#define UI_FLOWMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FlowManager
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *Main;
    QLabel *LabelHead;
    QLabel *LabelExpected;
    QLabel *LabelActual;
    QTextEdit *EditExpected;
    QTextEdit *EditActual;
    QLabel *label_9;
    QLabel *label_10;
    QFrame *Students;
    QPushButton *ButtonCount;
    QLabel *label_21;
    QComboBox *comboBox;
    QFrame *Destination;
    QLabel *label_19;
    QLabel *label_3;
    QLabel *label_18;
    QCheckBox *allowMin;
    QCheckBox *showSysTime;
    QLabel *label_4;
    QWidget *Settings;
    QLabel *label_6;
    QLabel *urlLabel;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_7;
    QComboBox *classChooseBox;
    QLabel *label_5;
    QWidget *tab;
    QLabel *label;
    QComboBox *presetTimeChoose;
    QFrame *Students_2;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FlowManager)
    {
        if (FlowManager->objectName().isEmpty())
            FlowManager->setObjectName("FlowManager");
        FlowManager->resize(1540, 850);
        centralwidget = new QWidget(FlowManager);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 0, 1521, 812));
        Main = new QWidget();
        Main->setObjectName("Main");
        LabelHead = new QLabel(Main);
        LabelHead->setObjectName("LabelHead");
        LabelHead->setGeometry(QRect(20, 40, 991, 121));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(72);
        LabelHead->setFont(font);
        LabelExpected = new QLabel(Main);
        LabelExpected->setObjectName("LabelExpected");
        LabelExpected->setGeometry(QRect(920, 60, 91, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font1.setPointSize(24);
        LabelExpected->setFont(font1);
        LabelActual = new QLabel(Main);
        LabelActual->setObjectName("LabelActual");
        LabelActual->setGeometry(QRect(920, 120, 91, 51));
        LabelActual->setFont(font1);
        EditExpected = new QTextEdit(Main);
        EditExpected->setObjectName("EditExpected");
        EditExpected->setGeometry(QRect(1020, 60, 271, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font2.setPointSize(22);
        EditExpected->setFont(font2);
        EditActual = new QTextEdit(Main);
        EditActual->setObjectName("EditActual");
        EditActual->setGeometry(QRect(1020, 120, 271, 51));
        EditActual->setFont(font2);
        label_9 = new QLabel(Main);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(1300, 60, 31, 51));
        label_9->setFont(font1);
        label_10 = new QLabel(Main);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(1300, 120, 41, 51));
        label_10->setFont(font1);
        Students = new QFrame(Main);
        Students->setObjectName("Students");
        Students->setGeometry(QRect(30, 210, 1291, 561));
        Students->setFrameShape(QFrame::Shape::StyledPanel);
        Students->setFrameShadow(QFrame::Shadow::Raised);
        ButtonCount = new QPushButton(Main);
        ButtonCount->setObjectName("ButtonCount");
        ButtonCount->setGeometry(QRect(1360, 120, 121, 51));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font3.setPointSize(16);
        ButtonCount->setFont(font3);
        label_21 = new QLabel(Main);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(1340, 600, 126, 26));
        QFont font4;
        font4.setPointSize(16);
        label_21->setFont(font4);
        comboBox = new QComboBox(Main);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(1340, 630, 141, 31));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font5.setPointSize(14);
        comboBox->setFont(font5);
        Destination = new QFrame(Main);
        Destination->setObjectName("Destination");
        Destination->setGeometry(QRect(1330, 210, 181, 381));
        Destination->setFrameShape(QFrame::Shape::StyledPanel);
        Destination->setFrameShadow(QFrame::Shadow::Raised);
        label_19 = new QLabel(Destination);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(10, 10, 105, 26));
        label_19->setFont(font4);
        label_3 = new QLabel(Destination);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 350, 181, 31));
        label_18 = new QLabel(Main);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(1341, 789, 63, 28));
        label_18->setFont(font3);
        label_18->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230)"));
        allowMin = new QCheckBox(Main);
        allowMin->setObjectName("allowMin");
        allowMin->setGeometry(QRect(1340, 670, 141, 31));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font6.setPointSize(12);
        allowMin->setFont(font6);
        showSysTime = new QCheckBox(Main);
        showSysTime->setObjectName("showSysTime");
        showSysTime->setGeometry(QRect(1340, 700, 111, 31));
        showSysTime->setFont(font6);
        label_4 = new QLabel(Main);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(1340, 729, 131, 41));
        label_4->setStyleSheet(QString::fromUtf8("color:rgb(204, 204, 204)"));
        tabWidget->addTab(Main, QString());
        Settings = new QWidget();
        Settings->setObjectName("Settings");
        label_6 = new QLabel(Settings);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(50, 180, 291, 20));
        urlLabel = new QLabel(Settings);
        urlLabel->setObjectName("urlLabel");
        urlLabel->setGeometry(QRect(350, 180, 271, 20));
        urlLabel->setStyleSheet(QString::fromUtf8("<herf=https://github.com/ChewyTube/FlowManager>https://github.com/ChewyTube/FlowManager"));
        plainTextEdit = new QPlainTextEdit(Settings);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(50, 210, 561, 171));
        label_7 = new QLabel(Settings);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(60, 39, 121, 41));
        QFont font7;
        font7.setPointSize(14);
        label_7->setFont(font7);
        classChooseBox = new QComboBox(Settings);
        classChooseBox->addItem(QString());
        classChooseBox->addItem(QString());
        classChooseBox->addItem(QString());
        classChooseBox->addItem(QString());
        classChooseBox->addItem(QString());
        classChooseBox->addItem(QString());
        classChooseBox->addItem(QString());
        classChooseBox->addItem(QString());
        classChooseBox->addItem(QString());
        classChooseBox->addItem(QString());
        classChooseBox->addItem(QString());
        classChooseBox->addItem(QString());
        classChooseBox->addItem(QString());
        classChooseBox->addItem(QString());
        classChooseBox->setObjectName("classChooseBox");
        classChooseBox->setGeometry(QRect(160, 40, 141, 41));
        classChooseBox->setFont(font7);
        label_5 = new QLabel(Settings);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(60, 390, 361, 71));
        tabWidget->addTab(Settings, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        label = new QLabel(tab);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 30, 81, 51));
        label->setFont(font3);
        presetTimeChoose = new QComboBox(tab);
        presetTimeChoose->addItem(QString());
        presetTimeChoose->addItem(QString());
        presetTimeChoose->addItem(QString());
        presetTimeChoose->addItem(QString());
        presetTimeChoose->setObjectName("presetTimeChoose");
        presetTimeChoose->setGeometry(QRect(130, 40, 141, 31));
        presetTimeChoose->setFont(font5);
        Students_2 = new QFrame(tab);
        Students_2->setObjectName("Students_2");
        Students_2->setGeometry(QRect(30, 90, 1291, 561));
        Students_2->setFrameShape(QFrame::Shape::StyledPanel);
        Students_2->setFrameShadow(QFrame::Shadow::Raised);
        label_2 = new QLabel(tab);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(310, 30, 341, 51));
        tabWidget->addTab(tab, QString());
        FlowManager->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FlowManager);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1540, 37));
        FlowManager->setMenuBar(menubar);
        statusbar = new QStatusBar(FlowManager);
        statusbar->setObjectName("statusbar");
        FlowManager->setStatusBar(statusbar);

        retranslateUi(FlowManager);
        QObject::connect(ButtonCount, SIGNAL(clicked()), FlowManager, SLOT(Count()));
        QObject::connect(comboBox, SIGNAL(currentTextChanged(QString)), FlowManager, SLOT(PeriodChanged(QString)));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FlowManager);
    } // setupUi

    void retranslateUi(QMainWindow *FlowManager)
    {
        FlowManager->setWindowTitle(QCoreApplication::translate("FlowManager", "FlowManager", nullptr));
        LabelHead->setText(QCoreApplication::translate("FlowManager", "  \350\207\252\344\277\256\344\272\272\345\221\230\346\265\201\345\212\250\347\256\241\347\220\206", nullptr));
        LabelExpected->setText(QCoreApplication::translate("FlowManager", "\345\272\224\345\210\260\357\274\232", nullptr));
        LabelActual->setText(QCoreApplication::translate("FlowManager", "\345\234\250\347\217\255\357\274\232", nullptr));
        EditExpected->setHtml(QCoreApplication::translate("FlowManager", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; font-size:22pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">47</p></body></html>", nullptr));
        EditActual->setHtml(QCoreApplication::translate("FlowManager", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; font-size:22pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">47</p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("FlowManager", "\344\272\272", nullptr));
        label_10->setText(QCoreApplication::translate("FlowManager", "\344\272\272", nullptr));
        ButtonCount->setText(QCoreApplication::translate("FlowManager", "\344\272\272\346\225\260\347\273\237\350\256\241", nullptr));
        label_21->setText(QCoreApplication::translate("FlowManager", "\350\207\252\344\277\256\346\227\266\346\256\265\357\274\232", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("FlowManager", "\345\215\210\350\207\252\344\277\256", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("FlowManager", "\346\231\232\350\207\252\344\277\256", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("FlowManager", "\350\207\252\344\277\256\350\257\276", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("FlowManager", "\346\227\251\350\207\252\344\277\256", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("FlowManager", "\345\260\217\347\244\274\346\213\234", nullptr));

        label_19->setText(QCoreApplication::translate("FlowManager", "\345\216\273\345\220\221\350\257\264\346\230\216\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("FlowManager", "\350\257\267\345\213\277\351\232\217\346\204\217\344\277\256\346\224\271\"\345\205\266\344\273\226\"\344\273\245\345\244\226\347\232\204\345\206\205\345\256\271", nullptr));
        label_18->setText(QCoreApplication::translate("FlowManager", "\344\270\215\345\217\202\345\212\240", nullptr));
        allowMin->setText(QCoreApplication::translate("FlowManager", "\345\205\201\350\256\270\346\234\200\345\260\217\345\214\226", nullptr));
        showSysTime->setText(QCoreApplication::translate("FlowManager", "\346\230\276\347\244\272\346\227\266\351\227\264", nullptr));
        label_4->setText(QCoreApplication::translate("FlowManager", "\347\250\213\345\272\217\347\224\261\346\235\250\345\274\240\351\224\203\345\210\266\344\275\234\n"
"\345\234\250\350\256\276\347\275\256\344\272\206\350\247\243\346\233\264\345\244\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Main), QCoreApplication::translate("FlowManager", "\350\200\203\345\213\244\347\211\214", nullptr));
        label_6->setText(QCoreApplication::translate("FlowManager", "20260134\346\235\250\345\274\240\351\224\203\345\210\266\344\275\234\357\274\214\345\267\262\345\274\200\346\272\220\344\272\216github  \347\202\271\345\207\273\350\267\263\350\275\254 ->", nullptr));
        urlLabel->setText(QCoreApplication::translate("FlowManager", "https://github.com/ChewyTube/FlowManager", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("FlowManager", "\346\233\264\346\226\260\346\227\245\345\277\227\357\274\232\n"
"2024/07/03 23:01 \n"
"\345\217\226\346\266\210\346\234\200\345\260\217\345\214\226\345\212\237\350\203\275\n"
"2024/07/05 21:52\n"
"\346\224\257\346\214\20126\345\261\212\346\211\200\346\234\211\347\217\255\347\272\247\357\274\214\344\277\256\345\244\215\345\205\266\344\273\226\345\267\262\347\237\245\351\227\256\351\242\230\n"
"2024\345\271\2647\346\234\2106\346\227\245 23\347\202\27111\345\210\206\n"
"\344\277\256\346\224\271\344\273\243\347\240\201\346\236\266\346\236\204\n"
"\346\224\257\346\214\201\347\212\266\346\200\201\351\242\234\350\211\262\344\277\256\346\224\271\n"
"\346\224\257\346\214\201Alt+Ctrl+F\345\277\253\346\215\267\351\224\256\345\205\201\350\256\270\346\234\200\345\260\217\345\214\2262min\357\274\214Alt+Ctrl+K\345\217\226\346\266\210\345\205\201\350\256\270\346\234\200\345\260\217\345\214\226", nullptr));
        label_7->setText(QCoreApplication::translate("FlowManager", "\347\217\255\347\272\247\351\200\211\346\213\251\357\274\232", nullptr));
        classChooseBox->setItemText(0, QCoreApplication::translate("FlowManager", "01", nullptr));
        classChooseBox->setItemText(1, QCoreApplication::translate("FlowManager", "02", nullptr));
        classChooseBox->setItemText(2, QCoreApplication::translate("FlowManager", "03", nullptr));
        classChooseBox->setItemText(3, QCoreApplication::translate("FlowManager", "04", nullptr));
        classChooseBox->setItemText(4, QCoreApplication::translate("FlowManager", "05", nullptr));
        classChooseBox->setItemText(5, QCoreApplication::translate("FlowManager", "06", nullptr));
        classChooseBox->setItemText(6, QCoreApplication::translate("FlowManager", "07", nullptr));
        classChooseBox->setItemText(7, QCoreApplication::translate("FlowManager", "08", nullptr));
        classChooseBox->setItemText(8, QCoreApplication::translate("FlowManager", "09", nullptr));
        classChooseBox->setItemText(9, QCoreApplication::translate("FlowManager", "10", nullptr));
        classChooseBox->setItemText(10, QCoreApplication::translate("FlowManager", "11", nullptr));
        classChooseBox->setItemText(11, QCoreApplication::translate("FlowManager", "12", nullptr));
        classChooseBox->setItemText(12, QCoreApplication::translate("FlowManager", "13", nullptr));
        classChooseBox->setItemText(13, QCoreApplication::translate("FlowManager", "14", nullptr));

        label_5->setText(QCoreApplication::translate("FlowManager", "\346\232\202\346\227\266\350\277\230\346\230\257\346\227\240\346\263\225\347\233\264\346\216\245\346\234\200\345\260\217\345\214\226\357\274\214\347\255\211\345\255\246\350\200\203\350\200\203\345\256\214\345\206\215\345\206\231", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Settings), QCoreApplication::translate("FlowManager", "\350\256\276\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("FlowManager", "\346\227\266\351\227\264\346\256\265\357\274\232", nullptr));
        presetTimeChoose->setItemText(0, QCoreApplication::translate("FlowManager", "\345\215\210\350\207\252\344\277\256", nullptr));
        presetTimeChoose->setItemText(1, QCoreApplication::translate("FlowManager", "\346\231\232\350\207\252\344\277\256", nullptr));
        presetTimeChoose->setItemText(2, QCoreApplication::translate("FlowManager", "\350\207\252\344\277\256\350\257\276", nullptr));
        presetTimeChoose->setItemText(3, QCoreApplication::translate("FlowManager", "\346\227\251\350\207\252\344\277\256", nullptr));

        label_2->setText(QCoreApplication::translate("FlowManager", "// @TODO \346\267\273\345\212\240\351\242\204\350\256\276 \345\272\247\344\275\215\346\230\240\345\260\204 \345\255\230\345\202\250 \344\277\256\346\224\271\344\272\272\346\225\260\347\273\237\350\256\241(\347\211\271\345\210\253\346\230\257\345\217\230\351\207\217\345\220\215)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("FlowManager", "\351\242\204\350\256\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FlowManager: public Ui_FlowManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLOWMANAGER_H
