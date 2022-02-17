#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double fatorial(int n){
    double fatorial=1;
    for(int i=1; i<=n; i++){
        fatorial *= i;
    }
    return(fatorial);
}

double Euler(int n){
    double retornar=1;
    for(int i=1; i<=n; i++){
        retornar+=(1/fatorial(i));
    }
    return(retornar);
}


int main(){
    int N;
    double resultado;
    cin >> N;
    resultado = Euler(N);

    cout << fixed << setprecision(6) << resultado << endl;
}
