#include <iostream>
#include<vector>
#include<array>

using namespace std;

int main (){
    int total;
    cin >> total;
    int array[100],auxiliar;
    int indices[100],auxiliar2;
    
    for(int i=0; i<total; i++){
        cin >> array[i];
        indices[i] = i;
    }
        for(int i=0; i<total - 1; i++){
            for(int j= i+1; j<total; j++){
                if(array[i] - array[j] >= 0){
                    auxiliar = array[j];
                    array[j] = array[i];
                    array[i] = auxiliar;

                    auxiliar2 = indices[j];
                    indices[j] = indices[i];
                    indices[i] = auxiliar2;
                }
            }
        } 
        for(int i=0; i<total; i++){
            if(i != total - 1){
                cout << indices[i] << " ";
            }else{
                cout << indices[i] << endl;
            }
        }
}