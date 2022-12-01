QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminwindow.cpp \
    loginwindow.cpp \
    main.cpp \
    manageinventory.cpp \
    managemembers.cpp \
    managerwindow.cpp \
    memberconversions.cpp

HEADERS += \
    adminwindow.h \
    loginwindow.h \
    manageinventory.h \
    managemembers.h \
    managerwindow.h \
    memberconversions.h

FORMS += \
    adminwindow.ui \
    loginwindow.ui \
    manageinventory.ui \
    managemembers.ui \
    managerwindow.ui \
    memberconversions.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
