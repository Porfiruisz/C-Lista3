#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

/**
 * Funkcja zwraca wszystkie podzbiory zadanego zbioru.
 * Zwraca vector zawieraj¹cy sety bêd¹ce podzbiorami zbioru wejœciowego,
 * ³¹cznie z podzbiorem pustym.
 *
 * @param zbior Wejœciowy zbiór elementów.
 * @return vector wszystkich podzbiorów zbioru.
 */
template <typename T>
vector<set<T>> podzbiory(const set<T>& zbior) {
    vector<T> lista(zbior.begin(), zbior.end());
    int n = lista.size();
    vector<set<T>> wynik;

    int liczbaKombinacji = pow(2, n);

    for (int i = 1; i < liczbaKombinacji; ++i) {
        set<T> podzbior;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                podzbior.insert(lista[j]);
            }
        }
        wynik.push_back(podzbior);
    }

    return wynik;
}

template <typename T>
void wypisz(const vector<set<T>>& zbiory) {
    cout << "[\n";
    for (const auto& zb : zbiory) {
        cout << "  { ";
        for (const auto& el : zb) {
            cout << el << " ";
        }
        cout << "}\n";
    }
    cout << "]\n";
}

int main() {
    set<char> test1 = { 'A', 'B', 'C' };
    wypisz(podzbiory(test1));

    set<int> test2 = { 1, 2, 3 };
    wypisz(podzbiory(test2));

    return 0;
}
