#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtDebug>
#include <QFile>


#define DEV1S "/dev1s"
#define DEV1P "/dev1p"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    client = new QMQTT::Client();
    d = new Dialog();
    state_dev1 = 0;
    ui->statusd1->setText("OFF");


    //mainwindow slots
    connect(client, SIGNAL(connected()), this, SLOT(onMQTT_Connected()));

    //todo: should emit on server suback
    connect(client, SIGNAL(error(QMQTT::ClientError)), this, SLOT(onMQTT_error(QMQTT::ClientError)));

    //slots changes
    //API:  void published(const QMQTT::Message& message);
    connect(client,SIGNAL(published(const QMQTT::Message &)),this,SLOT(onMQTT_Published(const QMQTT::Message &)));

    //todo: should emit on server suback
    connect(client, SIGNAL(received(const QMQTT::Message &)), this, SLOT(onMQTT_Received(const QMQTT::Message &)));
    connect(client, SIGNAL(subscribed(const QString &)), this, SLOT(onMQTT_subscribed(const QString &)));

    //todo: should emit on server suback
    connect(client, SIGNAL(unsubscribed(const QString &)), this, SLOT(onMQTT_unsubscribed(const QString &)));
    //todo: should emit on server suback
    connect(client, SIGNAL(disconnected()), this, SLOT(onMQTT_disconnected()));

    //connect(d, SIGNAL(accepted()), this, SLOT(onReadSetting()));
    connect(d, SIGNAL(updateDat()), this, SLOT(onReadSetting()));

    this->onReadSetting();
    client->setHost(QHostAddress::LocalHost);
    client->setPort(1883);
    client->setClientId("qt1");
    client->connectToHost();


}

MainWindow::~MainWindow()
{
    client->disconnectFromHost();
    delete ui;
}

void MainWindow::onReadSetting()
{
    QFile f("temp.txt");
    if(f.open( QIODevice::ReadOnly | QIODevice::Text )==true){
        QTextStream in(&f);
        QString line = in.readLine();
        QStringList list = line.split(",");
        if(list.length()>=16){
            ui->d1min->display(list[0]);
            ui->d1max->display(list[1]);
            ui->d2min->display(list[2]);
            ui->d2max->display(list[3]);
            ui->d3min->display(list[4]);
            ui->d3max->display(list[5]);
            ui->d4min->display(list[6]);
            ui->d4max->display(list[7]);
            ui->d5min->display(list[8]);
            ui->d5max->display(list[9]);
            ui->d6min->display(list[10]);
            ui->d6max->display(list[11]);
            ui->d7min->display(list[12]);
            ui->d7max->display(list[13]);
            ui->d8min->display(list[14]);
            ui->d8max->display(list[15]);
        }
        f.close();
    }else{
       qDebug() << "miss file";
       QFile f("temp.txt");
       f.open( QIODevice::WriteOnly | QIODevice::Text );
       QTextStream out(&f);
          out << "0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0" << "\n";
       f.close();
    }


}

/* -----------------------------------------------------------
 MQTT Client Slots
 -----------------------------------------------------------*/
void MainWindow::onMQTT_Connected()
{
   qDebug() << "connected";
   client->subscribe(DEV1S, 0);
   client->subscribe(DEV1P, 0);
}

void MainWindow::onMQTT_Connacked(quint8 ack)
{

}

void MainWindow::onMQTT_error(QMQTT::ClientError err)
{

}

void MainWindow::onMQTT_Published(const QMQTT::Message &message)
{

}

void MainWindow::onMQTT_Pubacked(quint8 type, quint16 msgid)
{

}

void MainWindow::onMQTT_Received(const QMQTT::Message &message)
{
    if(message.topic()==DEV1S){
        ui->d1v->display(message.payload().toInt());
    }
    qDebug() << QString::fromUtf8(message.payload());
}

void MainWindow::onMQTT_subscribed(const QString &topic)
{
   qDebug() << topic;
}

void MainWindow::onMQTT_subacked(quint16 msgid, quint8 qos)
{

}

void MainWindow::onMQTT_unsubscribed(const QString &topic)
{

}

void MainWindow::onMQTT_unsubacked(quint16 msgid)
{

}

void MainWindow::onMQTT_Pong()
{

}

void MainWindow::onMQTT_disconnected()
{
    qDebug() << "disconnected";
}

void MainWindow::on_pushButton_clicked()
{
    QMQTT::Message message(0, DEV1S, "44");
    client->publish(message);
    d->show();
}
