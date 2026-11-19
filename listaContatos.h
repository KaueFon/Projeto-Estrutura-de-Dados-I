# define MAX 100

Typedef struct cliente{

int ID;
char nome[100];
char empresa[50];
char departamento[50];
char telefone;
char celular;
char email[100];
struct cliente *prox;
}CLIENTE;

typedef struct Listacont LISTA;

int tamanhoLista(Lista *li); //prtótipo da função que pega o tamanho da lista

void apagaLista(Lista *li); //prototipo da função para apagar lista

int insereOrdenado(Lista *li, CLIENTE al); //prototipo da função que insere de forma ordenada

int listaVazia(Lista *li); //protoripo da função que checa se a lista está vazia

int removeOrdenado(Lista *li, int mat)