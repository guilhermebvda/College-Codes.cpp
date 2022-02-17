#include <iostream>
#include <cmath>
using namespace std;

void print(int vetor[], int tamanho)
{
   cout << "[";
   for(int i=0; i<tamanho; i++){
      if(i == tamanho - 1){
         cout << vetor[i] << "]" << endl;
      }else{
         cout << vetor[i] << ", ";
      }
   }
}

void triangulo_de_somas(int vetor[], int tamanho)
{
   if(tamanho > 0){

      int novo[tamanho - 1];
      for(int i=0; i < tamanho - 1; i++){
         novo[i] = vetor[i] + vetor[i+1];
      }
      triangulo_de_somas(novo, tamanho - 1);
      
      print(vetor,tamanho);
   }




}

int main(){
   int tamanho;
   cin >> tamanho;
   int vetor[tamanho];
   for(int i=0; i<tamanho; i++){
      cin >> vetor[i];
   }

   triangulo_de_somas(vetor,tamanho);
}
