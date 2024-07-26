#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int dado;
  struct no *prox;
} no;

// protótipos das funções
void criarLista(no **lista);
int estaVazia(no **lista);
int tamLista(no **lista);
void imprimirListaPosicao(no **lista, int pos);
void inserirListaPosicao(no **lista, int pos, int valor);
void removerListaPosicao(no **lista, int pos);
void imprimirLista(no *lista);

void printMenu() { // menu de exibição do switch case
  printf("\n MENU \n");
  printf("1 - Verificar se esta vazia\n");
  printf("2 - Verificar tamanho da lista\n");
  printf("3 - Imprimir elemento de uma determinada posicao na lista\n");
  printf("4 - Inserir elemento na posicao na lista\n");
  printf("5 - Remover elemento na posicao lista\n");
  printf("6 - Imprimir toda a lista\n");
  printf("0 - Sair\n");
}

int main(void) {
  no *lista;
  int op, pos, valor;
  criarLista(&lista);

  do {
    printMenu();
    scanf("%d", &op);

    switch (op) {
    case 1:
      if (estaVazia(&lista)) {
        printf("A lista esta vazia\n");
      } else {
        printf("A lista nao esta vazia\n");
      }
      break;
    case 2:
      printf("Tamanho da lista: %d\n", tamLista(&lista));
      break;
    case 3:
      printf("Digite a posicao: ");
      scanf("%d", &pos);
      imprimirListaPosicao(&lista, pos);
      break;
    case 4:
      printf("Digite a posicao: ");
      scanf("%d", &pos);
      printf("Digite o valor: ");
      scanf("%d", &valor);
      inserirListaPosicao(&lista, pos, valor);
      break;
    case 5:
      printf("Digite a posicao: ");
      scanf("%d", &pos);
      removerListaPosicao(&lista, pos);
      break;
    case 6:
      imprimirLista(lista);
      break;
    default:
      if (op != 0) {
        printf("Opcao invalida\n");
      }
    }

  } while (op != 0);

  return 0;
}

// função para inicia a lista
void criarLista(no **lista) { *lista = NULL; }

// função para verificar se a lista esta vazia
int estaVazia(no **lista) { return *lista == NULL; }

// função retorna o tamanho da lista
int tamLista(no **lista) {
  no *atual = *lista;
  int tam = 0;
  while (atual != NULL) {
    tam++;
    atual = atual->prox;
  }
  return tam;
}

// função para imprimir um elemento de uma determinada posição
void imprimirListaPosicao(no **lista, int pos) {
  if (pos < 1 || pos > tamLista(lista)) {
    printf("Posicao %d invalida\n", pos);
    return;
  }

  no *atual = *lista;
  int contador = 1;
  while (atual != NULL && contador < pos) {
    atual = atual->prox;
    contador++;
  }

  if (atual != NULL) {
    printf("Elemento na posicao %d: %d\n", pos, atual->dado);
  } else {
    printf("Posicao %d invalida\n", pos);
  }
}

// função para inserir um elemento na posição desejada
void inserirListaPosicao(no **lista, int pos, int valor) {
  if (pos < 1 || pos > tamLista(lista) + 1) {
    printf("Posicao %d invalida\n", pos);
    return;
  }

  no *novoNo = (no *)malloc(sizeof(no));
  novoNo->dado = valor;
  novoNo->prox = NULL;

  if (pos == 1) {
    novoNo->prox = *lista;
    *lista = novoNo;
    return;
  }

  no *atual = *lista;
  int contador = 1;
  while (atual != NULL && contador < pos - 1) {
    atual = atual->prox;
    contador++;
  }

  novoNo->prox = atual->prox;
  atual->prox = novoNo;
}

// função para remover um elemento na posição desejada
void removerListaPosicao(no **lista, int pos) {
  if (*lista == NULL) {
    printf("Lista vazia\n");
    return;
  }

  if (pos < 1 || pos > tamLista(lista)) {
    printf("Posicao %d invalida\n", pos);
    return;
  }

  no *temp = *lista;

  if (pos == 1) {
    *lista = temp->prox;
    free(temp);
    return;
  }

  no *anterior = NULL;
  int contador = 1;

  while (temp != NULL && contador != pos) {
    anterior = temp;
    temp = temp->prox;
    contador++;
  }

  if (temp == NULL) {
    printf("Posicao %d invalida\n", pos);
    return;
  }

  anterior->prox = temp->prox;
  free(temp);
}

// função imprimir toda a lista
void imprimirLista(no *lista) {
  no *atual = lista;

  if (atual == NULL) {
    printf("Lista vazia\n");
    return;
  }

  while (atual != NULL) {
    printf("%d ", atual->dado);
    atual = atual->prox;
  }
  printf("\n");
}
