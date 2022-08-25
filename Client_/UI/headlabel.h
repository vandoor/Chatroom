#ifndef HEADLABEL_H
#define HEADLABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QPicture>

class HeadLabel : public QLabel
{
    Q_OBJECT
public:
    explicit HeadLabel(QWidget *parent = nullptr, QString headPhotoPath = "");
    ~HeadLabel() override;

protected:

signals:
    void clicked();

public slots:

private:
    QPicture headPicture;
    QString headPicturePath;

};

#endif // HEADLABEL_H
