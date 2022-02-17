#include <iostream>
#include <cmath>
using namespace std;

int fib(int n){
        int contador;
        if(n == 0){
           contador = 0;
           return contador;
        }
        if(n == 1 || n == 2){
           contador = 1;
           return contador;
        }else{
           contador = fib(n-1) + fib(n-2);
        }
        return contador;
    }

    int main(){
        int n;
        cin >> n;
        cout << fib(n) << endl;
    }
