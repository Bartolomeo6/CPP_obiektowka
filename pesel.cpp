#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class PeselValidator {
private:
    string pesel;
    
public:
    PeselValidator(string pesel) {
        this->pesel = pesel;
    }
    
    char sprawdzPlec() {
        if ((pesel[9] - '0') % 2 == 0) {
            return 'K';
        } else {
            return 'M';
        }
    }
    
    bool sprawdzSumeKontrolna() {
        int wagi[10] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
        int suma = 0;
        
        for (int i = 0; i < 10; i++) {
            suma += (pesel[i] - '0') * wagi[i];
        }
        
        int kontrolna = (10 - (suma % 10)) % 10;
        if (kontrolna == (pesel[10] - '0')) {
            return true;
        } else {
            return false;
        }
    }
    
    void wyswietlInformacje() {
        cout << pesel << " ";
        if (sprawdzPlec() == 'K') {
            cout << "Kobieta";
        } else {
            cout << "Mezczyzna";
        }
        cout << " ";
        if (sprawdzSumeKontrolna()) {
            cout << "true";
        } else {
            cout << "false";
        }
        cout << endl;
    }
};

int main() {
    ifstream plik("pesele.txt");
    if (!plik) {
        cout << "Nie mozna otworzyc pliku pesele.txt!" << endl;
        return 1;
    }
    
    string pesel;
    while (plik >> pesel) {
        if (pesel.length() != 11) {
            cout << "Niepoprawny numer PESEL: " << pesel << endl;
        } else {
            PeselValidator validator(pesel);
            validator.wyswietlInformacje();
        }
    }
    
    plik.close();
    return 0;
}
