#include "detecteurtemporise.h"

DetecteurTemporise::DetecteurTemporise() {
    connect(&timerIntru,&QTimer::timeout,this,&DetecteurTemporise::onTimerIntru_timeout);
    timerIntru.setSingleShot(true);
}

void DetecteurTemporise::on_pushButton_clicked()
{
    timerIntru.start(1000);

}

void DetecteurTemporise::onTimerIntru_timeout()
{
    QMessageBox messageIntru;
    messageIntru.setText("Un intru a été détecté. " );
    messageIntru.exec();

}


