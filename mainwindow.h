#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSplitter>
#include "mainwidget.h"
#include "./picture/picturewidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();


public:
    QPushButton *homePageBtn;  // 首页按钮
    QPushButton *pictureBtn;   // 图像按钮
    QVBoxLayout *firstLayout;
    QHBoxLayout *mainLayout;
    QWidget *w;


private:
    MainWidget *mainWidget;
    PictureWidget *pictrueWidget;
    int widgetNum;  // 当前窗体的编号,便于切换的时候移除

private slots:
    void changeWidget0();
    void changeWidget1();
//    void changeWidget2();
//    void changeWidget3();
};

#endif // MAINWINDOW_H
