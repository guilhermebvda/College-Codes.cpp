#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(){
    int total,i;
    cin >> total;
    cin.ignore();
    
    float valores[total];
    
    for(i=0; i<total; i++){
        cin >> valores[i];
        cin.ignore();
    }

    float chutes1[total];

    for(i=0; i<total; i++){
        cin >> chutes1[i];
        cin.ignore();
    }

    string chutes2[total];

    for(i=0; i<total; i++){
        cin >> chutes2[i];
    }

    int j1=0,j2=0; // j == jogador
    
    for(i=0; i<total; i++){
        if((chutes1[i] < valores[i] && chutes2[i] == "M") || (chutes1[i] > valores[i] && chutes2[i] == "m")){
            j2++;
        }else{
            j1++;
        }
    }

    if(j1 > j2){
        cout << "primeiro" << endl;
    }
    if(j1 < j2){
        cout << "segundo" << endl;
    }   
    if(j1 == j2){
        cout << "empate" << endl;
    }
}
