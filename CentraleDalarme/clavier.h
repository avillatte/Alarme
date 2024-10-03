#ifndef CLAVIER_H
#define CLAVIER_H
#include <QMessageBox>
#include <QMainWindow>
#include <QTimer>
#include "detecteur.h"
#include "detecteurtempo.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Clavier;
}
QT_END_NAMESPACE

class Clavier : public QMainWindow
{
    Q_OBJECT

public:
    Clavier(QWidget *parent = nullptr);
    ~Clavier();


private slots:
    void on_pushButtonMarche_clicked();
    void TraiterChiffre();
    void onTimerLed_timeout();
    void on_pushButtonArret_clicked();

    void on_pushButton2_clicked();

    void on_pushButton3_clicked();

private:
    Ui::Clavier *ui;
    QTimer timerLed;
    Detecteur *leDetecteur;
    DetecteurTempo *leDetecteurTempo;
};
#endif // CLAVIER_H
