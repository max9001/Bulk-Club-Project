QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addmember.cpp \
    adminwindow.cpp \
    itemdisplay.cpp \
    loginwindow.cpp \
    main.cpp \
    manageinventory.cpp \
    managemembers.cpp \
    managerwindow.cpp \
    memberpurchase.cpp \
    membershipexpiry.cpp \
    memberupgrade.cpp \
    rebatewindow.cpp \
    salesreport.cpp

HEADERS += \
    addmember.h \
    adminwindow.h \
    itemdisplay.h \
    loginwindow.h \
    manageinventory.h \
    managemembers.h \
    managerwindow.h \
    memberpurchase.h \
    membershipexpiry.h \
    memberupgrade.h \
    rebatewindow.h \
    salesreport.h

FORMS += \
    addmember.ui \
    adminwindow.ui \
    itemdisplay.ui \
    loginwindow.ui \
    manageinventory.ui \
    managemembers.ui \
    managerwindow.ui \
    memberpurchase.ui \
    membershipexpiry.ui \
    memberupgrade.ui \
    salesreport.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
