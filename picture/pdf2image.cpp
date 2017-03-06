#include "pdf2image.h"

Pdf2Image::Pdf2Image(QWidget *parent) : QWidget(parent)
{
    imageListWidget = new QListWidget();
    leftSplitter = new QSplitter();

    openImageBtn = new QPushButton(tr("打开图片"));
    pdfSaveBtn = new QPushButton(tr("保存为PDF"));

    mainLayout = new QGridLayout();

    this->setLayout(mainLayout);
}
