QT       += core gui sql widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/addgroupdialog.cpp \
    src/admin.cpp \
    src/dialog.cpp \
    src/main.cpp \
    src/mainwindow.cpp

HEADERS += \
    src/addgroupdialog.h \
    src/admin.h \
    src/dialog.h \
    src/mainwindow.h

FORMS += \
    src/addgroupdialog.ui \
    src/admin.ui \
    src/dialog.ui \
    src/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
