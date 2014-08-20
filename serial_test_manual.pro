#-------------------------------------------------
#
# Project created by QtCreator 2011-11-04T13:00:52
#
#-------------------------------------------------

QT       += core gui sql

TARGET = serial_test_manual
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    createprofform.cpp \
    dbmanager.cpp \
    delegate.cpp \
    viewmanager.cpp \
    perfil.cpp \
    commmanager.cpp

HEADERS  += mainwindow.h \
    createprofform.h \
    dbmanager.h \
    delegate.h \
    viewmanager.h \
    perfil.h \
    commmanager.h

FORMS    += mainwindow.ui \
    createprofform.ui




win32:CONFIG(release, debug|release): LIBS += -L$$PWD/qextserialport-build-desktop/build/ -lqextserialport -lsetupapi
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/qextserialport-build-desktop/build/ -lqextserialportd  -lsetupapi
else:unix:!symbian:CONFIG(release, debug|release): LIBS += -L$$PWD/qextserialport-build-desktop/build/ -lqextserialport
else:unix:!symbian:CONFIG(debug, debug|release): LIBS += -L$$PWD/qextserialport-build-desktop/build/ -lqextserialportd

INCLUDEPATH += $$PWD/qextserialport
DEPENDPATH += $$PWD/qextserialport

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/qextserialport-build-desktop/build/libqextserialport.a
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/qextserialport-build-desktop/build/libqextserialportd.a
else:unix:!symbian:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/qextserialport-build-desktop/build/libqextserialport.a
else:unix:!symbian:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/qextserialport-build-desktop/build/libqextserialportd.a
