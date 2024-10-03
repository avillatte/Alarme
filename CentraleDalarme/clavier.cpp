#include "clavier.h"
#include "ui_clavier.h"

Clavier::Clavier(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::Clavier),
    leDetecteur(nullptr),
    leDetecteurTempo(nullptr)
{
    ui->setupUi(this);
    // connect(ui->pushButton0,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    // connect(ui->pushButton1,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    // connect(ui->pushButton2,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    // connect(ui->pushButton3,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    // connect(ui->pushButton4,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    // connect(ui->pushButton5,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    // connect(ui->pushButton6,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    // connect(ui->pushButton7,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    // connect(ui->pushButton8,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    // connect(ui->pushButton9,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(&timerLed,&QTimer::timeout,this,&Clavier::onTimerLed_timeout);
    QList<QPushButton*> allButtons = this->findChildren<QPushButton*>();
    foreach(QPushButton* button, allButtons) {
        if(button->text() != "Marche") {
            connect(button, &QPushButton::clicked, this, &Clavier::TraiterChiffre);
        }
    }
}

Clavier::~Clavier()
{
    delete ui;
}

void Clavier::onTimerLed_timeout()
{
    if(ui->checkBoxRouge->checkState() == Qt::Checked)

        ui->checkBoxRouge->setCheckState(Qt::Unchecked);

    else
        ui->checkBoxRouge->setCheckState(Qt::Checked);
}



void Clavier::on_pushButtonMarche_clicked()
{
    // QString texteBouton = ui->pushButtonMarche->text();
    // QMessageBox messageMarche;
    // messageMarche.setText("j'ai appuyé sur la touche " + texteBouton);
    // messageMarche.exec();
    ui->checkBoxRouge->setCheckState(Qt::Checked);
    timerLed.start(500);
}

void Clavier::TraiterChiffre()
{
    // QPushButton *pbouton = static_cast<QPushButton *>(sender());
    // QString texteBouton = pbouton->text();
    // QMessageBox messageChiffre;
    // messageChiffre.setText("j'ai appuyé sur la touche " + texteBouton);
    // messageChiffre.exec();
}

void Clavier::on_pushButtonArret_clicked()
{
    ui->checkBoxRouge->setCheckState(Qt::Unchecked);
    timerLed.stop();
}


void Clavier::on_pushButton2_clicked()
{
    leDetecteur = new Detecteur;
    leDetecteur->show();
}


void Clavier::on_pushButton3_clicked()
{
    if(leDetecteur != nullptr)
    {
    leDetecteur->hide();
    delete leDetecteur;
    leDetecteur = nullptr;
    }
}

