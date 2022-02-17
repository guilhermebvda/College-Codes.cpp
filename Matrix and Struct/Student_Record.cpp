#include <iostream>
#include <cmath>
#include <string>

struct aluno{
    std::string nome;
    int matricula;
    std::string disciplina;
    double nota;
};

int main(){
    aluno qualquer;
    std::cin >> qualquer.nome;
    std::cin >> qualquer.matricula;
    std::cin.ignore();
    std::cin >> qualquer.disciplina;
    std::cin >> qualquer.nota;

    if(qualquer.nota < 7){
        std::cout << qualquer.nome << " reprovado(a) em " << qualquer.disciplina << std::endl;
    }else{
        std::cout << qualquer.nome << " aprovado(a) em " << qualquer.disciplina << std::endl;
    }
}
