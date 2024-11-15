QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

    INCLUDEPATH += C:/opencv-4.9.0/build/install/include

    LIBS += -LC:/opencv-4.9.0/build/install/x64/mingw/lib \
        -lopencv_core490 \
        -lopencv_imgproc490 \
        -lopencv_highgui490 \
        -lopencv_video490   \
        -lopencv_imgcodecs490

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc