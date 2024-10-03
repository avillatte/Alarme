#ifndef DETECTEURTEMPORISE_H
#define DETECTEURTEMPORISE_H
#include <QTimer>
#include "detecteur.h"

class DetecteurTemporise : public Detecteur
{
public:
    DetecteurTemporise();
    ~DetecteurTemporise();
private slots:
    void on_pushButton_clicked();
    void onTimerIntru_timeout();
private:

    QTimer timerIntru;
};

inline DetecteurTemporise::~DetecteurTemporise()
{

}

#endif // DETECTEURTEMPORISE_H
