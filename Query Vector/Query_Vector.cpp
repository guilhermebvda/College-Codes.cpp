#include <iostream>
#include <cstring>

using namespace std;

void matchingStrings(string pesquisar[],string consulta[], int tamanho, int tamanho2, int *vetor){
    
    for(int i=0; i<tamanho2; i++){
        vetor[i] = 0;
    }
    for(int i = 0; i<tamanho2; i++){
        for(int j=0; j<tamanho; j++){
            if(consulta[i] == pesquisar[j]){
                vetor[i] += 1;
            }
        }

    }
    for(int i=0; i<tamanho2; i++){
        cout << vetor[i] << " ";
    }
};

int main(){
    int tamanho,i;
    cin >> tamanho;
    cin.ignore();
    string pesquisar[tamanho];
    for(i=0; i<tamanho; i++){
        cin >> pesquisar[i];
        cin.ignore();
    }
    int tamanho2;
    cin >> tamanho2;
    cin.ignore();
    string consulta[tamanho2];
    for(i=0; i<tamanho2; i++){
        cin >> consulta[i];
        cin.ignore();
    }
    int *vetor = new int[tamanho2];

    matchingStrings(pesquisar,consulta,tamanho,tamanho2,vetor);
}
