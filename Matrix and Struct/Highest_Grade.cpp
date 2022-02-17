#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

struct aluno1{
    std::string nome;
    int matricula;
    std::string disciplina;
    double nota;
};
struct aluno2{
    std::string nome;
    int matricula;
    std::string disciplina;
    double nota;
};

int main(){
    aluno1 A;
    std::cin >> A.nome;
    std::cin >> A.matricula;
    std::cin.ignore();
    std::cin >> A.disciplina;
    std::cin >> A.nota;
    
    aluno2 B;
    std::cin >> B.nome;
    std::cin >> B.matricula;
    std::cin.ignore();
    std::cin >> B.disciplina;
    std::cin >> B.nota;
    
    if(A.nota < B.nota ){
        std::cout << B.nome << " , " << std::fixed  << std::setprecision(1) << B.nota << std::endl;
    }
    
    if(A.nota > B.nota){
        std::cout << A.nome << " , " << std::fixed  << std::setprecision(1) <<  A.nota << std::endl;
    }

    if(A.nota == B.nota){
        std::cout << A.nome << " e " << B.nome << " , " << std::fixed  << std::setprecision(1) << A.nota << std::endl;
    }
}
