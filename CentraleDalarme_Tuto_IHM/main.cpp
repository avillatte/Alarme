#include "clavier.h"
#include <QApplication>
#include <iostream>
#include <code.h>
#define TAILLE_CODE 4
using namespace std;



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Clavier w;
    w.show();
    return a.exec();

    Code *leCode;
    leCode = new Code(TAILLE_CODE);
    quint8 combinaison[TAILLE_CODE];
    cout << "Nouveau Code?"<<endl;
    cin >> combinaison[0] >> combinaison[1] >> combinaison[2] >> combinaison[3];
    for (int i = 0; i < TAILLE_CODE; ++i) {
        combinaison[i] -= '0';
    }
    leCode->Memoriser(combinaison);
    cout << "Code?"<<endl;
    cin >> combinaison[0] >> combinaison[1] >> combinaison[2] >> combinaison[3];
    for (int i = 0; i < TAILLE_CODE; ++i) {
        combinaison[i] -= '0';
    }
    bool test = leCode->VerifierCode(combinaison);
    if (test) {
        cout << "Code Valide"<< endl;
    }else
        cout << "Code Non Valide"<< endl;
}
