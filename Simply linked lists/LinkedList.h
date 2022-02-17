#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdexcept>
#include <iostream>

// Define um tipo de dado chamado Item,
// que é apenas um apelido para int
typedef int Item;

/*******************************************
 * Definição do struct Node
 *******************************************/
struct Node {
    Item data;    
    Node *next;  

    // Construtor do struct Node
    // Obs.: Em C++ os structs tambem podem ter construtores,
    // destrutores ou quaisquer outras funcoes que voce quiser.
    Node(const Item& k, Node *nextnode = nullptr) {
        data = k;
        next = nextnode;
    }
};

/*****************************************
 * Declaração da classe LinkedList
 *****************************************/
class LinkedList{
private:
    Node* m_head; // ponteiro para o primeiro elemento
    int m_size;   // número de elementos na lista

public:
    // Construtor
    LinkedList(); 

    // Destrutor
    ~LinkedList(); 

    // Devolve true se e somente se a lista estiver cheia
    bool empty();

    // Deixa a lista vazia, com zero elementos
    void clear();

    // Retorna o número de elementos atualmente na lista 
    int size();

    // adiciona elemento no final da lista
    void push_back(Item data);

    // remove elemento do final da lista
    void pop_back();

    // insere um elemento na posição index
    void insert(int index, Item data);

    // remove o elemento na posição index
    void remove(int index);
    
    // operador de indexação sobrecarregado como função-membro da classe
    Item& operator[](int index);

    // operador<< sobrecarregado como função global friend 
    friend std::ostream& operator<<(std::ostream& out, const LinkedList& l);  

    
    void concat(const LinkedList& lst);
    
    void removeAll(const Item& x);
    
    LinkedList *clone();
    
    void appendArray(Item v[], int n);
    
    bool equals(const LinkedList& lst);
    
    void reverse();
};

/***************************************************
 * Implementação das funções-membro da classe
 ***************************************************/

// Constructor: the linked list
// initializes empty
LinkedList::LinkedList() {
    m_size = 0;
    m_head = nullptr;
}

// Returs true if and only if the 
// list is empty
bool LinkedList::empty() {
    return m_head == nullptr;
}

// Empty the list and frees memory
void LinkedList::clear() {
    while(m_head != nullptr) {
        Node *temp = m_head;
        m_head = m_head->next;
        delete temp;
    }
    m_size = 0;
}

// Returns the size of the list
int LinkedList::size() {
    return m_size;
}

// Adds an element at the end of the list
void LinkedList::push_back(Item data) {
    Node *aux = new Node(data, nullptr);
    if(m_head == nullptr) {
        m_head = aux;
    } else {
        Node *current = m_head;
        while(current->next != nullptr) {
            current = current->next;
        }
        current->next = aux;
    }
    m_size++;
}

// Deletes an element from the end of the list
void LinkedList::pop_back() {
    if(m_head == nullptr) {
        throw std::underflow_error("empty list");
    }
    if(m_head->next == nullptr) {
        delete m_head;
        m_head = nullptr;
        m_size = 0;
        return;
    }
    Node *current = m_head;
    while(current->next->next != nullptr) {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
    m_size--;
}

// Inserts data at any position in the range [0..size()]
void LinkedList::insert(int index, Item data) {
    if(index < 0 || index > m_size) {
        throw std::out_of_range("index out of range");
    }
    if(index == 0) {
        Node *aux = new Node(data, m_head);
        m_head = aux;
        m_size++;
        return;
    }
    int counter = 0;
    Node *current = m_head;
    while(counter < index-1) {
        counter++;
        current = current->next;
    }
    Node *aux = new Node(data, current->next);
    current->next = aux;
    m_size++;
}

// Deletes data at any position in the range [0..size()-1]
void LinkedList::remove(int index) {
    if(index < 0 || index >= m_size) {
        throw std::out_of_range("index out of range");
    }
    if(index == 0) {
        Node *temp = m_head;
        m_head = m_head->next;
        delete temp;
        m_size--;
        return;
    }
    int counter = 0;
    Node *current = m_head;
    while(counter < index-1) {
        counter++;
        current = current->next;
    }
    Node *temp = current->next;
    current->next = current->next->next;
    delete temp;
    m_size--;
}

// Destructor
LinkedList::~LinkedList() {
    clear();
}

// operator[] overloaded
Item& LinkedList::operator[](int index) {
    if(index < 0 || index >= m_size) {
        throw std::out_of_range("index out of range");
    }
    int counter = 0;
    Node *current = m_head;
    while(counter < index) {
        counter++;
        current = current->next;
    }
    return current->data;
}

// operator<< overloaded
std::ostream& operator<<(std::ostream& out, const LinkedList& list) {
    Node *current = list.m_head;
    out << "[ ";
    while(current != nullptr) {
        out << current->data << " ";
        current =current->next;
    }
    out << "]";
    return out;
}


// Concatena a lista atual com a lista lst passada por parametro.
// A lista lst nao eh modificada nessa operacao. Ela permanece intacta ao final.
// Por exemplo, sejam l1 = [ 1 2 3 4 ] e l2 = [ 7 9 8 ]
// Após fazer l1.concat(l2) você deve obter
// l1 = [ 1 2 3 4 7 9 8 ] e l2 = [ 7 9 8 ]
// Restrição: está proibido usar funções auxiliares nesta questão,
// inclusive qualquer dos operadores sobrecarregados
void LinkedList::concat(const LinkedList& lst){
    Node *l2 = lst.m_head;
    if(l2 == nullptr){
        return;
    }else{
        while(l2 != nullptr){
            Node *l1 = m_head;
            Node *auxiliar = new Node(l2->data,nullptr);
            if(l1 == nullptr){
                m_head = auxiliar;
            }else{
                while(l1->next != nullptr){
                    l1 = l1->next;
                }
                l1->next = auxiliar;
            }
            m_size++;
            l2 = l2->next;
        }
    }
}

// Remove da lista todas as ocorrencias do Item x.
// Se a lista estiver vazia, esta funcao nao faz nada;
// Restricao: Esta funcao deve ter complexidade O(n) no pior caso.
// Restrição: está proibido usar funções auxiliares nesta questão,
// inclusive qualquer dos operadores sobrecarregados
void LinkedList::removeAll(const Item& x) {
    Node* original = m_head;
    Node* aux = m_head; 
    while(original != nullptr){
        if(  original->data == x){
            Node* atual;
            if(original == m_head){
                original = original->next;
                m_head = original;
                atual = aux;
                aux = original;
            }else{
                original = original->next;
                atual = aux->next;
                aux->next = original;
            }
            delete atual;
            m_size--;
        }else{
            original = original->next;
            if(aux->next != original)
                aux=aux->next;
        }
    }
} 



// Devolve um ponteiro para uma copia desta lista.
// Veja que uma copia nao eh a mesma lista, ela contem uma copia dos dados
// Esta funcao deve ter complexidade O(n) no pior caso
// Restrição: está proibido usar funções auxiliares nesta questão,
// inclusive qualquer dos operadores sobrecarregados
LinkedList *LinkedList::clone() {
    LinkedList *copia = new LinkedList();
    copia->m_head = new Node(m_head->data,nullptr);
    Node *ponteiro_copia=copia->m_head;
    Node *ponteiro_original=this->m_head;
    while(ponteiro_original->next!=nullptr){
        ponteiro_copia->next= new Node(ponteiro_original->next->data,nullptr);
        ponteiro_copia=ponteiro_copia->next;
        copia->m_size++;
        ponteiro_original=ponteiro_original->next;
    }
    return copia;
} 

// Copia os elementos do array v[0..n-1] para o final da lista. 
// Esta funcao deve ter complexidade O(n) no pior caso
// Restrição: está proibido usar funções auxiliares nesta questão,
// inclusive qualquer dos operadores sobrecarregados
void LinkedList::appendArray(Item v[], int n) {
    
    if(m_head == nullptr){
        m_head = new Node(v[0],nullptr);
        Node *original = m_head;
        int k=1;
        while(k < n){
                Node *trocar = new Node(v[k],nullptr);
                original->next = trocar;
                original = original->next;
                k++;
                m_size++;
        }
        return;
    }

    if(m_head != nullptr){
        
        Node *original = m_head;
        
        while(original->next != nullptr){
            original = original->next;
        }
        int k = 0;
        while(k < n){
            Node *troca = new Node(v[k],nullptr);
            original->next = troca;
            original = original->next;
            k++;
            m_size++;
        }
    }

}

// Determina se a lista lst, passada por parametro, eh igual 
// a lista em questao. Duas listas sao iguais se elas tem o mesmo tamanho 
// e o valor do k-esimo elemento da primeira lista eh igual ao 
// k-esimo valor da segunda lista.
// Restrição: está proibido usar funções auxiliares nesta questão,
// inclusive qualquer dos operadores sobrecarregados
bool LinkedList::equals(const LinkedList& lst) {
    if(m_size == lst.m_size){
        Node *l1 = m_head;
        Node *l2 = lst.m_head;
        while( l1 != nullptr){
            if(l1->data != l2->data){
                return false;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        return true;
    }else{
        return false;
    }
}

// Inverte a ordem dos nós (o primeiro node passa a ser o último, 
// o segundo passa a ser o penultimo, etc.) 
// Restricao: Essa operacao faz isso sem criar novos nodes, apenas altera os ponteiros.
// Voce pode criar ponteiros auxiliares (um número constante deles), 
// mas nao pode alocar novos nós.
// Repetindo: está proibido chamar o operador new nesta questão.
// Restrição: Também não é permitido usar funções auxiliares nesta questão
void LinkedList::reverse(){
        //Caso Primordial Funcionando ,amém.
    if(m_head == nullptr || m_head->next == nullptr){
        return;
    }else{
        //Transformei o primeiro em ultimo, funcionando, amém.
        Node *base = m_head;
        while(base->next != nullptr){
            base = base->next;
        }
        int trocar = base->data;
        base->data = m_head->data;
        m_head->data = trocar;
        
        base = nullptr;
        delete base;

        
        
        Node *atual = m_head->next->next;
        Node *anterior = m_head->next;
        Node *depois = m_head->next->next->next;
        if(anterior->next == nullptr){
            return;
        }
        
        int contador = 0;
        while(anterior->next != nullptr){
            anterior = anterior->next;
            contador++;
        }
        contador--;
        anterior = m_head->next;
        int voltas = 0;
        
        for(int i = 0; i<contador; i++ ){
            while(depois != nullptr){
                int mudar = atual->data;
                atual->data = anterior->data;
                anterior->data = mudar;
                atual = atual->next;
                anterior = anterior->next;
                depois = depois->next;
            }
            
            atual = m_head->next->next;
            anterior = m_head->next;
            depois = m_head->next->next->next;
            
            voltas++;
            for(int k = 0; k<voltas; k++){
                depois=depois->next;
            }
            
        }
    }
    }
    // OBS: MEU DEUS EU NEM ACREDITO QUE MEU REVERSE DEU CERTO, FORAM AS 58H 47M 29S MAIS BEM GASTAS DA MINHA VIDA!!!


#endif
