#include "dialog.h"
#include "ui_dialog.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{

    QFile f("temp.txt");
    f.open( QIODevice::WriteOnly | QIODevice::Text );
    QTextStream out(&f);
       out << ui->d1min->value() << "," << ui->d1max->value() << ","
           << ui->d2min->value() << "," << ui->d2max->value() << ","
           << ui->d3min->value() << "," << ui->d3max->value() << ","
           << ui->d4min->value() << "," << ui->d4max->value() << ","
           << ui->d5min->value() << "," << ui->d5max->value() << ","
           << ui->d6min->value() << "," << ui->d6max->value() << ","
           << ui->d7min->value() << "," << ui->d7max->value() << ","
           << ui->d8min->value() << "," << ui->d8max->value() << "\n";
    f.close();
    this->close();
    emit updateDat();
    this->close();

}

void Dialog::on_buttonBox_rejected()
{
    this->close();
}
