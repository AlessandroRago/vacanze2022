#include <iostream>
#include <ctime>

using namespace std;
const int VERTICALE = 5, ORIZZONTALE = 5;

//30/08/2022
//Esercizio trovato su internet sulle matrici (qui sotto il testo)
//Una matrice 5×5 rappresenta il numero di punti realizzati da dei giocatori di basket in un piccolo torneo, in ogni riga c’è il totale dei punti realizzati da un
// giocatore in per ogni partita, in ogni colonna ci sono i punti realizzati dai giocatori in una specifica partita.
//Stampare il numero di punti realizzati nella partita in cui sono stati fatti più punti dal giocatore che nel totale delle partite ha realizzato più punti.
//(Per semplicità si consideri che non ci siano giocatori con lo stesso numero di punti o partite con lo stesso numero di punti totali).
void punti_iniziali(int tabella[ORIZZONTALE][VERTICALE]) {
    tabella[0][0] = 21;
    tabella[1][0] = 18;
    tabella[2][0] = 8;
    tabella[3][0] = 10;
    tabella[4][0] = 16;

    tabella[0][1] = 7;
    tabella[1][1] = 10;
    tabella[2][1] = 8;
    tabella[3][1] = 5;
    tabella[4][1] = 12;

    tabella[0][2] = 26;
    tabella[1][2] = 31;
    tabella[2][2] = 28;
    tabella[3][2] = 42;
    tabella[4][2] = 38;

    tabella[0][3] = 16;
    tabella[1][3] = 22;
    tabella[2][3] = 15;
    tabella[3][3] = 18;
    tabella[4][3] = 17;

    tabella[0][4] = 30;
    tabella[1][4] = 25;
    tabella[2][4] = 18;
    tabella[3][4] = 33;
    tabella[4][4] = 21;

}
int main() {

    int tabella[ORIZZONTALE][VERTICALE], partita = 0, giocatore = 0, maggiore_g = 0, maggiore_p = 0, top = 0,x, y;
    punti_iniziali(tabella);
    for (int i = 0; i < VERTICALE; ++i) {

        for (int j = 0; j < ORIZZONTALE; ++j) {
            partita = tabella[i][j] + partita;
            giocatore = tabella[j][i] + giocatore;
            if (giocatore > maggiore_g) {

                maggiore_g = giocatore;
                y = i;
            }
            if (partita > maggiore_p) {
                maggiore_p = partita;
                x = i;
            }


        }

        giocatore = 0;
        partita = 0;

    }
    cout << "Giocatore " << maggiore_g << endl;
    cout << "Partita " << maggiore_p << endl;
    cout << "Punti del giocatore con piu punti totali nella partita con piu punti " << tabella[x][y] << endl;

    return 0;
}
//Questo problema era fondamentalmente semplice ma ci ho messo un intera giornata (ho iniziato di mattina e ho finito adesso che sono le 22:41)
// perché sono stupido e stavo cercando di farlo in modi estremamente complicati semplicemente perché avevo sbagliato la ricerca delle cordinate nella tabella
// inizialmente. GG