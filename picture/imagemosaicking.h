#ifndef IMAGEMOSAICKING_H
#define IMAGEMOSAICKING_H

#include <QWidget>
#include <QSplitter>
#include <QPushButton>

class ImageMosaicking : public QWidget
{
    Q_OBJECT
public:
    explicit ImageMosaicking(QWidget *parent = 0);

    QSplitter *leftWidget;
//    QPushButton *

signals:

public slots:
};

#endif // IMAGEMOSAICKING_H
