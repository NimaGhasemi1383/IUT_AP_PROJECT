QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MainWindow.cpp \
    addteam.cpp \
    deleteteam.cpp \
    editorg.cpp \
    forgotpassword.cpp \
    inorg.cpp \
    main.cpp \
    organization.cpp \
    orgui.cpp \
    outorg.cpp \
    projectui.cpp \
    signup.cpp \
    teamui.cpp \
    user.cpp

HEADERS += \
    MainWindow.h \
    addteam.h \
    deleteteam.h \
    editorg.h \
    forgotpassword.h \
    inorg.h \
    organization.h \
    orgui.h \
    outorg.h \
    projectui.h \
    signup.h \
    teamui.h \
    user.h

FORMS += \
    MainWindow.ui \
    addteam.ui \
    deleteteam.ui \
    editorg.ui \
    forgotpassword.ui \
    inorg.ui \
    organization.ui \
    orgui.ui \
    outorg.ui \
    projectui.ui \
    signup.ui \
    teamui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    picture.qrc

DISTFILES +=
