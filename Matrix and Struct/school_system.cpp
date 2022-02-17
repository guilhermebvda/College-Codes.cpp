#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct Aluno{
    int matricula;
    char nome[100];
    double media;
};

int main(){
    int i;
    int alunos,localizar;
    cin >> alunos;
    cin.ignore();
    Aluno perfil[alunos];
    for(i=0; i<alunos; i++){
        cin >> perfil[i].matricula;
        cin.ignore();
        cin.get(perfil[i].nome, 100);
        cin.ignore();
        cin >> perfil[i].media;
        cin.ignore();
    }
    cin >> localizar;

    for(i=0; i<alunos; i++){
        if(perfil[i].matricula == localizar){
            cout << perfil[i].nome << endl << fixed << setprecision(1) << perfil[i].media << endl;
            return 0;
        }
    }
    cout << "NAO ENCONTRADA" << endl;

}
