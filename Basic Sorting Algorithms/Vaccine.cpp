#include <iostream>
#include<vector>
#include<array>

using namespace std;

int main (){
    int total;
    cin >> total;
    int array[100];
    int array2[100];
    int auxiliar;

    for(int i=0; i<total; i++){
        cin >> array[i];
    }
    for(int i=0; i<total; i++){
        cin >> array2[i];
    }
    
    for(int i=0; i<total - 1; i++){
        for(int j= i + 1; j < total; j++){
            
            if(array[i] - array[j] >= 0){
                auxiliar = array[j];
                array[j] = array[i];
                array[i] = auxiliar;
            }
            
            if(array2[i] - array2[j] >= 0){
                auxiliar = array2[j];
                array2[j] = array2[i];
                array2[i] = auxiliar;
            }

        }
    }
    for(int i = 0; i<total; i++){
        if(array[i] < array2[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}