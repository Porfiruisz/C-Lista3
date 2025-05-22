#include <iostream>
#include <cmath>
#include <stdexcept> // do wyj¹tków

using namespace std;

/**
 * Funkcja obliczaj¹ca pole trójk¹ta na podstawie d³ugoœci boków a, b, c
 * za pomoc¹ wzoru Herona.
 *
 * @param a d³ugoœæ pierwszego boku
 * @param b d³ugoœæ drugiego boku
 * @param c d³ugoœæ trzeciego boku
 * @return pole trójk¹ta
 * @throws invalid_argument jeœli boki s¹ niedodatnie lub nie spe³niaj¹ nierównoœci trójk¹ta
 */
double heron(double a, double b, double c) {
    // Sprawdzenie, czy d³ugoœci boków s¹ dodatnie
    if (a <= 0 || b <= 0 || c <= 0) {
        throw invalid_argument("Dlugosci bokow musza byc dodatnie");
    }

    // Sprawdzenie nierównoœci trójk¹ta
    if ((a + b <= c) || (a + c <= b) || (b + c <= a)) {
        throw invalid_argument("Podane wartosci nie tworza trojkata");
    }

    double q = (a + b + c) / 2.0;
    double P = sqrt(q * (q - a) * (q - b) * (q - c));

    return P;
}

int main() {
    try {
        double testHeron1 = heron(3.0, 4.0, 5.0);
        cout << testHeron1 << endl;
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    try {
        double testHeron2 = heron(-3.0, 4.0, 5.0);
        cout << testHeron2 << endl;
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    try {
        double testHeron3 = heron(30.0, 4.0, 5.0);
        cout << testHeron3 << endl;
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
