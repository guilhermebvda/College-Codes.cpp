#include <iostream>

using namespace std;

int main(){
    int atual=0, depois=0, fora=0;
    int i,j;
    int matriz[3][3];
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            cin >> matriz[i][j];
        }
    }

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
        
        depois = matriz[j][i];
        
        if(j == 0 ){
            atual=depois;
        }
        if(atual > depois){
            fora++;
            atual=depois;
        }else{
            atual=depois;
        }
        }
    }
    cout << fora << endl;
}
