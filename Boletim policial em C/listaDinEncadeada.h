typedef struct{
  char nome[30];
	int tel;
  int codigoReclam;
} reclamante;

typedef struct{
  char dataCrim[9];
	int codigoCrim;
	char descricao[60];
	char tipo[30];   
} crime;

typedef struct{

	reclamante reclam;
	char dataBO[9];
  int codigoBO;
  crime crim;
}BO;



typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int tamanho_lista(Lista* li);
int lista_cheia(Lista* li);
int lista_vazia(Lista* li);

int insere_lista_inicio(Lista* li, BO bo);
int insere_lista_final(Lista* li, BO bo);
int insere_lista_ordenada(Lista* li, BO bo);

int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int remove_lista(Lista* li, int Bo);

int consulta_lista_pos(Lista* li, int pos, BO *bo);
int consulta_lista_boletim(Lista* li, int codig, BO *bo);
void imprime_consulta(Lista* li, int codig, BO *bo);
int ordenar_lista(Lista * li);

void imprimir_lista(Lista * li);
void posicao_lista(Lista * li, char nome[30]);

void Menu_editarbo(Lista* li);
void Editar_dados_bo(Lista* li, int codig);
int ExcluirBO (Lista* li);
void NovoBo (Lista* li, FILE *fp);

FILE cria_arq_lista();
void ler_arquivo(Lista* li, BO bo, FILE *fp);
void abrirArq_lista(Lista * li2, FILE *fp2);
void SalvarArq (Lista *li,FILE* fp, int y);
void arqui_anonimo(Lista *li2, FILE* fp2, BO bo);
