#include <iostream>
#include <fstream>
// 14/07/2022
// Es 26 p A248
using namespace std;
int main() {
    ifstream in;
    ofstream out;
    in.open("input.txt");
    if (!in) {
        cout << "Apertura file non riuscita" << endl;
        return 1;
    }
    string minuscole;
    string maiuscole;
    while (in >> minuscole) {
        int giri = 0;
        giri++;
        for (int i = 0; i < giri; ++i) {
            for (int j = 0; j < minuscole.size(); ++j) {
                maiuscole += toupper(minuscole.at(j));

                cout << endl;
            }
            maiuscole += " ";
        }
    }
    out.open("output.txt");
    if (!out) {
        cout << "Apertura file non riuscita" << endl;
        return 2;
    }
    out << maiuscole;
    in.close();
    out.close();
    return 0;
}
