#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H
#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    MyPushButton(QStringList iconList,QWidget* parent = nullptr);

public slots:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void setImage(QString icon);

private:
    QString defaultIcon,inIcon,clickedIcon;




};

#endif // MYPUSHBUTTON_H
