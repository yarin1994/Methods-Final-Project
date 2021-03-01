QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GroceryStoreApp
TEMPLATE= app

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminpage.cpp \
    checkoutpage.cpp \
    customerpage.cpp \
    databaseconnector.cpp \
    finishpage.cpp \
    main.cpp \
    mainwindow.cpp \
    manageproducts.cpp \
    monthlyincomepage.cpp \
    signin.cpp \
    signup.cpp \
    todayincomespage.cpp

HEADERS += \
    adminpage.h \
    checkoutpage.h \
    customerpage.h \
    databaseconnector.h \
    finishpage.h \
    mainwindow.h \
    manageproducts.h \
    monthlyincomepage.h \
    signin.h \
    signup.h \
    todayincomespage.h

FORMS += \
    adminpage.ui \
    checkoutpage.ui \
    customerpage.ui \
    finishpage.ui \
    mainwindow.ui \
    manageproducts.ui \
    monthlyincomepage.ui \
    signin.ui \
    signup.ui \
    todayincomespage.ui

TRANSLATIONS += \
    GroceryStoreApp_he_IL.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
