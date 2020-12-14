 include (../src/log4qt/log4qt.pri)

TEMPLATE = app

DISTFILES += \
    bk_log4qt.properties \
    log4qt.proerties.cfg \
    log.cfg


INCLUDEPATH += $$PWD/../dll/include
LIBS += -L$$PWD/../dll/ -llog4qt

HEADERS +=

SOURCES += \
    qlog.cpp

