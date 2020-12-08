include(log4qt.pri)

TEMPLATE = lib
TARGET = log4qt
QT -= gui

DESTDIR = $$PWD/../dll/


target.path = $$PWD/../dll/
INSTALLS = target

header_base.files = *.h
header_base.path = $$PWD/../dll/include/log4qt
INSTALLS += header_base

header_helpers.files = helpers/*.h
header_helpers.path = $$PWD/../dll/include/log4qt/helpers
INSTALLS += header_helpers

header_spi.files = spi/*.h
header_spi.path = $$PWD/../dll/include/log4qt/spi
INSTALLS += header_spi

header_varia.files = varia/*.h
header_varia.path = $$PWD/../dll/include/log4qt/varia
INSTALLS += header_varia

DISTFILES += \
    demo.txt

