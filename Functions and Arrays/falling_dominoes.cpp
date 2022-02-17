#include <iostream>

using namespace std;

int main(){
    int total,i;
    cin >> total;
    int vetor[total];
    for(i=0; i<total; i++){
        cin >> vetor[i];
    }
    int maior = -1;
    for(i=0; i<total; i++){
            if(vetor[i] >= maior){
                maior = vetor[i];
            }else{
                cout << "precisa de ajuste" << endl;
                return 0;
            }
        }
        cout << "ok" << endl;
    }
