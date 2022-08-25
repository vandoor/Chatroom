#include "textrecord.h"

TextRecord::TextRecord(QWidget *parent) : QWidget(parent)
{
    hscrollbar = new QScrollBar(Qt::Vertical,nullptr);
    initPoint = this->pos();
//    connect(hscrollbar,SIGNAL(valueChanged(int)),this,SLOT(valueChangeScrollBar(int)));
}

void TextRecord::valueChangeScrollBar(int value){
    this->move(QPoint(initPoint.x(),initPoint.y()+value*factualHeight/100));
}


void TextRecord::setScrollBar(QScrollBar *scrollBar){
    this->hscrollbar = scrollBar;
}

