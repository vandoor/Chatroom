/********************************************************************************
** Form generated from reading UI file 'notice.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTICE_H
#define UI_NOTICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Notice
{
public:

    void setupUi(QWidget *Notice)
    {
        if (Notice->objectName().isEmpty())
            Notice->setObjectName(QStringLiteral("Notice"));
        Notice->resize(400, 300);

        retranslateUi(Notice);

        QMetaObject::connectSlotsByName(Notice);
    } // setupUi

    void retranslateUi(QWidget *Notice)
    {
        Notice->setWindowTitle(QApplication::translate("Notice", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Notice: public Ui_Notice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTICE_H
