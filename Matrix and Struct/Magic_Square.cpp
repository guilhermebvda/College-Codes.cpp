#include <iostream>

using namespace std;

int main(){

    int soma=0, total=0;
    int matriz[3][3];
    int i,j;
   
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            cin >> matriz[i][j];
        }
    }

    // Somando a Diagonal Principal //
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(i == j){
                soma += matriz[i][j];
            }
        }
    }

    total = soma;
    soma = 0;
    
    // Somando a Diagonal Secundária //
    for(j=0; j<3; j++){
        for(i=0; i<3; i++){
            if(matriz[j][i] == matriz[j][3-i-1]){
                soma += matriz[j][i];
            }
        }
    }
    
    if (total != soma){
        cout << "nao" << endl;
        return 0;
    }
    
    // Somando as Colunas //
    for(j=0; j<3; j++){
        soma=0;
        for(i=0; i<3; i++){
            soma += matriz[i][j];
        }
        if(soma != total){
            break;
        }
    }

    if (total != soma){
        cout << "nao" << endl;
        return 0;
    }

    // Somando as Linhas
    for(i=0; i<3; i++){
        soma=0;
        for(j=0; j<3; j++){
            soma += matriz[i][j];
        }
        if(soma != total){
            break;
        }
    }
    
    if (total != soma){
        cout << "nao" << endl;
        return 0;
    }else{
        cout << "sim" << endl;
    }
}
