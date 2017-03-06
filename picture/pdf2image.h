#ifndef PDF2IMAGE_H
#define PDF2IMAGE_H

#include <QWidget>
#include <QSplitter>
#include <QPushButton>
#include <QFileDialog>
#include <QListWidget>
#include <QGridLayout>

class Pdf2Image : public QWidget
{
    Q_OBJECT
public:
    explicit Pdf2Image(QWidget *parent = 0);


public:
    QListWidget *imageListWidget;        // 用于显示图片的窗口
    QSplitter *leftSplitter;             // 用于左边的分割窗口
    QPushButton *openImageBtn;           // 用于打开图像的按钮
    QPushButton *pdfSaveBtn;             // 用于保存生成的pdf按钮
    QGridLayout *mainLayout;             // 主布局

signals:

public slots:
};

#endif // PDF2IMAGE_H
