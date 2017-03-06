#include "mainwindow.h"
#include <QLayoutItem>
#include <QList>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    homePageBtn = new QPushButton(tr("首页"));
    connect(homePageBtn, SIGNAL(clicked()), this, SLOT(changeWidget0()));
    pictureBtn = new QPushButton(tr("图片相关"));
    connect(pictureBtn, SIGNAL(clicked()), this, SLOT(changeWidget1()));
    mainWidget = new MainWidget();

    firstLayout = new QVBoxLayout();
    firstLayout->addWidget(homePageBtn);
    firstLayout->addWidget(pictureBtn);
    mainLayout = new QHBoxLayout();
    mainLayout->addLayout(firstLayout, 1);
    mainLayout->addWidget(mainWidget, 3);
    widgetNum = 0;

    w = new QWidget();
    w->setLayout(mainLayout);

    this->setCentralWidget(w);
    this->resize(600, 500);
}

MainWindow::~MainWindow()
{
    delete homePageBtn;
    delete pictureBtn;
    delete firstLayout;
    delete mainLayout;
    delete w;
}

void MainWindow::changeWidget0()
{
    // 删除当前widget
    // 先是用remove,在addWidget发现不行
    // 所以采用了直接析构掉原控件,然后在新建新控件,并添加
    // 试了一下用QSpliter来分割窗口,但是在变换的时候比例不能保证
    // 后来发现了QStackWidget堆栈窗体
    switch (widgetNum)
    {
    case 0:
        return;
    case 1:
        delete pictrueWidget;
        break;
    }
    mainWidget = new MainWidget();
    mainLayout->addWidget(mainWidget, 3);
    this->update();
    widgetNum = 0;
}

void MainWindow::changeWidget1()
{
    // 删除当前widget
    switch (widgetNum)
    {
    case 0:
        delete mainWidget;
        break;
    case 1:
        return;
    }
    pictrueWidget = new PictureWidget();
    mainLayout->addWidget(pictrueWidget, 3);
    this->update();
    widgetNum = 1;
}
