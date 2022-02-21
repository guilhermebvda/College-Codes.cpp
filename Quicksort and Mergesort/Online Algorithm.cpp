#include <iostream>
using namespace std;

int main(){
    int total;
    cin >> total;
    int ordem[100],valor[100],array[100];
    int contador = 0, pos = 0, aux = 0;
    
    for(int i=0; i<total; i++){
        cin >> ordem[i] >> valor[i];
        if(ordem[i] == 1){
            array[contador] = valor[i];
            contador++;
        if(contador > 1){
            pos = contador-1;
        for(int j=contador-2; j>=0; j--){
        
        if(array[j] > array[pos]){
            aux = array[pos];
            array[pos] = array[j];
            array[j] = aux;
            pos--;
        }else{
            break;
                   }
                }
            }
        }
        if(ordem[i] == 2){
            cout << array[valor[i]] << endl;
        }
    }
    
}