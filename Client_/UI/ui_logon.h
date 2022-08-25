/********************************************************************************
** Form generated from reading UI file 'logon.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGON_H
#define UI_LOGON_H

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

class Ui_Logon
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *accountLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *accountLabel;
    QLineEdit *uname;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *accountLayout_2;
    QSpacerItem *horizontalSpacer_7;
    QLabel *accountLabel_2;
    QLineEdit *password1;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *passwordLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *passwordLabel;
    QLineEdit *password2;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *logon;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_3;
    QCommandLinkButton *toLog;
    QSpacerItem *verticalSpacer_6;

    void setupUi(QWidget *Logon)
    {
        if (Logon->objectName().isEmpty())
            Logon->setObjectName(QStringLiteral("Logon"));
        Logon->setWindowModality(Qt::NonModal);
        Logon->resize(396, 375);
        Logon->setCursor(QCursor(Qt::ArrowCursor));
        Logon->setStyleSheet(QStringLiteral("background-image: url(:/log/Icon/logbackgroud1.jpg);"));
        verticalLayout = new QVBoxLayout(Logon);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_4 = new QSpacerItem(20, 120, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        accountLayout = new QHBoxLayout();
        accountLayout->setObjectName(QStringLiteral("accountLayout"));
        horizontalSpacer = new QSpacerItem(5, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        accountLayout->addItem(horizontalSpacer);

        accountLabel = new QLabel(Logon);
        accountLabel->setObjectName(QStringLiteral("accountLabel"));
        accountLabel->setStyleSheet(QString::fromUtf8("background: transparent; \n"
"font: 10pt \"\351\273\221\344\275\223\";"));

        accountLayout->addWidget(accountLabel);

        uname = new QLineEdit(Logon);
        uname->setObjectName(QStringLiteral("uname"));
        uname->setMinimumSize(QSize(160, 22));
        uname->setStyleSheet(QLatin1String("background-image: url(:/log/Icon/nobackground.jpg);\n"
"border-radius:4px;\n"
""));

        accountLayout->addWidget(uname);

        horizontalSpacer_2 = new QSpacerItem(95, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        accountLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(accountLayout);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        accountLayout_2 = new QHBoxLayout();
        accountLayout_2->setObjectName(QStringLiteral("accountLayout_2"));
        horizontalSpacer_7 = new QSpacerItem(5, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        accountLayout_2->addItem(horizontalSpacer_7);

        accountLabel_2 = new QLabel(Logon);
        accountLabel_2->setObjectName(QStringLiteral("accountLabel_2"));
        accountLabel_2->setStyleSheet(QString::fromUtf8("background: transparent; \n"
"font: 10pt \"\351\273\221\344\275\223\";"));

        accountLayout_2->addWidget(accountLabel_2);

        password1 = new QLineEdit(Logon);
        password1->setObjectName(QStringLiteral("password1"));
        password1->setMinimumSize(QSize(160, 22));
        password1->setStyleSheet(QLatin1String("background-image: url(:/log/Icon/nobackground.jpg);\n"
"border-radius:4px;"));

        accountLayout_2->addWidget(password1);

        horizontalSpacer_8 = new QSpacerItem(95, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        accountLayout_2->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(accountLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        passwordLayout = new QHBoxLayout();
        passwordLayout->setObjectName(QStringLiteral("passwordLayout"));
        horizontalSpacer_3 = new QSpacerItem(5, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        passwordLayout->addItem(horizontalSpacer_3);

        passwordLabel = new QLabel(Logon);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));
        passwordLabel->setStyleSheet(QString::fromUtf8("background: transparent; \n"
"font: 10pt \"\351\273\221\344\275\223\";"));

        passwordLayout->addWidget(passwordLabel);

        password2 = new QLineEdit(Logon);
        password2->setObjectName(QStringLiteral("password2"));
        password2->setMinimumSize(QSize(160, 22));
        password2->setSizeIncrement(QSize(10, 10));
        password2->setStyleSheet(QLatin1String("background-image: url(:/log/Icon/nobackground.jpg);\n"
"border-radius:4px;"));

        passwordLayout->addWidget(password2);

        horizontalSpacer_4 = new QSpacerItem(95, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        passwordLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(passwordLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        logon = new QPushButton(Logon);
        logon->setObjectName(QStringLiteral("logon"));
        logon->setStyleSheet(QString::fromUtf8("font: 10pt \"\351\273\221\344\275\223\";"));

        horizontalLayout->addWidget(logon);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        toLog = new QCommandLinkButton(Logon);
        toLog->setObjectName(QStringLiteral("toLog"));
        toLog->setCursor(QCursor(Qt::ArrowCursor));
        toLog->setStyleSheet(QString::fromUtf8("background: transparent; \n"
"font: 10pt \"\351\273\221\344\275\223\";"));

        verticalLayout->addWidget(toLog);

        verticalSpacer_6 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);


        retranslateUi(Logon);

        QMetaObject::connectSlotsByName(Logon);
    } // setupUi

    void retranslateUi(QWidget *Logon)
    {
        Logon->setWindowTitle(QApplication::translate("Logon", "Form", Q_NULLPTR));
        accountLabel->setText(QApplication::translate("Logon", " \347\224\250\346\210\267\345\220\215 ", Q_NULLPTR));
        accountLabel_2->setText(QApplication::translate("Logon", " \345\257\206  \347\240\201 ", Q_NULLPTR));
        passwordLabel->setText(QApplication::translate("Logon", "\347\241\256\350\256\244\345\257\206\347\240\201", Q_NULLPTR));
        logon->setText(QApplication::translate("Logon", "\346\263\250\345\206\214", Q_NULLPTR));
        toLog->setText(QApplication::translate("Logon", "\347\231\273\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Logon: public Ui_Logon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGON_H
