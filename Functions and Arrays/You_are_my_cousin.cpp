#include <iostream>
#include <cmath>

using namespace std;

bool primo(int n){
    int i;
    
    if(n <= 2 && n != 0){
            return true;
        }
    
    for(i=2; i<n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
   int A,B,i;
   int teste;
   cin >> A;
   cin >> B;
   int numeros[B + 1], primos[B + 1];

   for(i=0; i<=B; i++){
       primos[i]=0;
   }

   for(i=A; i<=B; i++){
       numeros[i] = i;
   }

   for(i=A; i<=B; i++){
       teste = primo(i);
       if(teste == true){
           primos[i]=i;
       }
   }

   for(i=0; i<=B; i++){
       if(primos[i] != 0){
           cout << primos[i] << endl;
       }
   }
}
