#ifndef BST_H
#define BST_H
#include <stdexcept>
#include <iostream>
#include <stack>

/*******************************
 * Definicao do struct Node
 *******************************/
struct Node {
    int key;
    Node *left;
    Node *right;

    Node(int k, Node *l, Node *r)
        : key(k), left(l), right(r) 
        { }

    ~Node() {
        std::cout << "Node removed: " << this->key << std::endl;
    }
};

/*******************************
 * class BST
 *******************************/
class BST { // classe BST (Binary Search Tree)
public:
    BST();
    ~BST();
    void bshow();
    void add(int key);       // Adicionar chave 
    bool contains(int key);  // contem chave key?
    int minimum();           // Devolve chave minima
    int maximum();           // Devolve chave maxima
    int successor(int k);    // Devolve chave sucessora de k
    int predecessor(int k);  // Devolve chave antecessora de k
private:
    Node *root;
    void bshow(Node *node, std::string heranca);
    Node *add(Node *node, int key);
    Node *search(Node *node, int key);
    Node *clear(Node *node);
    Node *minimum(Node *node);                          // ----> implementar
    Node *maximum(Node *node);                          // ----> implementar
    Node *sucessor(Node *x, Node *raiz);                // ----> implementar
    Node *predecessor(Node *x, Node* raiz);             // ----> implementar
    Node *ancestral_sucessor(Node *x, Node *raiz);      // ----> implementar
    Node *ancestral_predecessor(Node *x, Node* raiz);   // ----> implementar
};

BST::BST() {  // Construtor
    root = nullptr; 
} 
    
BST::~BST() {  // Destrutor
    root = clear(root);
} 

// Esta funcao recebe um ponteiro para um node e libera
// os nos da arvore enraizada nesse node. A funcao devolve
// nullptr apos apagar a arvore enraizada em node
Node *BST::clear(Node *node) {  
    if(node != nullptr) {
        node->left = clear(node->left);
        node->right = clear(node->right);
        delete node;
    }
    return nullptr;
}

// Esta funcao recebe um ponteiro para node e uma key e:
// (1) devolve nullptr caso key nao esteja na arvore;
// (2) devolve um ponteiro para o no contendo key caso contrario.
Node *BST::search(Node *node, int key) {
    if(node == nullptr || node->key == key)
        return node;
    if(key > node->key)
        return search(node->right, key);
    else 
        return search(node->left, key);
} 

bool BST::contains(int key) {
    return search(root, key) != nullptr;
}
 
// Esta funcao insere o no com chave key na arvore
// enraizada em node, somente se a chave key nao for repetida.
// Devolve um ponteiro para a raiz da nova arvore 
// enraizada em node.
Node *BST::add(Node *node, int key) {
    if(node == nullptr) { // Condicao de Parada
        node = new Node(key, nullptr, nullptr);
        return node;
    }
    // Casos Gerais
    if(key > node->key)
        node->right = add(node->right, key);
    else if(key < node->key)
        node->left = add(node->left, key);
    return node;
} 

void BST::add(int key) {
    root = add(root, key);
}

// Recebe um ponteiro para a arvore enraizada em node e:
// (1) devolve o ponteiro para o no contendo o minimo; ou
// (2) devolve nullptr se a arvore for vazia.
Node *BST::minimum(Node *node) {
    if(node == nullptr || node->left == nullptr){
        return node;
    }else{
        return minimum(node->left);
    }
}

// funcao publica. Devolve a chave minima da arvore
int BST::minimum() {
    if(root == nullptr){
        throw std::out_of_range("ERROR: Arvore Vazia");
    }else{
        return minimum(root)->key;
    }
}

// Recebe um ponteiro para a arvore enraizada em node e:
// (1) devolve o ponteiro para o no contendo o maximo; ou
// (2) devolve nullptr se a arvore for vazia.
Node *BST::maximum(Node *node){
    if(node == nullptr || node->right == nullptr){
        return node;
    }else{
        return maximum(node->right);
    }
}

// Funcao publica. Devolve a chave maxima da arvore
int BST::maximum() {
    if(root == nullptr){
        throw std::out_of_range("ERROR: Arvore Vazia");
    }else{
        return maximum(root)->key;
    }
}

// Devolve o ponteiro para o no sucessor do no x
// passado como parametro. A funcao tambem recebe
Node *BST::sucessor(Node *x, Node *raiz) {
    if(raiz->key > x->key && raiz->left != nullptr){
        raiz = sucessor(x, raiz->left);
    }else if(raiz->key < x->key && raiz->right != nullptr){
        raiz = sucessor(x, raiz->right);
    }
    if(raiz == x){
        if(raiz->right != nullptr){
            raiz = sucessor(x, raiz->right);
        }else{
            raiz = ancestral_sucessor(x, root);
        }
    }
    return raiz;
}

Node *BST::ancestral_sucessor(Node *x, Node *raiz) {
    if(raiz->right == x){
        throw std::runtime_error(x->key + "nao tem sucessor ou nao esta na arvore");
    }else if(raiz->left == x){
        return raiz;
    }
    if(raiz->key > x->key){
        raiz = ancestral_sucessor(x, raiz->left);
    }else if(raiz->key < x->key){
        raiz = ancestral_sucessor(x, raiz->right);
    }
}

int BST::successor(int k) {
    if(root == nullptr){
        throw std::runtime_error("erro: arvore vazia");
    }
    if(k == maximum()){
        throw std::runtime_error(k + "nao tem sucessor ou nao esta na arvore");
    }
    std::stack<Node*> pilha;
    Node *aux;
    Node *x;
    pilha.push(root);
    while(true){
        aux = pilha.top();
        pilha.pop();
        if(aux->key > k && aux->left != nullptr){
            pilha.push(aux->left);
        }else if(aux->key < k && aux->right != nullptr){
            pilha.push(aux->right);
        }else if(aux->key == k){
            x = aux;
            break;
        }else{
            throw std::runtime_error(k + "nao tem sucessor ou nao esta na arvore");
        }
    }
    Node *suc = sucessor(x, root);
    return suc->key;
}

// Retorna o ponteiro para o no antecessor do no x
// passado como parametro. A funcao tambem recebe 
// como parametro a raiz da arvore.
Node* BST::predecessor(Node *x, Node* raiz) {
    if(raiz->key > x->key && raiz->left != nullptr){
        raiz = predecessor(x, raiz->left);
    }else if(raiz->key < x->key && raiz->right != nullptr){
        raiz = predecessor(x, raiz->right);
    }
    if(raiz == x){
        if(raiz->left != nullptr){
            raiz = predecessor(x, raiz->left);
        }else{
            raiz = ancestral_predecessor(x, root);
        }
    }
    return raiz;
}

Node *BST::ancestral_predecessor(Node *x, Node* raiz) {
    if(raiz->left == x){
        throw std::runtime_error(x->key + "nao tem antecessor ou nao esta na arvore");
    }else if(raiz->right == x){
        return raiz;
    }
    if(raiz->key < x->key && raiz->right->key < x->key){
        raiz = ancestral_predecessor(x, raiz->right);
    }else if(raiz->key > x->key && raiz->left->key < x->key){
        raiz = ancestral_predecessor(x, raiz->left);
    }
    return raiz;
}

int BST::predecessor(int k) {
    if(root == nullptr){
        throw std::runtime_error("erro: arvore vazia");
    }
    if(k == minimum()){
        throw std::runtime_error(k + "nao tem antecessor ou nao esta na arvore");
    }
    std::stack<Node*> pilha;
    Node *aux;
    Node *x;
    pilha.push(root);
    while(true){
        aux = pilha.top();
        pilha.pop();
        if(aux->key > k && aux->left != nullptr){
            pilha.push(aux->left);
        }else if(aux->key < k && aux->right != nullptr){
            pilha.push(aux->right);
        }else if(aux->key == k){
            x = aux;
            break;
        }else{
            throw std::runtime_error(k + "nao tem antecessor ou nao esta na arvore");
        }
    }
    Node *ant = predecessor(x, root);
    return ant->key;
}

#endif