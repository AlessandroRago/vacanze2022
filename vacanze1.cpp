#include <iostream>
// 08/07/2022
// Esercizio 15 pag A191 libro
using namespace std;
struct libro{
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
    do {
        cin >> a;
    } while (a < 0 || a > 4);
    getline(cin, pezza);
}
void aggiungi(libro a[MAX], int aggiunti) {
    string pezza;
    cout << "Inserisci le informazioni del libro numero " << aggiunti + 1 << endl;
    cout << "Inserisci il codice: ";
    getline( cin, a[aggiunti].codice);
    cout << "Inserisci il titolo: ";
    getline(cin, a[aggiunti].titolo);
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
        scelta(a);
        }
    return 0;
}
