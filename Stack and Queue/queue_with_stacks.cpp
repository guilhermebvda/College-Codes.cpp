#include <iostream>
#include <stack>
#include <stdexcept>

using namespace std;

struct pilha{
    
    stack<int>pratileira;
    stack<int>deposito;


void put_on_top(int colocar){
    deposito.push(colocar);
}

void rule_out(){
    if(pratileira.size() > 0){
        pratileira.pop();
        return;
    }
    
    if(pratileira.empty() == true){
        while(deposito.empty() == false ){
            pratileira.push(deposito.top());
            deposito.pop();
        }
    }
    
    if(pratileira.empty() == false){
        pratileira.pop();
    }
    
}
void show(){
    if(pratileira.empty() == true){
        while(deposito.empty() == false ){
            pratileira.push(deposito.top());
            deposito.pop();
        }
    }
    cout << pratileira.top()<< endl;
}
};



int main(){
    int total;
    pilha chamar;
    cin >> total;
    int comando;
    for(int i = 0;i < total;i++){
        cin >> comando;
        if(comando == 1){
            int colocar;
            cin >> colocar;
            chamar.put_on_top(colocar);
        }
        if(comando == 2){
            chamar.rule_out();
        }
        if(comando == 3){
            chamar.show();
        }
    }
}
