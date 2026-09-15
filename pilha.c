#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct no{
    char nome[20];
    struct no *next;
    struct no *back;
}no;

struct no *topo = NULL;
struct no *auxiliar = NULL;
int qtdePilha = 0;

void inserir(){
    printf("Inserir Nome: \n");
    scanf("%s", &auxiliar->nome);
}


void push(){
        if(topo == NULL){
            auxiliar = (no*)malloc(sizeof(no));
            topo = auxiliar;
            auxiliar->back = NULL;
            auxiliar->next = NULL;
            qtdePilha++;
            inserir();
        }else{
            if(qtdePilha >= 10){
                printf("Stack Overflow \n");
            }else{
                auxiliar = (no*)malloc(sizeof(no));
                auxiliar->back = topo;
                auxiliar->next = NULL;
                topo->next = auxiliar;
                topo = auxiliar;
                qtdePilha++;
                inserir();
            }
        }
}

void top(){
    if(topo == NULL){
        printf("Stack is Empty \n");
    }else{
        printf("Topo da pilha: %s \n \n", topo);
    }

}

void pop(){
    if(topo == NULL){
        printf("Stack is Empty \n");
    }else{
        if(topo->next==NULL && topo->back==NULL){
            free(topo);
            topo = NULL;
            qtdePilha = 0;
        }else{
            auxiliar = topo->back;
            auxiliar->next = NULL;
            free(topo);
            topo = auxiliar;
            qtdePilha--;
        }
        printf("Removido! \n");
    }
}

void listarPilha(){
    if(topo == NULL){
        printf("Pilha vazia \n");
    }else{
        auxiliar = topo;
        while(auxiliar != NULL){
            printf(auxiliar->nome);
            printf("\n");
            auxiliar = auxiliar->back;
        }
        printf("\n Quantidade de Itens na Pilha: %d \n", qtdePilha);
    }

}

int main(){
    int op = 0;
    while(op != 5){
        printf("===== OPERACOES ===== \n");
        printf("(1) - push \n");
        printf("(2) - pop \n");
        printf("(3) - top \n");
        printf("(4) - Listar Pilha \n");
        printf("(5) - Sair \n");
        printf("===================== \n");
        scanf("%d", &op);
        switch(op){
            case 1:
                system("clear");
                push();
                break;
            case 2:
                system("clear");
                pop();
                break;
            case 3:
                top();
                break;
            case 4:
                system("clear");
                listarPilha();
                break;
            case 5:
                break;
            default:
                break;
        }
    }
}


