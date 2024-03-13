#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "listaDinEncadeada.h"

struct elemento{
    BO dados;
    struct  elemento *prox;
};

typedef struct elemento Elem;

//Cria lista
Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;

    return li;
}

//Libera lista
void libera_lista(Lista* li){
    if(li != NULL) {
        Elem *no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }

}

//Retorna tamanho da lista
int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(Lista* li){
    return 0;
}

// Checa lista vazia
int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if((*li) == NULL)
        return 1;

    return 0;
}

// Insere no inicio da lista
int insere_lista_inicio(Lista* li, BO bo){
    if(li == NULL)
        return 0;

    Elem* no = (Elem*) malloc(sizeof(Elem));

    if(no == NULL)
        return 0;

    no->dados = bo;
    no->prox = (*li);
    *li = no;
    return 1;
}

// Insere no final da lista
int insere_lista_final(Lista* li, BO bo){
    if(li == NULL)
        return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;

    no->dados = bo;
    no->prox = NULL;

    if((*li) == NULL){
        *li = no;
    }else{
        Elem *aux;
         aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }

    return 1;
}

//Insere na lista de forma ordenada
int insere_lista_ordenada(Lista* li, BO bo){
    if(li == NULL)
        return 0;
    Elem *no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = bo;
    if((*li) == NULL){ //insere inicio
        no->prox = NULL;
        *li = no;
        return 1;
    }else{
        Elem * ant, *atual = *li;
        while(atual != NULL && atual->dados.codigoBO < bo.codigoBO){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){ //insere inicio
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = atual->prox;
            ant->prox = no;
        }
        return 1;
    }
}

//Remove do inicio da lista
int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)
        return 0;

    Elem *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

//Remove do final da lista
int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)
        return 0;

    Elem *ant, *no = *li;
    while (no->prox != NULL){
        ant = no;
        no = no->prox;
    }
    if(no == (*li))
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);

    return 1;
}

//Remove elemento de um lugar especifico da lista
int remove_lista(Lista* li, int Bo){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;
    Elem *ant, *no = *li;
    while(no != NULL && no->dados.codigoBO != Bo){
        ant = no;
        no = no->prox;
    }

    if(no == NULL)
        return 0;

    if(no == *li)
        *li = no->prox;
    else
        ant->prox = no->prox;

    free(no);

    return 1;
}

//Consultar elemento na lista por posição
int consulta_lista_pos(Lista* li, int pos, BO *bo){
    if(li == NULL || pos <= 0)
        return 0;

    Elem *no = *li;
    int i =  1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    if(no == NULL)
        return 0;
    else{
        *bo = no->dados;
        return 1;
    }
}
//consulta por dados do codigoBO
int consulta_lista_boletim(Lista* li, int codig, BO *bo){

    if(li == NULL)
        return 0;
    Elem *no = *li;

    while(no != NULL && no->dados.codigoBO != codig){
        no = no->prox;
    }

    if(no == NULL)
        return 0;
    else {
        *bo = no->dados;
        return 1;
    }
}
//imprimir resultado da consulta
void imprime_consulta(Lista* li, int codig, BO *bo){
  
    if(li == NULL)
        return;
    Elem *no = *li;

    while(no != NULL && no->dados.codigoBO != codig){
        no = no->prox;
    }
    if(no == NULL)
        return;
    else {
        *bo = no->dados;}
  
      printf("Nome do reclamante: %s\n", no->dados.reclam.nome);
    	printf("Telefone do reclamante: %d\n", no->dados.reclam.tel);
      printf("Codigo do reclamante: %d\n", no->dados.reclam.codigoReclam);
    	printf("Data do boletim: %s\n", no->dados.dataBO);
      printf("Codigo gerado do boletim: %d\n", no->dados.codigoBO);
      printf("Data do crime ocorrido: %s\n", no->dados.crim.dataCrim);
      printf("Codigo do crime gerado pelo sistema: %d\n", no->dados.crim.codigoCrim);
      printf("Descricao do caso ocorrido: %s\n", no->dados.crim.descricao);
      printf("Tipo do crime cometido: %s\n", no->dados.crim.tipo);
  
}

// Q1 - Imprimir a lista
void imprimir_lista(Lista * li){
  
  if(lista_vazia(li))
      printf("lista vazia\n");
  if(li == NULL)
        return;
  Elem *no = *li;

    while(no != NULL){
    	printf("Nome do reclamante: %s\n", no->dados.reclam.nome);
    	printf("Telefone do reclamante: %d\n", no->dados.reclam.tel);
      printf("Codigo do reclamante: %d\n", no->dados.reclam.codigoReclam);
    	printf("Data do boletim: %s\n", no->dados.dataBO);
      printf("Codigo gerado do boletim: %d\n", no->dados.codigoBO);
      printf("Data do crime ocorrido: %s\n", no->dados.crim.dataCrim);
      printf("Codigo do crime gerado pelo sistema: %d\n", no->dados.crim.codigoCrim);
      printf("Descricao do caso ocorrido: %s\n", no->dados.crim.descricao);
      printf("Tipo do crime cometido: %s\n", no->dados.crim.tipo);
      printf("\n");
        
      no = no->prox;
    }
}
// criando o arquivo obs: n reutilizavel
FILE cria_arq_lista(){
    FILE *fp;
  fp = fopen("listaBO.txt", "w");
  if(fp == NULL)
    printf("Erro!\n");
  return *fp;
}
//inserindo os dados no arquivo anonimo
void abrirArq_lista(Lista * li2,FILE *fp2){
     if(li2 == NULL)
        return;
     Elem* no = *li2;
    fp2 = fopen("lista_Anonima.bin", "a+b");

    fwrite(no->dados.crim.dataCrim,sizeof(char),strlen(no->dados.crim.dataCrim),fp2);
    fwrite(no->dados.crim.tipo,sizeof(char),strlen(no->dados.crim.tipo),fp2);
    fwrite(no->dados.crim.descricao,sizeof(char),strlen(no->dados.crim.descricao),fp2);
       
    fclose(fp2);    
}
//menu de alteracao
void Menu_editarbo(Lista *li){
    if(lista_vazia(li)){
        printf("\n\nLista vazia\n\n"); 
        return;}
  
    printf("\n-------QUE DADOS DESEJA MUDAR?---------\n");
    printf("1-Alterar nome\n2-Alterar telefone\n3-Alterar codigo do BO\n");
    printf("4-Alterar data\n5-Alterar codigo do crime\n6-Alterar data do crime\n");
    printf("7-Alterar descricao\n8-Alterar o tipo de crime\n9-Sair\n");
  
}
//opcao de editar os dados
void Editar_dados_bo(Lista* li, int codig){
     int opcao, x=0;
     if(lista_vazia(li))
        return;
      Elem *no = *li;
      while(no->dados.codigoBO != codig){
           no = no->prox;
      }
      
     do{
       scanf("%d",&opcao);
       switch(opcao){
        case 1:
           printf("Altere o nome:\n");
           scanf("%s", no->dados.reclam.nome); break;
        case 2:
           printf("Altere o telefone\n");
           scanf("%d",&no->dados.reclam.tel); break;
        case 3:
           printf("Altere o codigo do BO:\n");
           scanf("%d",&no->dados.codigoBO); break;
        case 4:
           printf("Alterar a data:\n");
           scanf("%s", no->dados.dataBO);break;
        case 5:
           printf("Altere o codigo do crime:\n");
           scanf("%d",&no->dados.crim.codigoCrim);break;
        case 6:
          printf("Altere a data do crime:\n");
          scanf("%s", no->dados.crim.dataCrim);break;
        case 7:
          printf("Altere a descricao");
          scanf("%s", no->dados.crim.descricao);break;
        case 8:
          printf("Altere o tipo do crime");
          scanf("%s", no->dados.crim.tipo); break;
        case 9:
          x=1; break;
         default:
           printf("opcao invalida\n"); break;
         }
       Menu_editarbo(li);
      }while(x==0);
     
}
// opcao de qual bo excluir
int ExcluirBO (Lista* li)
{
  int choice;
  if(lista_vazia(li)){
    printf("lista vazia!");
    return 0;}
    
  else
     printf("\n Digite o codigo(BO) de quais desses BO voce deseja excluir?\n\n");
     imprimir_lista(li);
     scanf("%d", &choice);
     remove_lista(li, choice);

  return choice;

}
//salvar mudanças no arquivo
void SalvarArq (Lista *li, FILE* fp, int y){
    FILE *fp2;
    Elem *no = *li;
    fp2= fopen("listaBO_temp.txt","w");
    if(fp2 == NULL)
        printf("Erro!\n");
    fp = fopen("listaBO.txt", "w");
    if(fp == NULL)
        printf("Erro!\n");
  
    while(no!=NULL){ 
        if(y!=no->dados.codigoBO){
         fprintf(fp2,"%s\n%d\n",no->dados.reclam.nome,no->dados.reclam.tel);
         fprintf(fp2,"%d\n",no->dados.reclam.codigoReclam); 
         fprintf(fp2,"%s\n%d\n",no->dados.dataBO,no->dados.codigoBO);
         fprintf(fp2,"%s\n%d\n",no->dados.crim.dataCrim,no->dados.crim.codigoCrim);
         fprintf(fp2,"%s\n%s\n",no->dados.crim.descricao,no->dados.crim.tipo);
          no = no->prox;
        }}
        
    fclose(fp2);
    fclose(fp);
    remove("listaBO.txt");
    rename("listaBO_temp.txt","listaBO.txt");
      
}
// Desenvoolvedora: Emillyn  ?( ?° ?? ?°)?
void NovoBo (Lista* li, FILE *fp){

  BO boFilho;
  int i=0,j,igual,num_aleatorio[1000];
  srand(time(NULL));

  do{
      num_aleatorio[i] = 1+ rand()%999;
      igual=0;
      for(j=0; j<i; j++){
         if(num_aleatorio[j]==num_aleatorio[i])
            igual=1;
      }
      if(igual==0)
         i++; 
      
      boFilho.codigoBO = num_aleatorio[i-1];
      boFilho.crim.codigoCrim = num_aleatorio[i-2];
      boFilho.reclam.codigoReclam = num_aleatorio[i-3];
      
  }while(i<999);
  
  
  printf("---------------Primeiro os dados do reclamante---------------\n");
  printf(" Insira seu nome:\n");
  scanf("%s", boFilho.reclam.nome);   
  printf("Telefone de contato:\n");
  scanf("%d", &boFilho.reclam.tel);
  printf("Codigo do reclamante: %d\n",boFilho.reclam.codigoReclam);
  printf("---------------Agora as informacoes do crime---------------\n");
  printf("Data do ocorrido:\n");
  scanf("%s", boFilho.crim.dataCrim);   
  printf("Codigo gerado pelo sistema: %d\n", boFilho.crim.codigoCrim);
  printf("Digite a Descricao do ocorrido:\n");
  scanf("%s", boFilho.crim.descricao);
  printf("Tipo de crime:\n");
  scanf("%s", boFilho.crim.tipo);   
  printf("---------------Agora as informacoes do BO---------------\n");
  printf("Data do BO:\n");
  scanf("%s", boFilho.dataBO);   
  printf("Codigo do BO gerdado pelo sistema: %d\n", boFilho.codigoBO);
  printf("Boletim finalizado! Sera encamminhado as autoridades mais proximas!\n ");
  
  if(lista_vazia(li))
     insere_lista_inicio(li,boFilho);
  else  
     insere_lista_final(li, boFilho);
  return;
   
}
//ler arquivo e adicionar na lista
void ler_arquivo(Lista* li, BO bo, FILE *fp){
  
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return;
     fp = fopen("listaBO.txt", "r");
     if(fp == NULL)
        printf("Erro!\n");   
    
     char a[30],b[9],c[9],d[60],e[30];
     int x,y,w,z;
      
      while(fscanf(fp,"%s\n%d\n%d\n%s\n%d\n%s\n%d\n%s\n%s\n",a,&x,&y,b,&w,c,&z,d,e)!= EOF){

      strcpy(no->dados.reclam.nome,a);
      no->dados.reclam.tel=x;
      no->dados.reclam.codigoReclam=y;
      strcpy(no->dados.dataBO,b);
      no->dados.codigoBO=w;
      strcpy(no->dados.crim.dataCrim,c);
      no->dados.crim.codigoCrim=z;
      strcpy(no->dados.crim.descricao,d);
      strcpy(no->dados.crim.tipo,e);
      bo=no->dados;  
      insere_lista_final(li,bo);}

     free(no);        
     fclose(fp);
     
}
//denuncia anonima por eduardo pereira
void arqui_anonimo(Lista *li2, FILE *fp2, BO bo){
     if(li2 == NULL)
        return;
     printf("\n=====PREENCHA OS DADOS DO CADASTRO ANONIMO=====\n");
     printf("Digite a data do ocorrido\n");
     scanf("%s", bo.crim.dataCrim);
     printf("Diga o tipo de ocorrido\n");
     scanf("%s", bo.crim.tipo);
     printf("digite a discricao do ocorrido\n");
     scanf("%s", bo.crim.descricao);
     printf("Processo finalizado!\nLembramos que a denuncia anonima nao\n");
     printf("equivale a um boletim de ocorrencia\nobs: voce nao tera acesso a esses dados\n");
  
     if(lista_vazia(li2))
        insere_lista_inicio(li2,bo);
     else  
        insere_lista_final(li2, bo);
       return;
}
