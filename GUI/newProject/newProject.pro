QT       += core gui
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    analyzedialog.cpp \
    detailedcontentdialog.cpp \
    detailedcontentdialog2.cpp \
    detailedcontentdialog3.cpp \
    detailedcontentdialog4.cpp \
    detailedcontentdialog5.cpp \
    detailedcontentdialog6.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    analyzedialog.h \
    detailedcontentdialog.h \
    detailedcontentdialog2.h \
    detailedcontentdialog3.h \
    detailedcontentdialog4.h \
    detailedcontentdialog5.h \
    detailedcontentdialog6.h \
    mainwindow.h\


FORMS += \
    analyzedialog.ui \
    detailedcontentdialog.ui \
    detailedcontentdialog2.ui \
    detailedcontentdialog3.ui \
    detailedcontentdialog4.ui \
    detailedcontentdialog5.ui \
    detailedcontentdialog6.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
