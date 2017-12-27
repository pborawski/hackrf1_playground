TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += /usr/include/SoapySDR/
LIBS += -lSoapySDR

SOURCES += main.cpp \
    soapyhackrf.cpp

HEADERS += \
    soapyhackrf.h
