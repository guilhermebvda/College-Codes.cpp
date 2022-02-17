#include<iostream>

using namespace std;


void Torre_de_Hanoi(char origem, char destino, char auxiliar, int discos){
   if(discos == 1){
      cout << origem << " -> " << destino << endl;
   }else{
      Torre_de_Hanoi(origem,auxiliar,destino,discos-1);
      cout << origem << " -> " << destino << endl;
      Torre_de_Hanoi(auxiliar, destino, origem,discos-1);
   }
   
}


int main(){
   int discos;
   cin >> discos;
   
   Torre_de_Hanoi('A','C','B',discos);

   return 0;
}
