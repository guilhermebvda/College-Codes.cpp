#include <iostream>
#include <queue>
using namespace std;


int main (){
    char times,time1,time2;
    queue<char> fila;
    
    for(times = 'A'; times <= 'P'; times++){
        fila.push(times);
    }
    
    int gol1,gol2;
    
    for(int i=1; i<16; i++){
        cin >> gol1 >> gol2;
        if(gol1<gol2){
            time1 = fila.front();
            fila.pop();
            time2 = fila.front();
            fila.pop();
            fila.push(time2);
        } 
        if(gol1>gol2){
            time1 = fila.front();
            fila.pop();
            time2 = fila.front();
            fila.pop();
            fila.push(time1);
        }      
    }
    time1 = fila.front();
    fila.pop();
    cout << time1 << endl;
}
