#include <iostream>
#include <iomanip>
#include "Matriz.h"

// Aloca espaco para matriz n por m
Matriz::Matriz(int n, int m){
	matriz = new int*[n];
	for(int i=0; i<n; i++){
		matriz[i] = new int[m];   
	}
	lin = n;
	col = m;
	
}   

// Destrutor: Libera a memoria da matriz
Matriz::~Matriz(){
	for(int i=0; i<lin; i++){
		delete[] matriz[i];
	}
	delete matriz;
	std::cout << "Matriz Liberada" << std::endl;
}     

// Retorna o valor do elemento [i][j]
int Matriz::valor(int i, int j) {
	return matriz[i][j];
} 

// Atribui valor ao elemento [i][j]
void Matriz::atribui(int valor, int i, int j) {
	matriz[i][j] = valor;
}

// Retorna o numero de linhas da matriz
int Matriz::linhas() {
	return lin;
} 

// Retorna o numero de colunas da matriz
int Matriz::colunas() { 
	return col;
}

// Imprime matriz --- Ja esta codificado 
void Matriz::imprime(int largura) {
	for (int linha = 0; linha < lin; linha++) {
		for (int coluna = 0; coluna < col; coluna++) {
			std::cout << std::setw(largura) << matriz[linha][coluna];
		}
		std::cout << std::endl;
	}
} 

// Soma matrizes
Matriz *Matriz::soma(Matriz *B) {
	if(lin != B->linhas() || col != B->colunas()){
		return nullptr;
	}else{
		Matriz *Resultante = new Matriz(lin,col);
		for(int i=0; i<lin; i++){
			for(int j=0; j<col; j++){
				int somando = matriz[i][j] + B->valor(i,j);
				Resultante->atribui(somando,i,j);
			}
		}
		return Resultante;
	}
}

// Multiplica matrizes
Matriz *Matriz::multiplica(Matriz *B){
	if(lin != B->colunas()){
		return nullptr;
	}else{
		Matriz *Resultante = new Matriz(lin,col);
		for(int i=0; i<lin; i++){
			for(int j=0; j<col; j++){
				int multiplicando = matriz[i][j] * B->valor(i,j);
				Resultante->atribui(multiplicando,i,j);
			}
		}
		return Resultante;
	}
}
