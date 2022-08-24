#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
// 24/08/2022
// Es 28 pag A248 del libro
using namespace std;
const int MAX = 10000;
 struct studente {
    string cognome,nome,matricola,eta;
    int voto;
};
 /*
 Il programma ha dei problemi se uno studente ha un nome doppio o un cognome doppio, però non saprei come risolvere questo problema.
*/
int numero_righe() {
    ifstream in("Risultati.txt");
    if (!in) {
        cout << "Errore nell'apertura del file nella funzione" << endl;
        return 2;
    }
    string stringa;
    int contatore = 0;
    while (in >> stringa) {
        contatore++;
    }
    return contatore/5;
}
int main() {
ifstream in("Risultati.txt");
if (!in) {
    cout << "Errore nell'apertura del file" << endl;
    return 1;
}
ofstream out("Risultati_ordinati.txt");
if (!out) {
    cout << "Errore nell'apertura del file" << endl;
    return 2;
}
studente vuoto;
vuoto.voto = -1;
studente classe[MAX];
string risultati[MAX];
string ordinati;
int numero = numero_righe();
int voti[MAX];
    for (int i = 0; i < numero; ++i) {
        getline(in,risultati[i]);
        for (int j = 0; j < 5; ++j) {
            if ( j == 1) {
            classe[i].cognome = risultati[i].substr(0, risultati[i].find(' '));
            risultati[i].erase(0, risultati[i].find(' ')+1);

                }
            if ( j == 2) {
                classe[i].nome = risultati[i].substr(0, risultati[i].find(' '));
                risultati[i].erase(0, risultati[i].find(' ')+1);

            }
            if ( j == 3) {
                classe[i].matricola = risultati[i].substr(0, risultati[i].find(' '));
                risultati[i].erase(0, risultati[i].find(' ')+1);

            }
            if ( j == 4) {
                classe[i].eta = risultati[i].substr(0, risultati[i].find(' '));
                risultati[i].erase(0, risultati[i].find(' ')+1);

            }



        }
        classe[i].voto = stoi(risultati[i]);
        voti[i] = classe[i].voto;
        risultati[i].clear();
    }
    sort(voti,voti+numero, greater<>()); //Metodo trovato su internet
    for (int i = 0; i < numero; ++i) {
        for (int j = 0; j < numero; ++j) {
            if (voti[i] == classe[j].voto) {
                stringstream ss; //Metodo che ho utilizzato già in precedenza e che ho sempre trovato su internet
                ss <<  classe[j].voto;
                ordinati = classe[j].cognome + " " + classe[j].nome + " " + classe[j].matricola + " " + classe[j].eta + " " + ss.str() + " ";
                out << ordinati << endl;
                classe[j] = vuoto;
            }
        }
    }
in.close();
out.close();
    return 0;
}
