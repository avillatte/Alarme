#ifndef DETECTEUR_H
#define DETECTEUR_H

#include <QDialog>
#include<QMessageBox>
namespace Ui {
class Detecteur;
}

class Detecteur : public QDialog
{
    Q_OBJECT

public:
    explicit Detecteur(QWidget *parent = nullptr);
    ~Detecteur();

protected slots:
    virtual void on_pushButton_clicked();

private:
    Ui::Detecteur *ui;
};

#endif // DETECTEUR_H
