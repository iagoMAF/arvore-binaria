/* Implementação do código para a árvore binária de busca
Disciplina: AEDS III
Docente: Marcelo Ferreira Rego
Integrantes: Camila A. Martins, Iago M. A. Fernandes, Lucas A. Barbosa, Mariano C. Silva, Mateus H. Machado e Thiago J. de Sousa
*/

#include <iostream>
#include <stdlib.h>
using namespace std;  

struct No {
    int valor;
    No *esquerdo;
    No *direito;
};

class Arvore { 
    public: No *raiz; 
    
    //Inicializando a árvore
    public: Arvore() { raiz = NULL; } 

    public: void inserir(int v) {
        No *novo = new No();  //Criando um novo No
        novo->valor = v;     //Colando o valor ao novo No
        novo->direito  = NULL;
        novo->esquerdo = NULL;
        
	  if (raiz == NULL) raiz = novo;
        else  { //Condição se não for uma raiz
            No *atual = raiz;
            No *anterior;
        while(true) {
            anterior = atual;

//Se o valor for atribuído na esquerda        
if (v <= atual->valor){ 
             atual = atual->esquerdo;
             if (atual == NULL){
                anterior->esquerdo = novo;
                return;}}  
        else{ //Se o valor for atribuído na direita
           atual = atual->direito;
           if (atual == NULL){
                anterior->direito = novo;
                return;} } } } }
   
 public: No *buscar(int chave) {
        //Condição - se a árvore estiver vazia
	 if (raiz == NULL) return NULL;          
	 No *atual = raiz;  
        while (atual->valor != chave) {
		//Pela esquerda 
            if(chave < atual->valor ) atual = atual->esquerdo; 
  		// Pela direita
            else atual = atual->direito;                         
            if (atual == NULL) return NULL;} 
return atual;}

    public: No *Remover(No *atual, int v) {
        
        No* temporario;
        int dadotemp; 
        
        //Caso base - Tem o elemento
        if (atual->valor == v){       
            //I - Nó folha
            if (atual->esquerdo == NULL && atual->direito == NULL){
                delete atual; 
                return NULL;}
            
		//II.a Apenas um filho à esquerda
            else if (atual->direito == NULL){
                temporario = atual->esquerdo;
                delete atual; 
                return temporario; }
            
		//II.b Apenas um filho à direita
            else if (atual->esquerdo == NULL){
                temporario = atual->direito;
                delete atual;
                return temporario; }
            

            //III. Nó possui dois filhos
            else if (atual->esquerdo != NULL && atual->direito != NULL){

//Encontra aquele que irá substituir o nó removido (usa o maior valor, ou seja, à direita)
                temporario = atual->direito;
//Encontra o nó de menor valor ao considerar a subárvore à direita
                while (temporario->esquerdo != NULL){
                    temporario = temporario->esquerdo;}
                dadotemp = atual->valor;
                atual->valor = temporario->valor;
                temporario->valor = dadotemp;
                atual->direito = Remover(atual->direito, temporario->valor);}
        }
        //Caso não tenha o elemento
        else if (atual == NULL){
            return atual;}
        else if (v < atual->valor){
            atual->esquerdo = Remover(atual->esquerdo, v);}
        else if (v > atual->valor){
            atual->direito = Remover(atual->direito, v);}
        return atual;}
    
  
    public: void imprimir() {
        cout << "\n\n";
        cout << "Percorrendo Pré-Ordem\n";
        preOrder(raiz);
        cout << "\nPercorrendo Em-Ordem\n";
        inOrder(raiz);
        cout << "\nPercorrendo Pós-Ordem\n";
        posOrder(raiz);
    }
    private: void inOrder(No *atual) {
        if (atual != NULL) {
        inOrder(atual->esquerdo);
        cout << atual->valor << " ";
        inOrder(atual->direito);}}
    
   private: void posOrder(No *atual) {
        if (atual != NULL) {
            posOrder(atual->esquerdo);
            posOrder(atual->direito);
            cout << atual->valor << " ";}}
  
    private: void preOrder(No *atual) {
        if (atual != NULL) {
            cout << atual->valor << " ";
            preOrder(atual->esquerdo);
            preOrder(atual->direito);}}
};

int main() {
    Arvore arv;
    int opcao, x;
    do {
        cout << "\n    O que voce deseja fazer?";
		cout << "\n[1] para Inserir";
		cout << "\n[2] para Excluir" ;
		cout << "\n[3] para Pesquisar";
		cout << "\n[4] para mostrar a arvore";
		cout << "\n[5] para terminar o programa";
		cout << "\n    Digite sua escolha: ";
		cin >> opcao;
		switch(opcao) {

	 		case 1: {
		       cout << "\nDigite o valor a ser inserido: ";
		       cin >> x;
		       arv.inserir(x);
		       break;
			}


			case 2: {
		       cout << "\nDigite o valor a ser excluido: ";
		       cin >> x;
		       
		       if (arv.buscar(x)==NULL){
		           cout << "\nO valor não foi encontrado\n";
		           break;
		       }
		       
		       arv.raiz = arv.Remover(arv.raiz, x);
               break;
			}

			case 3: {
		       cout << "\nDigite o valor a ser encontrado: ";
              	 cin >> x;
	      	   	 if( arv.buscar(x) != NULL )
		          cout << "\nO numero informado foi encontrado!\n";
		       else 
		          cout << "\nO numero informado nao encontrado!\n";
		       break;
			}
	 
			case 4: {
		      arv.imprimir();
		      break; 
			}
        }
    } while(opcao != 5);
}