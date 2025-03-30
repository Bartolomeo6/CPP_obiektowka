#include <iostream>
#include <cstdlib> // Dla srand() i rand()
#include <ctime>   // Dla time()

using namespace std;

class Kosci {
    int kostki[5]; // Tablica przechowująca wyniki losowania

public:
    Kosci() {
        srand(time(NULL)); // Inicjalizacja generatora losowego
    }

    void rzutKostka(int nr) {
        if (nr >= 0 && nr < 5) {
            kostki[nr] = rand() % 4; // Losowanie liczby 0-3
        }
    }

    void rzutKostkami() {
        for (int i = 0; i < 5; i++) {
            rzutKostka(i);
        }
        wyswietlKostki();
    }

    void wyswietlKostki() {
        cout << "Wynik losowania: ";
        for (int i = 0; i < 5; i++) {
            cout << kostki[i] << " ";
        }
        cout << endl;
    }

    int obliczPunkty() {
        int licznik[4] = {0}; // Zliczanie wartości 0-3

        for (int i = 0; i < 5; i++) {
            licznik[kostki[i]]++;
        }

        int suma = 0;
        for (int i = 0; i < 4; i++) {
            if (licznik[i] >= 2) {
                suma += i * licznik[i]; // Dodawanie wartości oczek
                suma += licznik[i];     // Bonus za powtórzenia
            }
        }

        // Pełna para (wszystkie te same oczka) -> 30 pkt
        for (int i = 0; i < 4; i++) {
            if (licznik[i] == 5) {
                return 30;
            }
        }

        return suma;
    }

    int obliczWartoscDziesietna() {
        int waga[5] = {256, 64, 16, 4, 1};
        int suma = 0;
        for (int i = 0; i < 5; i++) {
            suma += kostki[i] * waga[i];
        }
        return suma;
    }

    void rzutPonowny() {
        char decyzja;
        cout << "Czy chcesz ponownie rzucić jedną kostką? (t/n): ";
        cin >> decyzja;

        if (decyzja == 't') {
            int numerKostki;
            do {
                cout << "Podaj numer kostki (1-5): ";
                cin >> numerKostki;
            } while (numerKostki < 1 || numerKostki > 5);

            rzutKostka(numerKostki - 1);
            wyswietlKostki();
        }
    }

    void rozpocznijGre() {
        while (true) {
            rzutKostkami();
            cout << "Suma punktów: " << obliczPunkty() << endl;
            cout << "Wartość dziesiętna: " << obliczWartoscDziesietna() << endl;

            rzutPonowny();
            cout << "Suma punktów: " << obliczPunkty() << endl;
            cout << "Wartość dziesiętna: " << obliczWartoscDziesietna() << endl;

            char decyzja;
            cout << "Czy chcesz zagrać ponownie? (t/n): ";
            cin >> decyzja;

            if (decyzja == 'n') {
                break;
            }
        }
    }
};

int main() {
    Kosci kostki;
    kostki.rozpocznijGre();
    return 0;
}
