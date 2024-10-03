#include "detecteur.h"
#include "ui_detecteur.h"
#include <QTimer>

Detecteur::Detecteur(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Detecteur)
{
    ui->setupUi(this);
}

Detecteur::~Detecteur()
{
    delete ui;
}

void Detecteur::on_pushButton_clicked()
{
    QMessageBox messageMarche;
    messageMarche.setText("Il y a un intru");
    messageMarche.exec();
    QWidget* widget = this;
    widget->setStyleSheet("background-color: red");
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [widget = widget]() mutable {
        QString styleSheet = widget->styleSheet();
        if (styleSheet.contains("background-color: red")) {
            widget->setStyleSheet("background-color: transparent");
        } else {
            widget->setStyleSheet("background-color: red");
        }
    });
    timer->start(500);
}

