#include "clavier.h"
#include "ui_clavier.h"

Clavier::Clavier(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Clavier)
{
    ui->setupUi(this);
    QList<QPushButton*> allButtons = this->findChildren<QPushButton*>();
    foreach(QPushButton* button, allButtons) {
        if(button->text() != "Marche" && button->text() != "Arrêt" && button->text() != "2" && button->text() != "Quitter le menu" && button->text() != "4") {
            connect(button, &QPushButton::clicked, this, &Clavier::TraiterChiffre);

        }
    }
    connect(&timerLed,&QTimer::timeout,this,&Clavier::onTimerLed_timeout);
}

Clavier::~Clavier()
{
    delete ui;
}

void Clavier::on_pushButton_Marche_clicked()
{
    // QMessageBox messageMarche;
    // messageMarche.setText("j'ai appuyé sur Marche");
    // messageMarche.exec();
    ui->checkBox_Rouge->setCheckState(Qt::Checked);
    timerLed.start(500);
}

void Clavier::TraiterChiffre()
{
    QPushButton *pbouton = static_cast<QPushButton *>(sender());
    QString texteBouton = pbouton->text();
    QMessageBox messageChiffre;
    messageChiffre.setText("j'ai appuyé sur la touche " + texteBouton);
    messageChiffre.exec();
}

void Clavier::onTimerLed_timeout()
{
    if(ui->checkBox_Rouge->checkState() == Qt::Checked)
        ui->checkBox_Rouge->setCheckState(Qt::Unchecked);
    else
        ui->checkBox_Rouge->setCheckState(Qt::Checked);
}





void Clavier::on_pushButton_arret_clicked()
{
     ui->checkBox_Rouge->setCheckState(Qt::Unchecked);
    timerLed.stop();
}


void Clavier::on_pushButton2_clicked()
{
    leDetecteur = new Detecteur;
    leDetecteur->show();
}


void Clavier::on_pushButton3_clicked()
{
    if (leDetecteur != nullptr) {
        leDetecteur->hide();
        delete leDetecteur;
        leDetecteur = nullptr;
    }

}


void Clavier::on_pushButton4_clicked()
{
    leDetecteurTempo = new DetecteurTemporise;
    leDetecteurTempo->show();

}


void Clavier::on_pushButton5_clicked()
{

    if (leDetecteurTempo != nullptr) {
        leDetecteurTempo->hide();
        delete leDetecteurTempo;
        leDetecteurTempo = nullptr;
    }
}

