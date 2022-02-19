#include <iostream>
#include<vector>
#include<array>

using namespace std;

int main (){
    int total;
    cin >> total;
    int array[100];
    int contador = 0;
    int numero = 0;
    int resultado = 0;
    
    for(int i=0; i<total; i++){
        cin >> array[i];
    }
        for(int i=0; i<total - 1; i++){
            for(int j = i; j<total; j++){
                if(array[i] == array[j]){
                    contador++;
                }
            }
            if(contador > resultado){
                numero = array[i];
                resultado = contador;
            }
            contador = 0;
        } 
        cout << numero << " " << resultado << endl;
}