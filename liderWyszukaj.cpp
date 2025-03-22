#include <iostream>
#include <fstream>

using namespace std;

int szukaj_lider(int tab[], int n){
    
    int lider = tab[0];
    int do_pary = 1;
    
    for(int i = 1; i<n; i++){
        if(do_pary > 0){
            if(tab[i] == lider){
                ++do_pary;
            }
            else{
                --do_pary;
            }
        }
        else{
            ++do_pary;
            lider = tab[i];
        }
    }
    
    if(do_pary == 0){
        return -1;
    }
    
    int licznik = 0;
    
    for(int i = 0; i<n; i++){
        if(tab[i] == lider){
            ++licznik;
        }
    }
    if(licznik > n/2){
        return lider;
    }
    
    return -1;
}

int main()
{
    int n, *tab, lider;
    
    cout<<"Ile liczb? ";
    cin>>n;
    
    tab = new int[n];

    srand(time(NULL));
    for(int i = 0; i<n; i++){
         tab[i] = rand() % 5 + 1;
         cout<<tab[i]<<endl;
    }
    
    lider = szukaj_lider(tab, n);
    if(lider == -1){
        cout<<"Ten zbiór nie posiada lidera";
    }
    else{
        cout<<"Lider to: "<<lider;
    }

    return 0;
}
