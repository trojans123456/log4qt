# include (../src/log4qt/log4qt.pri)

TEMPLATE = app

DISTFILES += \
    bk_log4qt.properties \
    qlog.config


INCLUDEPATH += $$PWD/../dll/include
LIBS += -L$$PWD/../dll/ -llog4qt

HEADERS +=

SOURCES += \
    qlog.cpp

