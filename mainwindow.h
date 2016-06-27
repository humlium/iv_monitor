#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"
#include "qmqtt.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onMQTT_Connected();
    void onMQTT_Connacked(quint8 ack);
    void onMQTT_error(QMQTT::ClientError err);
    //slots changes
    //API:  void published(const QMQTT::Message& message);
    void onMQTT_Published(const QMQTT::Message &message);
    void onMQTT_Pubacked(quint8 type, quint16 msgid);
    void onMQTT_Received(const QMQTT::Message &message);
    void onMQTT_subscribed(const QString &topic);
    void onMQTT_subacked(quint16 msgid, quint8 qos);
    void onMQTT_unsubscribed(const QString &topic);
    void onMQTT_unsubacked(quint16 msgid);
    void onMQTT_Pong();
    void onMQTT_disconnected();
    void onReadSetting();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QMQTT::Client *client;
    Dialog *d;
    int state_dev1;
};

#endif // MAINWINDOW_H
