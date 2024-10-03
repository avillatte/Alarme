#include "clavier.h"
#include "ui_clavier.h"

Clavier::Clavier(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Clavier),
    leDetecteur(nullptr),
    leDetecteurTemporise(nullptr)
{
    ui->setupUi(this);
    connect(ui->pushButton_0,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton_1,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton_3,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton_4,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton_5,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton_6,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton_7,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton_8,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton_9,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(&timerLed,&QTimer::timeout,this,&Clavier::onTimerLed_timeout);
}

Clavier::~Clavier()
{
    delete ui;
}

void Clavier::on_pushButtonMarche_clicked()
{
    /*
    QMessageBox messageMarche;
    messageMarche.setText("j'ai appuyé sur Marche");
    messageMarche.exec();

    QString texteBouton = ui->pushButtonMarche->text();
    QMessageBox messageMarche;
    messageMarche.setText("j'ai appuyé sur la touche " + texteBouton);
    messageMarche.exec();
*/
    timerLed.start(500);
}

void Clavier::TraiterChiffre()
{
    /*
    QPushButton *pbouton = static_cast<QPushButton *>(sender());
    QString texteBouton = pbouton->text();
    QMessageBox messageChiffre;
    messageChiffre.setText("j'ai appuyé sur la touche " + texteBouton);
    messageChiffre.exec();
*/
}

void Clavier::onTimerLed_timeout()
{
    if(ui->checkBoxLedRouge->checkState() == Qt::Checked)
        ui->checkBoxLedRouge->setCheckState(Qt::Unchecked);
    else
        ui->checkBoxLedRouge->setCheckState(Qt::Checked);
}


void Clavier::on_pushButtonArret_clicked()
{
    timerLed.stop();
    ui->checkBoxLedRouge->setCheckState(Qt::Unchecked);
}

void Clavier::on_pushButton_2_clicked()
{
    leDetecteur = new Detecteur;
    leDetecteur->show();
}

void Clavier::on_pushButton_3_clicked()
{
    if (leDetecteur != nullptr) {
        leDetecteur->hide();
        delete leDetecteur;
        leDetecteur = nullptr;
    }
}


void Clavier::on_pushButton_4_clicked()
{
    leDetecteurTemporise = new DetecteurTemporise;
    leDetecteurTemporise->show();
}


void Clavier::on_pushButton_5_clicked()
{
    if (leDetecteurTemporise != nullptr) {
        leDetecteurTemporise->hide();
        delete leDetecteurTemporise;
        leDetecteurTemporise = nullptr;
    }
}

