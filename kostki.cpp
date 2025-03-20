#include <iostream>
#include <ctime>

using namespace std;

class GraWKosci {
private:
    int kostki[5];

public:
    GraWKosci() {
        srand(time(NULL));
        rzutKostkami();
    }

    void rzutKostkami() {
        for (int i = 0; i < 5; i++) {
            kostki[i] = rand() % 4;  // Losujemy liczby z przedziału 0-3
        }
        wyswietlKostki();
    }

    void wyswietlKostki() {
        for (int i = 0; i < 5; i++) {
            cout << "Kostka " << i + 1 << ": " << kostki[i] << endl;
        }
    }

    int obliczPunkty() {
        int licznik[4] = {0};  // Zliczamy wystąpienia liczb 0-3
        for (int i = 0; i < 5; i++) {
            licznik[kostki[i]]++;
        }

        int suma = 0;
        for (int i = 0; i < 4; i++) {
            if (licznik[i] >= 2) {
                suma += i * licznik[i];  // Dodajemy wartości oczek
                if (licznik[i] == 2) suma += 2;  // Premia za parę
                if (licznik[i] == 3) suma += 3;  // Premia za trójkę
                if (licznik[i] == 4) suma += 4;  // Premia za czwórkę
            }
        }

        if (licznik[0] == 5 || licznik[1] == 5 || licznik[2] == 5 || licznik[3] == 5) {
            return 30;  // Pięć takich samych daje zawsze 30 punktów
        }

        return suma;
    }

    int obliczWartoscDziesietna() {
        int waga[5] = {256, 64, 16, 4, 1};  // Wartości wagowe pozycji
        int suma = 0;
        for (int i = 0; i < 5; i++) {
            suma += kostki[i] * waga[i];
        }
        return suma;
    }

    void rzutPonowny() {
        char decyzja;
        cout << "Czy chcesz wykonać dodatkowy rzut? (t/n): ";
        cin >> decyzja;

        if (decyzja == 't') {
            int numerKostki;
            do {
                cout << "Wybierz numer kostki (1-5): ";
                cin >> numerKostki;
            } while (numerKostki < 1 || numerKostki > 5);

            kostki[numerKostki - 1] = rand() % 4;  // Rzucenie nowej wartości
            wyswietlKostki();
        }
    }

    void rozpocznijGre() {
        while (true) {
            rzutKostkami();
            cout << "Suma wynosi: " << obliczPunkty() << endl;
            cout << "Wartość dziesiętna: " << obliczWartoscDziesietna() << endl;

            rzutPonowny();
            cout << "Suma wynosi: " << obliczPunkty() << endl;
            cout << "Wartość dziesiętna: " << obliczWartoscDziesietna() << endl;

            char decyzja;
            cout << "Czy chcesz zagrać ponownie? (t/n): ";
            cin >> decyzja;
            if (decyzja == 'n') break;
        }
    }
};

int main() {
    GraWKosci gra;
    gra.rozpocznijGre();
    return 0;
}
