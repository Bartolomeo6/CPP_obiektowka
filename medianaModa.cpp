#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class ArrayProcessor {
private:
    int tablica[30];
    int *liczbyPierwsze;
    int liczbaPierwszych;
    
public:
    ArrayProcessor() {
        srand(time(0));
        for (int i = 0; i < 30; i++) {
            tablica[i] = rand() % 10;
        }
        liczbyPierwsze = nullptr;
        liczbaPierwszych = 0;
    }
    
    ~ArrayProcessor() {
        delete[] liczbyPierwsze;
    }
    
    void selectionSort() {
        for (int i = 0; i < 29; i++) {
            int minIndex = i;
            for (int j = i + 1; j < 30; j++) {
                if (tablica[j] < tablica[minIndex]) {
                    minIndex = j;
                }
            }
            swap(tablica[i], tablica[minIndex]);
        }
    }
    
    int znajdzMode(int &czestosc) {
        int maxLicznik = 0, moda = -1;
        for (int i = 0; i < 30; ) {
            int licznik = 1;
            for (int j = i + 1; j < 30 && tablica[j] == tablica[i]; j++) {
                licznik++;
            }
            if (licznik > maxLicznik) {
                maxLicznik = licznik;
                moda = tablica[i];
            }
            i += licznik;
        }
        czestosc = (maxLicznik * 100) / 30;
        return moda;
    }
    
    double znajdzMediane() {
        return (tablica[14] + tablica[15]) / 2.0;
    }
    
    bool czyPierwsza(int liczba) {
        if (liczba < 2) return false;
        for (int i = 2; i * i <= liczba; i++) {
            if (liczba % i == 0) return false;
        }
        return true;
    }
    
    void znajdzLiczbyPierwsze() {
        liczbaPierwszych = 0;
        int unikalne[10] = {0};
        for (int i = 0; i < 30; i++) {
            if (czyPierwsza(tablica[i]) && unikalne[tablica[i]] == 0) {
                unikalne[tablica[i]] = 1;
                liczbaPierwszych++;
            }
        }
        
        if (liczbaPierwszych > 0) {
            liczbyPierwsze = new int[liczbaPierwszych];
            int index = 0;
            for (int i = 0; i < 10; i++) {
                if (unikalne[i] == 1) {
                    liczbyPierwsze[index++] = i;
                }
            }
            selectionSortLiczbyPierwsze();
        }
    }
    
    void selectionSortLiczbyPierwsze() {
        for (int i = 0; i < liczbaPierwszych - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < liczbaPierwszych; j++) {
                if (liczbyPierwsze[j] < liczbyPierwsze[minIndex]) {
                    minIndex = j;
                }
            }
            swap(liczbyPierwsze[i], liczbyPierwsze[minIndex]);
        }
    }
    
    int znajdzLidera() {
        int maxLicznik = 0, lider = -1;
        for (int i = 0; i < 30; ) {
            int licznik = 1;
            for (int j = i + 1; j < 30 && tablica[j] == tablica[i]; j++) {
                licznik++;
            }
            if (licznik > maxLicznik) {
                maxLicznik = licznik;
                lider = tablica[i];
            }
            i += licznik;
        }
        return lider;
    }
    
    void wyswietlWyniki() {
        cout << "Tablica posortowana: ";
        for (int i = 0; i < 30; i++) {
            cout << tablica[i] << " ";
        }
        cout << endl;
        
        int czestosc;
        int moda = znajdzMode(czestosc);
        cout << "Moda: " << moda << " z " << czestosc << "% częstością." << endl;
        
        int lider = znajdzLidera();
        if (lider != -1) {
            cout << "Lider: " << lider << " (występuje " << (int)((czestosc * 30) / 100) << " razy)" << endl;
        } else {
            cout << "Brak lidera w tablicy." << endl;
        }
        
        cout << "Mediana: " << znajdzMediane() << endl;
        
        if (liczbaPierwszych > 0) {
            cout << "Liczby pierwsze (unikalne): ";
            for (int i = 0; i < liczbaPierwszych; i++) {
                cout << liczbyPierwsze[i] << " ";
            }
            cout << endl;
        } else {
            cout << "Brak liczb pierwszych w tablicy." << endl;
        }
    }
};

int main() {
    ArrayProcessor ap;
    ap.selectionSort();
    ap.znajdzLiczbyPierwsze();
    ap.wyswietlWyniki();
    return 0;
}
