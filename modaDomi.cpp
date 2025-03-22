// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void losowanieWartosci(int tab[20], int n){
    srand(time(NULL));
    for(int i = 0; i<n; i++){
        tab[i] = rand()%50+50;
    }
}

void sortowanieLiczb(int tablica[20], int dl){
    for(int i = 0; i<dl-1; i++){
        for(int j = 0; j<dl-i-1; j++){
            if(tablica[j] > tablica[j+1]){
                int temp = tablica[j];
                tablica[j] = tablica[j+1];
                tablica[j+1] = temp;
            } 
        }
    }
    
    for(int i = 0; i<dl; i++){
        cout<<tablica[i]<<" ";
    }
}

double mediana(int tablicaLiczb[20], int n){
    if(n % 2 == 0){
        return (tablicaLiczb[n/2-1] + tablicaLiczb[n/2])/2.0;
    }
    else{
        return (tablicaLiczb[n/2]);
    }
}

void dominanta(int liczby[], int dlugosc) {
    int najwLicznik = 0;
    int dominujace[20];
    int licznikDominant = 0;

    for (int i = 0; i < dlugosc; i++) {
        int licznik = 0;
        for (int j = 0; j < dlugosc; j++) {
            if (liczby[i] == liczby[j]) {
                licznik++;
            }
        }
        if (licznik > najwLicznik) {
            najwLicznik = licznik;
            licznikDominant = 0;
            dominujace[licznikDominant++] = liczby[i];
        } 
        else if (licznik == najwLicznik) {
            bool istnieje = false;
            for (int k = 0; k < licznikDominant; k++) {
                if (dominujace[k] == liczby[i]) {
                    istnieje = true;
                    break;
                }
            }
            if (!istnieje) {
                dominujace[licznikDominant++] = liczby[i];
            }
        }
    }

    if (najwLicznik == 1) {
        cout << "\nBrak dominanty." << endl;
    } else {
        int procent = (najwLicznik * 100) / dlugosc;
        cout << "\nWartości o największej częstotliwości (" << procent << "%): ";
        for (int i = 0; i < licznikDominant; i++) {
            cout << dominujace[i] << " ";
        }
        cout << endl;
    }
}


void sitoErato(int n){
   bool A[n];

    for(int i = 0; i<n; i++){
        A[i] = true;
    }

    A[0] = A[1] = false;

    for(int i = 2; i<=n; i++){
        if(A[i]){
            for(int j = i*i; j<n; j+=i){
                A[j] = false;
            }
        }
    }
    
    if(n>=1000){
        int pierwsze[3] = {0,0,0};
        int znalezione = 0;
        
        for(int i = n; i>=2 && znalezione<3; i--){
            if(tablicaLiczb[i] == 1){
                pierwsze[znalezione] = i;
                znalezione++;
            }
        }
        
        for(int i = 2; i>=0; i--){
            cout<<pierwsze[i]<<" ";
        }
    }
    else{
       for(int i = 2; i<=n; i++){
            if(tablicaLiczb[i] == 1){
                cout<<i<<" ";
            }
        }
    }
    
}

int main() {
    // Write C++ code here
    int tab[20];
    int dl = sizeof(tab)/sizeof(tab[0]);
    int dlugosc = 50;
    
    losowanieWartosci(tab, dl);
    sortowanieLiczb(tab,dl);
    cout<<"\n Mediana: "<<mediana(tab, dl);
    dominanta(tab,dl);
    
    sitoErato(dlugosc);

    return 0;
}
