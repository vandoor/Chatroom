#ifndef TEXTRECORD_H
#define TEXTRECORD_H

#include <QWidget>
#include <QScrollBar>
#include <QAbstractSlider>
#include <QResizeEvent>

class TextRecord : public QWidget
{
    Q_OBJECT
public:
    explicit TextRecord(QWidget *parent = 0);
    void setScrollBar(QScrollBar *scrollBar);
private:
    QScrollBar * hscrollbar;
    QPoint initPoint;
    int factualHeight;
    int seenHeight;
signals:

public slots:
    void valueChangeScrollBar(int value);
protected:

};

#endif // TEXTRECORD_H
