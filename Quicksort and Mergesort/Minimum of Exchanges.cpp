#include <iostream>
using namespace std;

int main(){
    int total;
    cin >> total;
    int array[100];
    int k = 0, i = 0, j = 0, inverter = 0, pos = 999, menor = 999,  troca = 0, razao = 0;
    
    while(k < total){
        cin >> array[k];
        if(array[k] < menor){
            menor = array[k];
        }
        k++;
    }
    k=0;
    
    for(i=0; i<total; i++){
        if(array[i] == menor && i > 0){
            inverter = array[0];
            array[0] = array[i];
            array[i] = inverter;
            troca++;
            i = 0;
        }
        if(array[0] == menor && i > 0){
            for(j=i+1; j<total; j++){
                if(array[i] > array[j] && array[i] - array[j] > razao){
                    pos = j;
                    razao = array[i] - array[j];
                }
            }
            if(pos != 999){
                inverter = array[pos];
                array[pos] = array[i];
                array[i] = inverter;
                troca++;
            }
            pos = 999;
            razao = 0;
        }
    }
    cout << troca << endl;
}