#-------------------------------------------------
#
# Project created by QtCreator 2017-03-03T19:44:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tools
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    picture/picturewidget.cpp \
    mainwidget.cpp \
    picture/imagemosaicking.cpp \
    picture/pdf2image.cpp

HEADERS  += mainwindow.h \
    picture/picturewidget.h \
    mainwidget.h \
    imagemosaicking.h \
    picture/imagemosaicking.h \
    picture/pdf2image.h

# 添加opencv
INCLUDEPATH += /usr/local/include/opencv    \
               /usr/local/include/opencv2   \
               /usr/local/include

LIBS += /usr/local/lib/libopencv_highgui.so \
        /usr/local/lib/libopencv_core.so    \
        /usr/local/lib/libopencv_imgproc.so \
        /usr/local/lib/libopencv_imgcodecs.so

# 添加poppler
PKGCONFIG += poppler-qt5
CONFIG += c++11 link_pkgconfig
