#ifndef PDF2IMAGE_H
#define PDF2IMAGE_H

#include <QWidget>
#include <QSplitter>
#include <QPushButton>
#include <QFileDialog>
#include <QListWidget>
#include <QGridLayout>
#include <QtPrintSupport/QPrinter>
#include <QPainter>

class Image2Pdf : public QWidget
{
    Q_OBJECT
public:
    explicit Image2Pdf(QWidget *parent = 0);


public:
    QListWidget *imageListWidget;        // 用于显示图片的窗口
    QPushButton *openImageBtn;           // 用于打开图像的按钮
    QPushButton *pdfSaveBtn;             // 用于保存生成的pdf按钮
    QGridLayout *mainLayout;             // 主布局

    int errorCode;                       // 用来保存错误代码


public slots:
    void openImageOnClicked();
    void pdfSaveOnClicked();
};

#endif // PDF2IMAGE_H
