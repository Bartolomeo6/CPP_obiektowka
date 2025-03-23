// Online C++ compiler to run C++ program online
#include <iostream>
#include <fstream>

using namespace std;

class PeselV{
    
    string pesel;
    
    public:
    PeselV(string P){
        this->pesel = P;
    }
    
    ~PeselV(){
        
    }
    
    char sprawdzPlec(){
        int plec = pesel[9] - '0';
        if(plec % 2 == 0){
            return 'K';
        }
        else{
            return 'M';
        }
    }
    
    bool cyfraKontrolna(){
        int waga[10] = {1,3,7,9,1,3,7,9,1,3};
        int s = 0;
        
        for(int i = 0; i<10; i++){
            int cyfra = pesel[i] - '0';
            s += cyfra*waga[i];
        }
        
        int m = s % 10;
        int r;
        
        if(m == 0){
            r = 0;
        }
        else{
            r = 10-m;
        }
        
        int ostatniaBoi = pesel[10] - '0';
        
        if(r == ostatniaBoi){
            return true;
        }
        else{
            return false;
        }
    }
};

int main() {
    ifstream plik("pesele.txt");
    
    string linia;
    while(plik >> linia){
        PeselV sprawdzaniePesel(linia);
        cout<<"Pesel: "<<linia<<" || Plec: "<<sprawdzaniePesel.sprawdzPlec()<<" || Poprawny: ";
        
        if(sprawdzaniePesel.cyfraKontrolna()){
            cout<<"Tak\n";
        }
        else{
            cout<<"Nie\n";
        }
    }

    return 0;
}
