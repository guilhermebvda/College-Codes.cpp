#include <iostream>

using namespace std;

int main(){

    int total,i;
    cin >> total;
    int pessoas[total];
    
    for(i=0; i<total; i++){
        cin >> pessoas[i];
    }

    int sair,j;
    cin >> sair;
    int deixou[sair];
    for(i=0; i<sair; i++){
        cin >> deixou[i];
    }
    int retirando = -13;
    for(i=0; i<sair; i++){
        for(j=0; j<total; j++){
            if(deixou[i] == pessoas[j]){
                pessoas[j] = retirando;
            }
        }
    }
    for(i=0; i<total; i++){
        if(pessoas[i] >= 0){
            cout << pessoas[i] << " ";
        }
    }
}
