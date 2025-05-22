#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

/**
 * Funkcja zwraca czêœæ wspóln¹ dwóch multizbiorów x i y.
 * Zachowuje liczbê powtórzeñ elementów, które wystêpuj¹ w obu multizbiorach.
 *
 * @param x - pierwszy multizbiór
 * @param y - drugi multizbiór
 * @return wektor zawieraj¹cy czêœæ wspóln¹ multizbiorów
 *
 * @throws invalid_argument jeœli którykolwiek z argumentów jest pusty
 */
vector<int> wspolne(const vector<int>& x, const vector<int>& y) {
    if (x.empty() || y.empty()) {
        throw invalid_argument("Argumenty nie moga byc puste");
    }

    vector<int> wynik;
    vector<bool> uzyteY(y.size(), false);

    for (size_t i = 0; i < x.size(); ++i) {
        for (size_t j = 0; j < y.size(); ++j) {
            if (!uzyteY[j] && x[i] == y[j]) {
                wynik.push_back(x[i]);
                uzyteY[j] = true;
                break;
            }
        }
    }

    return wynik;
}

void wypisz(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    try {
        vector<int> m1 = { 1, 2, 2, 2, 4, 4, 5, 6 };
        vector<int> m2 = { 2, 2, 3, 4, 4, 4, 6, 6 };
        wypisz(wspolne(m1, m2));

        vector<int> m3 = { 1, 1, 1, 1, 1 };
        vector<int> m4 = { 0 };
        wypisz(wspolne(m3, m4));

        vector<int> m5;  // pusty wektor, ¿eby pokazaæ wyj¹tek
        vector<int> m6 = { 1 };
        wypisz(wspolne(m5, m6));
    }
    catch (const invalid_argument& e) {
        cerr << "Blad: " << e.what() << endl;
    }

    return 0;
}
