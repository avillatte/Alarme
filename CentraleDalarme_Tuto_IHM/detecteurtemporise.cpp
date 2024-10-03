#include "detecteurtemporise.h"

DetecteurTemporise::DetecteurTemporise() {

    setWindowTitle("Détecteur Temporisé");
    connect(&timerTempo,&QTimer::timeout,this,&DetecteurTemporise::onTimerTempo_timeout);
}

DetecteurTemporise::~DetecteurTemporise()
{
    timerTempo.stop();
}

void DetecteurTemporise::on_pushButtonIntrus_clicked()
{
    timerTempo.start(3000);
}

void DetecteurTemporise::onTimerTempo_timeout()
{
    QMessageBox messageMarche;
    messageMarche.setText("Un intrus a été détecté");
    messageMarche.exec();
    timerTempo.stop();
}
