#include <iostream>
#include<vector>
#include<array>

using namespace std;

int main (){
    int total;
    cin >> total;
    int array[100];
    int array2[100];
    int auxiliar = 0;

    for(int i=0; i<total; i++){
        cin >> array[i];
    }
    for(int i=0; i<total; i++){
        cin >> array2[i];
    }
    
    for(int i=0; i<total; i++){
        for(int j= 0; j < total; j++){
            if(array[i] == array2[j]){
                auxiliar += 1;
                break;
            }
        }
    }
    if(auxiliar == total){
        cout << 1 << endl;
    }else{
        cout << 0 << endl;
    }
}