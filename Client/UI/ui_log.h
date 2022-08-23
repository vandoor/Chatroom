/********************************************************************************
** Form generated from reading UI file 'log.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOG_H
#define UI_LOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Log
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *accountLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *accountLabel;
    QLineEdit *account;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *passwordLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *passwordLabel;
    QLineEdit *password;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *login;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_3;
    QCommandLinkButton *toLogon;
    QSpacerItem *verticalSpacer_5;

    void setupUi(QWidget *Log)
    {
        if (Log->objectName().isEmpty())
            Log->setObjectName(QStringLiteral("Log"));
        Log->resize(381, 267);
        Log->setStyleSheet(QLatin1String("QListView{\n"
"	font:25 9pt \"Microsoft YaHei\";\n"
"	border: 15px soild white;\n"
"	border-radius: 10px;\n"
"}"));
        verticalLayout = new QVBoxLayout(Log);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_4 = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        accountLayout = new QHBoxLayout();
        accountLayout->setObjectName(QStringLiteral("accountLayout"));
        horizontalSpacer = new QSpacerItem(5, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        accountLayout->addItem(horizontalSpacer);

        accountLabel = new QLabel(Log);
        accountLabel->setObjectName(QStringLiteral("accountLabel"));

        accountLayout->addWidget(accountLabel);

        account = new QLineEdit(Log);
        account->setObjectName(QStringLiteral("account"));

        accountLayout->addWidget(account);

        horizontalSpacer_2 = new QSpacerItem(5, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        accountLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(accountLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        passwordLayout = new QHBoxLayout();
        passwordLayout->setObjectName(QStringLiteral("passwordLayout"));
        horizontalSpacer_3 = new QSpacerItem(5, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        passwordLayout->addItem(horizontalSpacer_3);

        passwordLabel = new QLabel(Log);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));

        passwordLayout->addWidget(passwordLabel);

        password = new QLineEdit(Log);
        password->setObjectName(QStringLiteral("password"));
        password->setSizeIncrement(QSize(10, 10));

        passwordLayout->addWidget(password);

        horizontalSpacer_4 = new QSpacerItem(5, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        passwordLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(passwordLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        login = new QPushButton(Log);
        login->setObjectName(QStringLiteral("login"));
        login->setIconSize(QSize(20, 50));
        login->setAutoRepeat(false);
        login->setAutoExclusive(false);

        horizontalLayout->addWidget(login);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        toLogon = new QCommandLinkButton(Log);
        toLogon->setObjectName(QStringLiteral("toLogon"));

        verticalLayout->addWidget(toLogon);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);


        retranslateUi(Log);

        QMetaObject::connectSlotsByName(Log);
    } // setupUi

    void retranslateUi(QWidget *Log)
    {
        Log->setWindowTitle(QApplication::translate("Log", "Form", Q_NULLPTR));
        accountLabel->setText(QApplication::translate("Log", "\350\264\246\345\217\267", Q_NULLPTR));
        passwordLabel->setText(QApplication::translate("Log", "\345\257\206\347\240\201", Q_NULLPTR));
        login->setText(QApplication::translate("Log", "\347\231\273\345\275\225", Q_NULLPTR));
        toLogon->setText(QApplication::translate("Log", "\346\263\250\345\206\214\350\264\246\345\217\267", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Log: public Ui_Log {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOG_H
