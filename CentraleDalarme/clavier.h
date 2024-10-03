#ifndef CLAVIER_H
#define CLAVIER_H

#include <QWidget>
#include <QMessageBox>
#include <QTimer>
#include <detecteur.h>
#include <detecteurtemporise.h>
QT_BEGIN_NAMESPACE
namespace Ui {
class Clavier;
}
QT_END_NAMESPACE

class Clavier : public QWidget
{
    Q_OBJECT

public:
    Clavier(QWidget *parent = nullptr);
    ~Clavier();

private slots:
    void on_pushButton_Marche_clicked();
    void TraiterChiffre();
    void onTimerLed_timeout();
    void on_pushButton_arret_clicked();

    void on_pushButton2_clicked();

    void on_pushButton3_clicked();

    void on_pushButton4_clicked();

    void on_pushButton5_clicked();

private:
    Ui::Clavier *ui;
    QTimer timerLed;
    QTimer timerIntru;
    Detecteur *leDetecteur;
    DetecteurTemporise *leDetecteurTempo;
};
#endif // CLAVIER_H
