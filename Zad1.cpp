#include <iostream>
#include <cmath>
#include <stdexcept> // do wyj�tk�w

using namespace std;

/**
 * Funkcja obliczaj�ca pole tr�jk�ta na podstawie d�ugo�ci bok�w a, b, c
 * za pomoc� wzoru Herona.
 *
 * @param a d�ugo�� pierwszego boku
 * @param b d�ugo�� drugiego boku
 * @param c d�ugo�� trzeciego boku
 * @return pole tr�jk�ta
 * @throws invalid_argument je�li boki s� niedodatnie lub nie spe�niaj� nier�wno�ci tr�jk�ta
 */
double heron(double a, double b, double c) {
    // Sprawdzenie, czy d�ugo�ci bok�w s� dodatnie
    if (a <= 0 || b <= 0 || c <= 0) {
        throw invalid_argument("Dlugosci bokow musza byc dodatnie");
    }

    // Sprawdzenie nier�wno�ci tr�jk�ta
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
