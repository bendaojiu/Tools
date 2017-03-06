#ifndef PICTUREWIDGET_H
#define PICTUREWIDGET_H
/*********************************************************
 * 图像界面主窗口
 * ******************************************************/
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QList>

class PictureWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PictureWidget(QWidget *parent = 0);


public:
    QList<QPushButton *> pushButtonList;    // 用于保存按钮的列表
    QList<QHBoxLayout *> hboxLayoutList;    // 用于保存横向布局的列表
    QVBoxLayout *mainLayout;                // 主布局

signals:

public slots:
    void showImageMosaicking();             // 用于显示图片拼接的窗口

};

#endif // PICTUREWIDGET_H
