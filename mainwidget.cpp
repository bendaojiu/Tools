#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    QLabel *lab1 = new QLabel(tr("首页"));
    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(lab1, 1, 1);

    this->setLayout(layout);
}
