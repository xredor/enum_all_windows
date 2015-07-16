TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += enum_all_windows.cpp

include(deployment.pri)
qtcAddDeployment()

