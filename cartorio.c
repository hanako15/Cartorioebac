#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em  mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w");	//abre o arquivo na pasta e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abrir um arquivo que ja esta salvo , atualizar um arquivo
	fprintf(file,","); // salvar uma informa��o no arquivo j� existente, virgula � pra separar
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //abrir arquivo que j� existe, "a" atualizar o arquivo
	fprintf(file,nome); //salvar uma informa��o no arquivo que j� existe
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo, "a"); //abrir um arquivo que ja esta salvo , atualizar um arquivo
	fprintf(file,","); // salvar uma informa��o no arquivo j� existente, virgula � pra separar
	fclose(file); //fechar arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome); //armazenar dentro da variavel sobrenome
	
	file = fopen(arquivo, "a"); //abrir arquivo que j� existe, atualizar
	fprintf(file,sobrenome); //salvar uma informa��o no arquivo que j� existe
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo, "a"); //abrir um arquivo que ja esta salvo , atualizar um arquivo
	fprintf(file,","); // salvar uma informa��o no arquivo j� existente, virgula � pra separar
	fclose(file); //fechar arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); //abrir um arquivo j� salvo
	fprintf(file,cargo); //salvar uma informa��o no arquivo ja existente
	fclose(file); //fechar arquivo
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file; //criar arquivo
	file = fopen(cpf,"r"); // ler o arquivo
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file; //criar arquivo
	file = fopen(cpf,"r"); //abrir arquivo "r" significa ler
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
		
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for (laco=1;laco=1;)
	{
	
		system("cls"); // respons�vel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("###Cart�rio da EBAC###\n\n"); //in�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: ");//fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls"); //respons�vel por limpar a tela
		
		switch(opcao) //in�cio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta(); //chamada de fun��es
			break;
			
			case 3:
			deletar(); //chamada de fun��es
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		}//fim da sele��o
		
    
	}


	
	
}
