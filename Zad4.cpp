#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

/**
 * Zwraca wektor pierwszych n element�w ci�gu Fibonacciego.
 * @param n liczba element�w do wygenerowania (musi by� >= 0).
 * @return vector<int> z n elementami ci�gu.
 * @throws invalid_argument je�li n < 0.
 */
vector<int> Fibonacci(int n) {
    if (n < 0) {
        throw invalid_argument("Wartosc n nie moze byc mniejsza od 0");
    }

    if (n == 0) {
        return {};  // pusta lista
    }
    if (n == 1) {
        return { 0 };
    }

    vector<int> wynik = { 0, 1 };

    for (int i = 2; i < n; ++i) {
        wynik.push_back(wynik[i - 1] + wynik[i - 2]);
    }

    return wynik;
}

/**
 * Rekurencyjna funkcja obliczaj�ca n-ty element ci�gu Fibonacciego.
 * @param n indeks elementu (>= 0).
 * @return n-ty element ci�gu.
 * @throws invalid_argument je�li n < 0.
 */
int FibonacciRek(int n) {
    if (n < 0) throw invalid_argument("Wartosc n nie moze byc mniejsza od 0");
    if (n == 0) return 0;
    if (n == 1) return 1;
    return FibonacciRek(n - 1) + FibonacciRek(n - 2);
}

/**
 * Funkcja do wypisywania element�w wektora
 */
void wypisz(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i < v.size() - 1) cout << ", ";
    }
    cout << "]\n";
}

int main() {
    try {
        wypisz(Fibonacci(10));  // [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]
        wypisz(Fibonacci(0));   // []
        wypisz(Fibonacci(1));   // [0]

        // Test z wyj�tkiem
        wypisz(Fibonacci(-5));  // rzuci wyj�tek
    }
    catch (const exception& e) {
        cerr << "Blad: " << e.what() << "\n";
    }
}
