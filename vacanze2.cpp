// Esercizio 21 p. A247 12/07/2022
#include <iostream>
#include <fstream>
using namespace std;
int main() {
    const int MAX = 100000;
    int numeri[MAX], counter = 0;
    cin >> numeri[counter];
    while (numeri[counter] != 0) {
        counter++;
        cin >> numeri[counter];

    }
ofstream out;
    out.open("multipli5.txt");
    for (int i = 0; i < counter; ++i) {
        if (numeri[i] % 5 == 0) {
            out << numeri[i] << " " << endl;
        }
    }
    out.close();

    return 0;
}
