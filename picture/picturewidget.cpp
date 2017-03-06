#include "picturewidget.h"
#include "imagemosaicking.h"

const int numOfRow = 2;     // 每行所含有的按钮数量

PictureWidget::PictureWidget(QWidget *parent) : QWidget(parent)
{
    QPushButton *Btn1 = new QPushButton(tr("图片拼接"));
    pushButtonList.append(Btn1);
    connect(Btn1, SIGNAL(clicked()), this, SLOT(showImageMosaicking()));
    QPushButton *Btn2 = new QPushButton(tr("PDF转为图片"));
    QPushButton *Btn3 = new QPushButton(tr("图片转为PDF"));
    pushButtonList.insert(0, Btn2);
    pushButtonList.insert(0, Btn3);

    for (int i=0; i<pushButtonList.count(); i+=2)
    {
        QHBoxLayout *hb1 = new QHBoxLayout();
        hb1->addWidget(pushButtonList.at(i));
        if ((i + 1) < pushButtonList.count())
            hb1->addWidget(pushButtonList.at(i + 1));
        hboxLayoutList.append(hb1);
    }

    mainLayout = new QVBoxLayout();
    for (int i = 0; i < hboxLayoutList.count(); i++)
    {
        mainLayout->addLayout(hboxLayoutList.at(i));
    }

    this->setLayout(mainLayout);
}

void PictureWidget::showImageMosaicking()
{
    ImageMosaicking *w;
    w->show();
}
