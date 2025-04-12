// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

class Kostki{
    int kosci[5];
    
    public:
    Kostki(){
        srand(time(NULL));
    }
    
    ~Kostki(){
        
    }
    
    void rzucKoscia(int nr){
        if(nr >= 0 && nr < 5){
            kosci[nr] = rand()%4;
        }
    }
    
    void rzutKostkami(){
        for(int i = 0; i<5; i++){
            rzucKoscia(i);
        }
        wyswietlKostki();
    }
    
    void wyswietlKostki(){
        for(int i = 0; i<5; i++){
            cout<<"Kostka "<<i+1<<": "<<kosci[i]<<endl;
        }
    }
    
    int liczPunkty(){
        int licznik[4] = {0};
        for(int i = 0; i<5; i++){
            licznik[kosci[i]]++;
        }
        
        int suma = 0;
        for(int i = 0; i<4; i++){
            if(licznik[i] >= 2){
                suma += i*licznik[i];
                suma += licznik[i];
            }
            else if(licznik[i] == 5){
                return 30;
            }
        }
        return suma;
        
    }
    
    int punktyDziesietnie(){
        int waga[5] = {256,64,16,4,1};
        int suma = 0;
        
        for(int i = 0; i<5; i++){
            suma += kosci[i]*waga[i];
        }
        return suma;
    }
    
    void ponownyRzut(){
        char decyzja;
        cout<<"Czy chcesz wykonać kolejny rzut? (t/n): ";
        cin>>decyzja;
        
        if(decyzja == 't'){
            int numerKostki = 0;
            do{
                cout<<"Podaj numer kosci: ";
                cin>>numerKostki;
            }
            while(numerKostki < 0 && numerKostki > 5);
            
            rzucKoscia(numerKostki-1);
            wyswietlKostki();
        }
    }
    
    void rozpocznijGre(){
        while(true){
            rzutKostkami();
            cout<<"Punkty: "<<liczPunkty()<<endl;
            cout<<"Dziesietnie: "<<punktyDziesietnie()<<endl;
            
            ponownyRzut();
            cout<<"Punkty: "<<liczPunkty()<<endl;
            cout<<"Dziesietnie: "<<punktyDziesietnie()<<endl;
            
            char decyzja;
            cout<<"Czy chcesz zagrać ponownie? (t/n): ";
            cin>>decyzja;
            
            if(decyzja == 'n'){
                cout<<"Opuszczono grę.";
                break;
            }
        }
    }
    
    
    
};

int main() {
    Kostki kostki;
    kostki.rozpocznijGre();

    return 0;
}
