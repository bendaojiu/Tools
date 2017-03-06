#include "image2pdf.h"
#include <QMessageBox>
#include <QMatrix>
#include <QDebug>

#define IMAGE_WIDTH 150
#define IMAGE_HEIGHT 150

Image2Pdf::Image2Pdf(QWidget *parent) : QWidget(parent)
{
    errorCode = 0;
    imageListWidget = new QListWidget();
    imageListWidget->setIconSize(QSize(IMAGE_WIDTH, IMAGE_HEIGHT));     // 设置QListWidget中的单元项的图片大小
    imageListWidget->setResizeMode(QListView::Adjust);
    imageListWidget->setViewMode(QListView::IconMode); // 设置QListWidget的显示模式
    imageListWidget->setMovement(QListView::Static);   //设置QListWidget中的单元项不可被拖动
    imageListWidget->setSpacing(10);                   //设置QListWidget中的单元项的间距

    openImageBtn = new QPushButton(tr("打开图片"));
    connect(openImageBtn, SIGNAL(clicked()), this, SLOT(openImageOnClicked()));
    pdfSaveBtn = new QPushButton(tr("保存为PDF"));
    connect(pdfSaveBtn, SIGNAL(clicked()), this, SLOT(pdfSaveOnClicked()));

    mainLayout = new QGridLayout();
    mainLayout->addWidget(imageListWidget, 0, 0, 8, 8);
    mainLayout->addWidget(openImageBtn, 2, 9, 1, 1);
    mainLayout->addWidget(pdfSaveBtn, 4, 9, 1, 1);

    // 设置模态,以阻塞其他操作
//    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
//    setWindowModality(Qt::WindowModal);

    this->setLayout(mainLayout);
    this->resize(800, 600);
}

void Image2Pdf::openImageOnClicked()
{
    QStringList files = QFileDialog::getOpenFileNames(this, tr("选择图片"), "",
                                                      tr("Image Files(*.png *.xpm *.jpg)"));
    if (files.isEmpty())
    {
        qDebug() << "未获取到图片文件" << __FILE__ ;
        return;
    }
    if (imageListWidget->count() == 0)
    {
        for (int i=0; i<files.count(); ++i)
        {
            QPixmap tmpPixmap(files.at(i));
            QListWidgetItem *tmpItem = new QListWidgetItem(QIcon(tmpPixmap.scaled(QSize(IMAGE_WIDTH, IMAGE_HEIGHT))),
                                                           files.at(i));
            tmpItem->setSizeHint(QSize(IMAGE_WIDTH, IMAGE_HEIGHT));
            imageListWidget->insertItem(i, tmpItem);
        }
    }
    else
    {
        for (int i=0; i<files.count(); ++i)
        {
            QPixmap tmpPixmap(files.at(i));
            QListWidgetItem *tmpItem = new QListWidgetItem(QIcon(tmpPixmap.scaled(QSize(IMAGE_WIDTH, IMAGE_HEIGHT))),
                                                           files.at(i));
            tmpItem->setSizeHint(QSize(IMAGE_WIDTH, IMAGE_HEIGHT));
            imageListWidget->insertItem(i + imageListWidget->count(), tmpItem);
        }
    }
    this->update();
}

void Image2Pdf::pdfSaveOnClicked()
{
    // 该对话框已经包含了文件重复的判断,不需要在判断
    QString fileName = QFileDialog::getSaveFileName(this, tr("保存为PDF"), "", tr("PDF File(*.pdf)"));
    if (!fileName.isNull())
    {
        QFile file(fileName);

        // 创建文件,需要调用close之后文件才会创建
        file.open(QIODevice::WriteOnly);
        file.close();

        QPrinter printer_pixmap;
        // 添加下句作为构造函数后,图像变小了
//        (QPrinter::HighResolution);
        printer_pixmap.setPageSize(QPrinter::A4);            // 设置纸张大小为A4
        printer_pixmap.setOutputFormat(QPrinter::PdfFormat); //设置输出格式为pdf
        printer_pixmap.setOutputFileName(fileName);          //设置输出路径

        // 判断是否选中文件
        if (imageListWidget->count() == 0)
        {
            QMessageBox::warning(NULL, tr("没有选中文件"), tr("没有选中文件,请点击选择图片按钮选择图片"), QMessageBox::Yes);
        }

        QPainter painter_pixmap;
        painter_pixmap.begin(&printer_pixmap);


        for (int i=0; i<imageListWidget->count(); ++i)
        {
            QPixmap tmpPixmap(imageListWidget->item(i)->text());
//            QSize tmpSize(tmpPixmap.size());
            // 这是用来旋转图片用的
            //                if (tmpSize.width() > tmpSize.height())
            //                {
            //                    QMatrix tmpMatrix;
            //                    tmpMatrix.rotate(90);
            //                    tmpPixmap.transformed(tmpMatrix, Qt::SmoothTransformation);
            //                }

//            painter_pixmap.scale(0, 0);
            //用于生产新的一页
            if (i > 0)
                printer_pixmap.newPage();
            painter_pixmap.drawPixmap(0, i, tmpPixmap);
        }
        painter_pixmap.end();

    }
    else
    {
        // 点击取消
    }
}
