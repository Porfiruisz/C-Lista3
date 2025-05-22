#include <iostream>
#include <vector>

using namespace std;

/**
 * Funkcja collatz oblicza ci�g Collatza dla podanej liczby c.
 * @param c - liczba pocz�tkowa ci�gu (c0), powinna by� dodatnia.
 * @return wektor kolejnych element�w ci�gu a� do momentu osi�gni�cia 1.
 */
vector<int> collatz(int c) {
    vector<int> wynik;
    if (c <= 0) return wynik;

    wynik.push_back(c);
    while (c != 1) {
        if (c % 2 == 0)
            c /= 2;
        else
            c = 3 * c + 1;
        wynik.push_back(c);
    }
    return wynik;
}

/**
 * Funkcja wypisz wypisuje elementy wektora w formacie [a, b, c, ...].
 * @param dane - referencja do wektora liczb ca�kowitych.
 */
void wypisz(const vector<int>& dane) {
    cout << "[";
    for (int i = 0; i < dane.size(); ++i) {
        cout << dane[i];
        if (i < dane.size() - 1) cout << ", ";
    }
    cout << "]\n";
}

int main() {
    int liczba;
    cout << "Podaj liczbe dodatnia: ";
    cin >> liczba; // Pobiera od u�ytkownika liczb� pocz�tku ci�gu

    vector<int> wynik = collatz(liczba);
    if (wynik.empty()) {
        cout << "Niepoprawna liczba!\n";
    }
    else {
        wypisz(wynik);
    }

    return 0;
}
