#include <iostream>
#include <cmath>

using namespace std;

int fatorial(int n){
   if(n <= 1){
      return 1;
   }else{
      return n * fatorial(n-1);
   }
}

int main(){
   int inteiro,resultado;

   cin >> inteiro;

   resultado = fatorial(inteiro);

   cout << resultado << endl;
}
