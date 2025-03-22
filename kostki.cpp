// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

class Kosci{
    int kostki[5];
    
    public:
    Kosci(){
        srand(time(NULL));
    }
    
    ~Kosci(){
        
    }
    
    void rzutKostkami(){
        for(int i = 0; i<5; i++){
            kostki[i] = rand() % 4;
        }
        wyswietlKostki();
    }
    
    void wyswietlKostki(){
       for(int i = 0; i<5; i++){
           cout<<"Kostka: "<<i+1<<": "<<kostki[i]<<endl;
       }
    }
    
    int obliczPunkty(){
        int licznik[4] = {0};
        for(int i = 0; i<5; i++){
            licznik[kostki[i]]++;
        }
        
        int suma = 0;
        for(int i = 0; i<4; i++){
            if(licznik[i] >= 2){
                suma += i*licznik[i];
                if(licznik[i] == 2){
                    suma+=2;
                }
                if(licznik[i] == 3){
                    suma+=3;
                }
                if(licznik[i] == 4){
                    suma+=4;
                }
            }
        }
        
        if(licznik[0] == 5 || licznik[1] == 5 || licznik[2] == 5 || licznik[3] == 5){
            return 30;
        }
        return suma;
    }
    
    int obliczWartoscDziesietna(){
        int waga[5] = {256, 64, 16, 4, 1};
        int suma = 0;
        for(int i = 0; i<5; i++){
            suma += kostki[i] * waga[i];
        }
        return suma;
    }
    
    void rzutPonowny(){
        char decyzja;
        cout<<"Czy chcesz oddać kolejny rzut kostką? (t/n): ";
        cin>>decyzja;
        
        if(decyzja == 't'){
            int numerKostki = 0;
            do{
                cout<<"Podaj numer kostki: ";
                cin>>numerKostki;
            }
            while(numerKostki < 1 || numerKostki > 5);
            
            kostki[numerKostki - 1] = rand() % 4;
            wyswietlKostki();
        }
        else{
            return;
        }
    }
    
    void rozpocznijGre(){
        while(true){
            rzutKostkami();
            cout<<"Suma wynosi: "<<obliczPunkty()<<endl;
            cout<<"Wartosc dziesietna: "<<obliczWartoscDziesietna()<<endl;
            
            rzutPonowny();
            cout<<"Suma wynosi: "<<obliczPunkty()<<endl;
            cout<<"Wartosc dziesietna: "<<obliczWartoscDziesietna()<<endl;
            
            char decyzja;
            cout<<"Czy chcesz zagrać ponownie? (t/n): ";
            cin>>decyzja;
            
            if(decyzja == 'n'){
                break;
            }
        }
    };
};

int main() {
    Kosci kostki;
    kostki.rozpocznijGre();

    return 0;
}
