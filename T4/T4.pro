QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    T3/library.cpp \
    about.cpp \
    dev.cpp \
    doa.cpp \
    emp.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    T3/library.hpp \
    about.h \
    dev.h \
    doa.h \
    emp.h \
    mainwindow.h

FORMS += \
    about.ui \
    dev.ui \
    doa.ui \
    emp.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src.qrc
