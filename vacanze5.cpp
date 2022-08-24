#include <iostream>
#include <fstream>
//Esercizio 27 pag A248 del libro
//21/07/2022
const int MAX_ORIZZONTALE = 10;
const int MAX_VERTICALE = 10;
using namespace std;
struct calcolo {
    int navi1 = 0, navi2 = 0, navi3 = 0, tot = 0;
};
calcolo colpo(int x, int y, string mappa[MAX_ORIZZONTALE][MAX_VERTICALE]) {
    calcolo punti;
    if (mappa[x][y] == "1") {
        cout << x << " " << y << endl;
        mappa[x][y] = "0";
        punti.navi1++;
        punti.tot++;
    }
    if (mappa[x][y] == "2") {
        cout << x << " " << y << endl;
        mappa[x][y] = "0";
        punti.navi2++;
        punti.tot++;
    }
    if (mappa[x][y] == "3") {
        cout << x << " " << y << endl;
        mappa[x][y] = "0";
        punti.navi3++;
        punti.tot++;
    }
    return punti;
}
int main() {
    ifstream in;
    in.open("Navi.txt");
    if (!in) {
        cout << "Errore nell'apertura del file" << endl;
        return 1;
    }
    string mappa[MAX_ORIZZONTALE][MAX_VERTICALE];
    for (int i = 0; i < MAX_VERTICALE; ++i) {
        for (int j = 0; j < MAX_ORIZZONTALE; ++j) {
            in >> mappa[j][i];
        }
    }
in.close();
    ifstream in2;
    in2.open("Colpi.txt");
    if (!in2) {
        cout << "Errore nell'apertura del file" << endl;
        return 2;
    }
    string colpi;
    calcolo punti, totale;
    bool ritmo = false;
    bool ritmo2 = false;
    while (in2 >> colpi) {
        int x,y;
        ritmo = !ritmo;
        if (ritmo)
            x = stoi(colpi);
        if(!ritmo) {
            y = stoi(colpi);
            ritmo2 = !ritmo2;
        }
        if (ritmo2) {
            punti = colpo(x-1,y-1,mappa);
            totale.navi1 += punti.navi1;
            totale.navi2 += punti.navi2;
            totale.navi3 += punti.navi3;
            totale.tot += punti.tot;
            ritmo2 = !ritmo2;
        }


    }
    cout << "Fine del gioco" << endl;
    cout << "Di seguente verranno mostrati i punteggi" << endl;
    cout << "Il numero di punti totali e di " << totale.tot << endl;
    if (totale.navi1 == 1) {
        cout << "La nave 1 e stata affondata" << endl;
    }
    if (totale.navi2 == 2) {
        cout << "La nave 2 e stata affondata" << endl;
    }
    if (totale.navi3 == 3) {
        cout << "La nave 3 e stata affondata" << endl;
    }
    if (totale.navi1 != 1 && totale.navi2 != 2 && totale.navi3 != 3) {
        cout << "Nessuna nave e stata affondata" << endl;
    }
    return 0;
}
