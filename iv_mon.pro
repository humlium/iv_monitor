#-------------------------------------------------
#
# Project created by QtCreator 2016-06-24T01:20:07
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = iv_mon
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qmqtt_client_p.cpp \
    qmqtt_client.cpp \
    qmqtt_frame.cpp \
    qmqtt_message_p.cpp \
    qmqtt_message.cpp \
    qmqtt_network.cpp \
    qmqtt_routedmessage.cpp \
    qmqtt_router.cpp \
    qmqtt_routesubscription.cpp \
    qmqtt_socket.cpp \
    qmqtt_ssl_network.cpp \
    qmqtt_ssl_socket.cpp \
    qmqtt_timer.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    qmqtt_client_p.h \
    qmqtt_client.h \
    qmqtt_frame.h \
    qmqtt_global.h \
    qmqtt_message_p.h \
    qmqtt_message.h \
    qmqtt_network.h \
    qmqtt_networkinterface.h \
    qmqtt_routedmessage.h \
    qmqtt_router.h \
    qmqtt_routesubscription.h \
    qmqtt_socket.h \
    qmqtt_socketinterface.h \
    qmqtt_ssl_network.h \
    qmqtt_ssl_socket.h \
    qmqtt_timer.h \
    qmqtt_timerinterface.h \
    qmqtt.h \
    dialog.h

FORMS    += mainwindow.ui \
    dialog.ui
