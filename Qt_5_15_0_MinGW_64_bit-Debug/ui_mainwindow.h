/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *LabelVersion;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *ButtonSettings;
    QLabel *labelAuthError;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *LineEditLogin;
    QPushButton *ButtonGetPassword;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *LineEditPassword;
    QPushButton *ButtonEnter;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *ButtonCancelYandex;
    QPushButton *ButtonCancelCitymobile;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(240, 391);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 62, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LabelVersion = new QLabel(centralwidget);
        LabelVersion->setObjectName(QString::fromUtf8("LabelVersion"));

        horizontalLayout->addWidget(LabelVersion);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        ButtonSettings = new QPushButton(centralwidget);
        ButtonSettings->setObjectName(QString::fromUtf8("ButtonSettings"));

        horizontalLayout->addWidget(ButtonSettings);


        verticalLayout_3->addLayout(horizontalLayout);

        labelAuthError = new QLabel(centralwidget);
        labelAuthError->setObjectName(QString::fromUtf8("labelAuthError"));
        QFont font;
        font.setPointSize(14);
        labelAuthError->setFont(font);
        labelAuthError->setStyleSheet(QString::fromUtf8("color: rgb(102, 97, 255);"));

        verticalLayout_3->addWidget(labelAuthError);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        verticalLayout->addWidget(label);

        LineEditLogin = new QLineEdit(centralwidget);
        LineEditLogin->setObjectName(QString::fromUtf8("LineEditLogin"));
        LineEditLogin->setFont(font);

        verticalLayout->addWidget(LineEditLogin);


        verticalLayout_3->addLayout(verticalLayout);

        ButtonGetPassword = new QPushButton(centralwidget);
        ButtonGetPassword->setObjectName(QString::fromUtf8("ButtonGetPassword"));
        ButtonGetPassword->setFont(font);

        verticalLayout_3->addWidget(ButtonGetPassword);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        LineEditPassword = new QLineEdit(centralwidget);
        LineEditPassword->setObjectName(QString::fromUtf8("LineEditPassword"));
        LineEditPassword->setFont(font);

        verticalLayout_2->addWidget(LineEditPassword);


        verticalLayout_3->addLayout(verticalLayout_2);

        ButtonEnter = new QPushButton(centralwidget);
        ButtonEnter->setObjectName(QString::fromUtf8("ButtonEnter"));
        ButtonEnter->setFont(font);

        verticalLayout_3->addWidget(ButtonEnter);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_3->addWidget(lineEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        ButtonCancelYandex = new QPushButton(centralwidget);
        ButtonCancelYandex->setObjectName(QString::fromUtf8("ButtonCancelYandex"));

        horizontalLayout_2->addWidget(ButtonCancelYandex);

        ButtonCancelCitymobile = new QPushButton(centralwidget);
        ButtonCancelCitymobile->setObjectName(QString::fromUtf8("ButtonCancelCitymobile"));

        horizontalLayout_2->addWidget(ButtonCancelCitymobile);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 62, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 240, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\321\202\320\275\321\221\321\200\321\213", nullptr));
        LabelVersion->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        ButtonSettings->setText(QString());
        labelAuthError->setText(QCoreApplication::translate("MainWindow", "\320\243\321\201\320\277\320\265\321\210\320\275\320\276 \320\260\320\262\321\202\320\276\321\200\320\270\320\267\320\276\320\262\320\260\320\275\320\276!", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        ButtonGetPassword->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        ButtonEnter->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        ButtonCancelYandex->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\260 \320\257\320\275\320\264\320\265\320\272\321\201", nullptr));
        ButtonCancelCitymobile->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\260 \320\241\320\270\321\202\320\270\320\274\320\276\320\261\320\270\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
