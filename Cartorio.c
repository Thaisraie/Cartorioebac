#include <stdio.h> //biblioteca de comunicacao com o usu�rio
#include <stdlib.h> //biblioteca de alocacao de espaco em mem�ria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //funcao responsavel por cadastrar os usu�rios no sistema
{
	//inicio da criacao de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criacao de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informacao do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo e o "significa escrever"
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo 	
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);	
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);	
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);	
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}


int consulta()
{	
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	char cpf[40];
	char conteudo [200];

	printf("Digite o CPF a ser consultado: ");
	scanf ("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n");
	}

	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informacoes do usu�rio");
		printf("%s", conteudo);
		printf("\n\n");
	}

	system("pause");	
}	


int deletar()
{
	char  cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio nao se encontra no sistema!.\n");
		system("pause");
	}

}

int main()
{

	int opcao=0; //Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); //responsavel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //�nicio do menu
		printf("Escolha a opcao desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opcao: ");  //fim do menu

		scanf("%d", &opcao); //armazenaando a escolha do usu�rio
		
		system("cls"); //responsavel por limpar a tela
		
		switch(opcao) //inicio da selecao 
		{
			case 1:
			registro(); //chamada de funcoes
			break;
			
			case 2:
			consulta();
			break;
			
			case 3: 
			deletar();
			break;
				
			default:
			printf("Essa opcao nao est� disponivel!\n");
			system("pause");
			break;
			}//fim da selecao
		}			

}
	


