#ifndef MAINUI_H
#define MAINUI_H

#include <QMainWindow>
#include "mainui_leftbar.h"
#include "mainui_midbar.h"
#include "mainui_rightbar.h"
#include "notice.h"

namespace Ui {
class MainUI;
}

class MainUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainUI(QWidget *parent = nullptr);
    ~MainUI();
    void setUID(QString str);
    void resizeEvent(QResizeEvent *event);

private:
    Ui::MainUI *ui;
    QString UID;

    MainUI_LeftBar *leftBar;
    MainUI_MidBar *midBar;
    MainUI_RightBar * rightBar;

signals:

};

#endif // MAINUI_H
