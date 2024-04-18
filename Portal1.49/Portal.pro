QT       += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Portal.cpp \
    bullet.cpp \
    chooselevelscene.cpp \
    creategraphicsview.cpp \
    createscenewindow.cpp \
    gun.cpp \
    main.cpp \
    mainscene.cpp \
    mypushbutton.cpp \
    player.cpp \
    playscene.cpp \
    popscene.cpp \
    wall.cpp

HEADERS += \
    bullet.h \
    chooselevelscene.h \
    creategraphicsview.h \
    createscenewindow.h \
    gun.h \
    mainscene.h \
    mypushbutton.h \
    player.h \
    playscene.h \
    popscene.h \
    portal.h \
    wall.h

FORMS += \
    chooselevelscene.ui \
    createscenewindow.ui \
    mainscene.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qss.qrc \
    res.qrc

DISTFILES += \
    res/301922.png \
    res/50271.jpg \
    res/CompanionCube.png \
    res/Cube.png \
    res/MainScene.jpg \
    res/MainScene2.jpg \
    res/PlayerMWG.gif \
    res/PlayerMove.gif \
    res/PlayerStand.png \
    res/Title.png \
    res/WallPaper.png \
    res/back2.png \
    res/bluePortal.png \
    res/cancel1.png \
    res/cancel2.png \
    res/jiaocheng.png \
    res/orgPortal.png \
    res/portal gun.png \
    res/portal gun.png \
    res/quit1.png \
    res/quitScene.png \
    res/start1.png \
    res/start2.png \
    res/wall.png \
    res/youxishuoming.png \
    res/zhucaidan.png
