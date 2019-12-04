#include <stdio.h>
#include <stdlib.h>
typedef struct dicionario{
	char palavra [50];
	char significado [256];
}dicionario;
dicionario dic[0];
void incluir ();
int consultar ();
void listar();
void remover();
int menu();
int i,j,opcao;
char comp[50];
int main(int argc, char *argv[]) {

	menu();

	return 0;
}
int menu(){
	int opcao;
	int verifica;

	do{
	
	printf("\t\t\t\tDicionario\n");
	printf("1- Incluir \n");
	printf("2- Consultar \n");
	printf("3- Listar \n");
	printf("4- Remover \n");
	printf("0- Sair \n");
	printf("Escolha a opcao desejada ! \n");
	scanf("%d",&opcao);
	switch(opcao){
		case 1:
			incluir();
			break;
		case 2:
			verifica = consultar();
        if(verifica == -1){
        	printf("Palavra inexistente");
		}
		else{
			printf("Significa: %s",dic[verifica].significado);
		}
        break;
			
		case 3:
			listar();
			break;
		case 4:
			remover();
			break;
		case 0:
			exit(0);
		default: if(opcao > 4){
			printf("Opcao invalida, tente novamente \n");
		}
			break;
		
	}

}while(opcao =!0);

}
void incluir(){
	setbuf(stdin,NULL);
	printf("\nDigite uma palavra: ");
	gets(dic[i].palavra);
    printf("\nDigite o significado da palavra: ");
    gets(dic[i].significado);
    i++;
	
}

void listar(){
	for(j=0; j<i;j++){
		printf("Palavra:  %s \n",dic[j].palavra);
		printf("Significado %s \n",dic[j].significado);
	}
}
void remover(void){

    printf("Digite a palavra que deseja remover: ");
    scanf("%s",comp);
    fflush(stdin);

    for(j=0;j<i;j++){
        if(stricmp(comp, dic[j].palavra)==0){
            printf("Palavra removida!");
            *dic[j].palavra = *dic[j+1].palavra;
            *dic[j].significado = *dic[j+1].significado;
            i--;
        }
    }
}
int consultar(void){
	setbuf(stdin,NULL);
	int palavralocal = -1;
	printf("Digite a palavra que deseja consultar: ");
	scanf("%[^\n]",comp);

	for(j=0;j<i;j++){
		if(stricmp(comp, dic[j].palavra)==0){
			palavralocal = j;
		}
	}
	return palavralocal;
}
