#include <iostream>
#include <sstream>
using namespace std;

struct Vector {
    int capacity;
    int size;
    int * data;
};

Vector * vector_create(int capacity) {
    //crie um vetor dinâmicamente
    //cria a struct
    Vector *vector = new Vector;
    //crie o vetor data
    vector->data = new int [capacity];
    //inicialize size e capacity
     vector->size = 0;
     vector->capacity = capacity;
     
     return vector;
}

void vector_destroy(Vector * vector) {
    //destrua data
    delete[] vector->data;
    vector->data = nullptr;
    //destrua a struct
    delete vector;
    vector = nullptr;
}

void vector_add(Vector * vector, int value) {
    //utilize capacity e size para verificar se ainda existe espaço
    if(vector->size < vector->capacity){
        vector->size++;
        vector->data[vector->size - 1] = value;
    }
}

//retorne a string no formato 
// [ a b c ]
string vector_show(Vector * vector) {
    //retorne uma string com os dados do vetor
    stringstream ss;
    
    ss << "[ ";
    for(int i=0; i<vector->size; i++){
        ss << vector->data[i] << " ";
    }
    ss << "]";
    string Resultado = ss.str();
    return Resultado;

    //você pode usar uma stringstream como buffer
    //stringstream ss;
    //ss << 5 << " eh inteiro";
    //ss.str() será "5 eh inteiro"
}


/* NAO MEXA DAQUI PRA BAIXO */
int main() {
    string line, cmd;
    int value;
    Vector * v = vector_create(0);
    while(true) {
        getline(cin, line);
        cout << "$" << line << endl;
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "end"){
            break;
        } else if(cmd == "init") {
            ss >> value;
            if(v != nullptr)
                vector_destroy(v);
            v = vector_create(value);
        } else if(cmd == "status") {
            cout << "size:" << v->size << " capacity:" << v->capacity << "\n";
        } else if(cmd == "add") {
            while(ss >> value)
                vector_add(v, value);
        } else if(cmd == "show") {
            cout << vector_show(v) << endl;
        } else {
            cout << "fail: comando invalido\n";
        }
    }
    vector_destroy(v);
}
