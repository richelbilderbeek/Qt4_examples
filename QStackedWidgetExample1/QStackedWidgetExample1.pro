QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TEMPLATE = app

SOURCES += main.cpp\
        dialog.cpp \
    masterdialog.cpp

HEADERS  += dialog.h \
    masterdialog.h

FORMS    += dialog.ui \
    masterdialog.ui
