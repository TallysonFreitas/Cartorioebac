#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar de strings

int registro() //funcao responsavek por registrar usuarios
{
	//variaveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//coletando informacoes do usuario
	printf("digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; 				//cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" é escreva
	fprintf(file,cpf); 			//salva o valor da variavel
	fclose(file); 				//fecha o arquivo
	
	file = fopen(arquivo,"a"); 	//abrir arquivo
	fprintf(file,",");			//escrever no arquivo aberto ","
	fclose(file);				//fechar o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta(){
	
	setlocale(LC_ALL,"Portuguese");
	
	//variaveis
	char cpf[40];
	char conteudo[200];
	
	//pergunta ao usuario
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);//salvar resposta
	
	//abrir arquivo e ler
	FILE *file;
	file = fopen(cpf,"r");
	
	//sistema de condicao para respota ao usuario
	if(file == NULL){
		printf("O CPF nao foi localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		printf("\nEssas sao as informacoes do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar(){
	
	//variavel
	char cpf[40];
	
	//perguntar e salvar cpf
	printf("Digite o cpf a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);//excluir o arquivo com nome de cpf
	
	FILE *file;
	file = fopen(cpf,"r"); //"r" de read(ler)
	
	//sistema de condicao para dar resposta ao usuario
	if(file == NULL){
		printf("O usuario nao se encontra no sistema. \n");
		system("pause");
	}
	
}

int main(){
	
	//variaveis
	int opcao = 0;
	int laco = 1;
	
	//estrutura de repeticao
	for(laco=1;laco=1;){
		
		system("cls"); //limpa a tela do cmd
		
		setlocale(LC_ALL,"Portuguese"); //define a linguagem 
		
		//menu
		printf("### Cartorio da EBAC ### \n\n");
		printf("Ëscolha a opcao desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do menu\n\n");
		printf("Opcao: ");
		
		scanf("%d", &opcao); //armazenando a escolha do usuario
		
		system("cls"); //limpa o cmd
		
		//estrutura de condicao
	 	switch(opcao){
		 	case 1:
		 		registro(); //chamada de funcao para registrar um usuario
		 		break;
		 		
		 	case 2:
		 		consulta(); //chamada de funcao para consultar um usuario
		 		break;
		 		
		 	case 3:
		 		deletar(); //chamada de funcao para deletar um usuario
		 		break;
		 		
		 	case 4:
		 		printf("Obrigado por utilizar o sistema! ");
		 		return 0;
		 		break;
		 		
		 	default:
		 		printf("Voce escolheu uma opcao invalida\n");
		 		system("pause");
		 		break;
		 }
	 }
	
}
