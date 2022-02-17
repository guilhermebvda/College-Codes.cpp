#include <iostream>
#include <vector>
using namespace std;

void right_rotation(vector<int>& vet, int nrot){
    int aux = 0;
    int i,j;
    for(i=0; i<nrot; i++){
        for(j=0; j<vet.size(); j++){
        aux = vet[j];
        vet[j] = vet[vet.size() - 1];
        vet[vet.size() - 1] = aux;
        }
    }
}

void show(vector<int> &vet) {
    cout << "[ ";
    for(int value : vet)
        cout << value << " ";
    cout << "]\n";
}

int main(){
    int size, nrot;
    cin >> size >> nrot;
    vector<int> vet(size);
    for(int i = 0; i < size; i++)
        cin >> vet[i];
    
    right_rotation(vet, nrot);
    show(vet);
}
