QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    cryptodata.cpp \
    stenography.cpp \
    window.cpp

HEADERS += \
    window.hpp

FORMS += \
    window.ui

RESOURCES += \
    resources.qrc
