#include <iostream>
#include <fstream>

using namespace std;

class PeselSprawdzanie {
    string pesel;

public:
    PeselSprawdzanie(string pesel) {
        this->pesel = pesel;
    }

    char sprawdzPlec() {
        int plec = pesel[9] - '0';
        if (plec % 2 == 0) {
            return 'K';
        } else {
            return 'M';
        }
    }

    bool sumaKontrolna() {
        int waga[10] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
        int suma = 0;
        
        for (int i = 0; i < 10; i++) {
            int cyfra = pesel[i] - '0';
            suma += cyfra * waga[i];
        }
        
        int m = suma % 10;
        int r;
        
        if (m == 0) {
            r = 0;
        } else {
            r = 10 - m;
        }
        
        int ostatniaCyfra = pesel[10] - '0';
        if (r == ostatniaCyfra) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    ifstream plik("pesele.txt");
    string pesel;
    
    while (plik >> pesel) {
        if (pesel.length() != 11) {
            cout << "Niepoprawna dlugosc PESEL: " << pesel << endl;
            continue;
        }
        
        PeselSprawdzanie sprawdz(pesel);
        bool poprawny = sprawdz.sumaKontrolna();
        char plec = sprawdz.sprawdzPlec();
        
        cout << "PESEL: " << pesel << " - Plec: " << plec << " - Poprawny: ";
        
        if (poprawny) {
            cout << "Tak" << endl;
        } else {
            cout << "Nie" << endl;
        }
    }
    
    plik.close();
    return 0;
}
