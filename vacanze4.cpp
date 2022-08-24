#include <iostream>
#include <fstream>
#include <sstream> //stoi() mi stava dando problemi e ho trovato su internet un metodo alternativo
//  18/07/2022
// Es 29 pag A248 libro di testo (livello successivo dell' es 15 pag A191 svolto in precedenza)

using namespace std;
struct libro
        {
    string codice,titolo,autore, editore;
    int anno;
};
const int MAX = 10000;
void scelta(int &a) {
    string pezza;
    cout << "Inserire la scelta:" << endl;
    cout << " 0) Chiudi il programma" << endl;
    cout << " 1) Aggiungi un nuovo libro alla collezione" << endl;
    cout << " 2) Visualizza i libri nella collezione " << endl;
    cout << " 3) Visualizza le informazioni di un libro specifico a partire dal codice" << endl;
    cout << " 4)  Visualizza le informazioni di un libro specifico a partire dal titolo" << endl;
    cout << " 5) Creazione di un file di testo contenente l'intera collezione" << endl;
    cout << " 6) Inserimento libri tramite file " << endl;
    do {
        cin >> a;
    } while (a < 0 || a > 6);
    getline(cin, pezza);
}
void aggiungi(libro a[MAX], int aggiunti) {
    string pezza;
    cout << "Inserisci le informazioni del libro numero " << aggiunti + 1 << endl;
    cout << "Inserisci il titolo: ";
    getline(cin, a[aggiunti].titolo);
    cout << "Inserisci il codice: ";
    getline( cin, a[aggiunti].codice);
    cout << "Inserisci l'autore: ";
    getline(cin , a[aggiunti].autore);
    cout << "Inserisci l'editore: ";
    getline(cin , a[aggiunti].editore);
    cout << "Inserisci l'anno di pubblicazione: ";
    cin >> a[aggiunti].anno;
    getline(cin, pezza);
}
void show(libro a[MAX], int aggiunti) {
    for (int i = 0; i < aggiunti; ++i) {
        cout << a[i].titolo << endl;
        cout << a[i].anno << endl;
        cout << a[i].autore << endl;
        cout << a[i].editore << endl;
        cout << a[i].codice << endl;
        cout <<  "------------------" << endl;
    }
}
void ricerca_codice(libro a[MAX], string codice, int aggiunti) {
    for (int i = 0; i < aggiunti; ++i) {
        if ( codice == a[i].codice) {
            cout << a[i].titolo << endl;
            cout << a[i].anno << endl;
            cout << a[i].autore << endl;
            cout << a[i].editore << endl;
            cout << "--------------" << endl;
        }
    }
}
void ricerca_titolo(libro a[MAX], string titolo, int aggiunti) {
    for (int i = 0; i < aggiunti; ++i) {
        if ( titolo == a[i].titolo) {
            cout << a[i].anno << endl;
            cout << a[i].autore << endl;
            cout << a[i].editore << endl;
            cout << a[i].codice << endl;
            cout << "--------------" << endl;
        }
    }
}
int main() {
    libro biblioteca[MAX];
    int a, aggiunti = 0;

    scelta(a);

    while (a != 0) {
        if (a == 1) {
            aggiungi(biblioteca, aggiunti);
            aggiunti++;
        }
        if ( a == 2) {
            show(biblioteca, aggiunti);
        }
        if ( a == 3) {
            string codice;
            cout << "Inserisci il codice da ricercare" << endl;
            getline(cin, codice);
            ricerca_codice(biblioteca, codice, aggiunti);
        }
        if ( a == 4) {
            string titolo;
            cout << "Inserisci il titolo da ricercare" << endl;
            getline(cin, titolo);
            ricerca_titolo(biblioteca, titolo, aggiunti);
        }
        if ( a == 5) {
            ofstream out;
            out.open("collezione.txt");
            if (!out) {
                cout << "Errore nell'apertura del file di output" << endl;
                return 1;
            }
            string collezione;
            for (int i = 0; i < aggiunti; ++i) {
                collezione += biblioteca[i].titolo;
                collezione += "|";
                collezione += biblioteca[i].codice;
                collezione += "|";
                collezione += biblioteca[i].editore;
                collezione += "|";
                collezione += biblioteca[i].autore;
                collezione += "|";
                stringstream conv;
                conv << biblioteca[i].anno;
                string anno = conv.str();
                collezione += anno;
                collezione += "|";
                out << collezione;
                out << endl;
                collezione.clear();
            }


        }
        if ( a == 6) {
            ifstream in;
            in.open("input.txt");
            if (!in) {
                cout << "Errore nell'apertura del file di input " << endl;
                return 2;
            }
            string insert;

            bool finito = false;
            while (!finito) {
                getline(in, insert);
                if (insert.empty()) {
                    finito = true;
                }
                if (!finito) {
                    biblioteca[aggiunti].titolo = insert.substr(0, insert.find('|', 0));
                    insert.erase(0, insert.find('|')+1);
                    // Ho perso un ora cercando un errore ma mi ero semplicemente dimenticato di mettere il +1
                    biblioteca[aggiunti].codice = insert.substr(0, insert.find('|', 0));
                    insert.erase(0, insert.find('|')+1);
                    biblioteca[aggiunti].editore = insert.substr(0, insert.find('|', 0));
                    insert.erase(0, insert.find('|')+1);
                    biblioteca[aggiunti].autore = insert.substr(0, insert.find('|', 0));
                    insert.erase(0, insert.find('|')+1);
                    stringstream container(insert.substr(0, insert.find('|', 0)));
                    container >> biblioteca[aggiunti].anno;
                    insert.erase(0, insert.find('|')+1);
                    aggiunti++;
                }
            }
// Stavo provando a farlo in questo modo ma ho capito che non avrebbe funzionato poiché avrebbe letto i nomi dei libri in input separati
            /*int ciclo = -1;
            while (in >> insert) {
                ciclo++;
                    if (ciclo == 0) {
                        biblioteca[aggiunti].titolo = insert;
                    }
                    if (ciclo == 1) {
                        biblioteca[aggiunti].codice = insert;
                    }
                    if (ciclo == 2) {
                        biblioteca[aggiunti].editore = insert;
                    }
                    if (ciclo == 3) {
                        biblioteca[aggiunti].autore = insert;
                    }
                    if (ciclo == 4) {
                        biblioteca[aggiunti].anno = stoi(insert);
                        aggiunti++;
                        ciclo=-1;
                    }
                    insert.clear();

            }
             */
        }
        scelta(a);
    }
    return 0;
}
