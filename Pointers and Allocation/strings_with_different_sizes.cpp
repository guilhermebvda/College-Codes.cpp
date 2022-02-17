#include <iostream>
#include <cstring>

using namespace std;

int main(){
   int total,i,j,tamanho;
   cin >> total;
   char **lote = new char *[total];
   for(i=0; i< total; i++){
      cin >> tamanho;
      lote[i] = new char [tamanho];
      cin.ignore();
      cin.get(lote[i],tamanho + 1);
      cin.ignore();
   }

   for(i=0; i<total; i++){
       for(j=0; j<total - 1; j++){
           if(strcmp(lote[j],lote[j+1]) > 0){
              char *troca = lote[j+1];
              lote[j+1] = lote[j];
              lote[j] = troca;
           }
       }
   }
   
   for(i=0; i<total ; i++){
      cout << lote[i] << endl;
   }
   delete[] lote;
    return 0;
}
