#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listaDinEncadeada.h"

int main() {
   //Boletim e seus dados
     int codigoc, z, opcao, sair=0, i;
     int choice, y, escolha;

     BO dados_boletim, nomec;
  
    //criar lista e criar arquivo
   Lista *li2= cria_lista(),*li = cria_lista();
   FILE fp, fp2;     
  
  do{
     printf("\n================MENU DE OPCOES================\n");
     printf("1-Deseja fazer um BO?\n2-Deseja procurar um boletim ?\n");
     printf("3-Deseja alterar os dados do BO?\n4-Deseja excluir um BO?\n");
     printf("5-Salvar dados do BO\n6-Abrir arquivo\n7-Lista de BOs\n8-Denuncia anonima\n9-Sair\n");
     printf("obs: digite o numero da opcao para escolhe la\n");
     scanf("%d",&opcao);
     switch(opcao){

       case 1://Novo boletim
           NovoBo (li,&fp); break;
       
       case 2://Consultar a lista
           printf("Digite o codigo do BO\n");
           scanf("%d", &codigoc);
           printf("Digite o nome do BO\n");
           scanf("%s", nomec.reclam.nome);
           z = consulta_lista_boletim(li, codigoc,&nomec);
  
           if(z == 0)
             printf("\nNao encontrado\n");
              
          else
             printf("\nBO encontrado\n\n");
             imprime_consulta(li, codigoc,&nomec); break;
       
       case 3://Editar os dados da lista
            printf("Digite o codigo do BO\n");
            scanf("%d", &codigoc);
            Menu_editarbo(li);
            Editar_dados_bo(li,codigoc); break;
          
       case 4://Exlcuir da lista e arquivo
           y = ExcluirBO(li);
           printf("\nLista atualizada:\n\n");
           imprimir_lista(li); break;
       
       case 5://Salvar no arquivo
          
          SalvarArq(li,&fp, y); break;

       case 6://abrir arquivo para lista
          ler_arquivo(li,dados_boletim,&fp); break;
        
       case 7:
          imprimir_lista(li); break;

       case 8://fazer denuncia anonima
          printf("\nNESSA OPCAO VOCE NAO PODERAR EDITAR, EXCLUIR OU CONSULTAR A DENUNCIA POR MOTIVOS DE SEGURANCA E SIGILO\n");
          printf("deseja continuar com a denuncia?\nDigite (1) para sim\nDigite (2) para nao\n");
          scanf("%d",&escolha);
          if(escolha==1){
             arqui_anonimo(li2,&fp2,dados_boletim);
             abrirArq_lista(li2,&fp2); break;
             
           }
          else
            break;
          
       
       case 9://Finalizar procedimento
           sair=1; break;
       
       default:
          printf("OPCAO INVALIDA!!!\n"); break;
     }    
  }while(sair == 0);
  
    //liberar lista
    libera_lista(li);


    system("pause");
    //return 0;
}
