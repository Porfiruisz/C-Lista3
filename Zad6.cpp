#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stdexcept>

using namespace std;

// Funkcja zwracająca komplement jednego nukleotydu
char komplementujZnak(char znak) {
    switch (znak) {
    case 'A': return 'T';
    case 'T': return 'A';
    case 'C': return 'G';
    case 'G': return 'C';
    default: throw invalid_argument(string("Nieprawidlowy znak w sekwencji DNA: ") + znak);
    }
}

/**
 * @brief Zwraca odwrotną i komplementarną nić matrycową DNA dla fragmentu nici kodującej,
 * wyodrębnionego pomiędzy kodonem start (ATG) a najbliższym kodonem stop (TAA, TAG, TGA).
 *
 * @param dna Sekwencja nici kodującej DNA (5'→3')
 * @return Nić matrycowa DNA (3'→5') — odwrotna i komplementarna do fragmentu z dna
 * @throws invalid_argument jeśli brak kodonu start/stop lub występują nieprawidłowe znaki
 */
string komplement(const string& dna) {
    size_t startIndex = dna.find("ATG");
    if (startIndex == string::npos) {
        throw invalid_argument("Brak kodonu startowego ATG w sekwencji DNA");
    }

    vector<string> stopCodons = { "TAA", "TAG", "TGA" };
    size_t endIndex = dna.size();
    for (const auto& codon : stopCodons) {
        size_t stopIndex = dna.find(codon, startIndex + 3);
        if (stopIndex != string::npos && stopIndex < endIndex) {
            endIndex = stopIndex;
        }
    }

    if (endIndex == dna.size()) {
        throw invalid_argument("Brak kodonu stop w sekwencji DNA");
    }

    string wynik;
    for (int i = endIndex - 1; i >= static_cast<int>(startIndex); --i) {
        wynik += komplementujZnak(dna[i]);
    }

    return wynik;
}

// Funkcja zamienia A->U (transkrypcja z nici matrycowej)
string transkrybuj(const string& dna) {
    string wynik = dna;
    for (char& znak : wynik) {
        if (znak == 'A') znak = 'U';
        if (znak == 'T') znak = 'A';
        if (znak == 'C') znak = 'G';
        if (znak == 'G') znak = 'C';
    }
    return wynik;
}

int main() {
    try {
        string test1 = komplement("CATGGGCTGATTTGAA");
        cout << "Nic matrycowa: " << test1 << endl;

        string test11 = transkrybuj(test1);
        cout << "mRNA: " << test11 << endl;

        // string test2 = komplement("GGCTGATTT"); // wyjątek: brak ATG
        // string test3 = komplement("ATGGGCGTTT"); // wyjątek: brak kodonu stop
        // string test4 = komplement("CATGGGCTQATTTGAA"); // wyjątek: nieprawidłowy znak Q

    }
    catch (const exception& e) {
        cerr << "Wyjatek: " << e.what() << endl;
    }

    return 0;
}