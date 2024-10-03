#ifndef DETECTEURTEMPORISE_H
#define DETECTEURTEMPORISE_H

#include "detecteur.h"

class DetecteurTemporise : public Detecteur
{
public:
    DetecteurTemporise();
    ~DetecteurTemporise();
    void on_pushButtonIntrus_clicked();
    void onTimerTempo_timeout();

private:
    QTimer timerTempo;
};

#endif // DETECTEURTEMPORISE_H
