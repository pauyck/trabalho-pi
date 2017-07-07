#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// VARIAVEIS GLOBAIS
#define TAMANHO_INICIAL 20
#define t 1024

// CADASTRO DE CLIENTE
// DECLARAÇÃO DA ESTRUTURA
typedef struct {
	char logradouro[100];
	char cep[8];
	char bairro[30];
	char cidade[30];
	char estado[30];
} Endereco;

typedef struct {
	char codigo[25];
	char nome[100];
	char cpf_cnpj[14];
	char telefone[8];
	Endereco enderecos;
}Cliente;


typedef struct Produto {
    int  codigo;
    char nome[100];
    char fornecedor[100];
    char categoria;
    int quantidade;
    float valorUnitario;
}cadProduto;

// ESCOPO DAS FUNCOES
void menu();
char menuGerenciarClientes();
void menuGerenciarProdutos();
void menuGerenciarPedidos();
void imprimirProduto();

// FUNÇÕES COM STRUCT
Cliente cadastrarCliente();
Cliente imprimirCliente(char*);


int main (){
	// DECLARAÇÃO DAS VARIAVEIS LOCAIS
	char opcaoMenu;
	char *linha = malloc(1024);
	
	// CRIANDO PONTEIRO PARA O ARQUIVO
	FILE *arquivoDeDados;

	menu();	
	scanf("%c", &opcaoMenu);
	
	if(opcaoMenu == 'c' || opcaoMenu == 'C'){
		char opcaoGerenciarClientes = menuGerenciarClientes();
			
		if(opcaoGerenciarClientes == 'C' || opcaoGerenciarClientes == 'c') {
			// ABRE O ARQUIVO PARA ATUALIZACAO	
			arquivoDeDados = fopen("arquivoDeDados.txt", "a+");
			if(arquivoDeDados == NULL) {
				printf("Não foi possível abrir o arquivo.");
				return 1;}
				
			// CADASTRAR NO ARQUIVO
			Cliente cliente = cadastrarCliente();
			fprintf(arquivoDeDados, "%s;%s;%s;%s;%s;%s;%s;%s;%s\n", cliente.codigo, cliente.nome, cliente.cpf_cnpj, cliente.telefone, 
			cliente.enderecos.logradouro, cliente.enderecos.cep, cliente.enderecos.bairro, cliente.enderecos.cidade, cliente.enderecos.estado); 
			fclose(arquivoDeDados);
		}
		
		if(opcaoGerenciarClientes == 'L' || opcaoGerenciarClientes == 'l') {	
			// ABRE O ARQUIVO PARA ATUALIZACAO	
			arquivoDeDados = fopen("arquivoDeDados.txt", "r+");
			if(arquivoDeDados == NULL) {
				printf("Não foi possível abrir o arquivo.");
				return 1;
				}
			
			// LE ARQUIVO E CHAMA A FUNCAO PARA IM
			while(fgets(linha, t, arquivoDeDados) != EOF){
				fscanf(arquivoDeDados, "%[^\n]s", linha);
				imprimirCliente(linha);
			}
			
			fclose(arquivoDeDados);
		}
	}
			 
	if(opcaoMenu == 'p' || opcaoMenu == 'P'){
		menuGerenciarProdutos();
	}
	if(opcaoMenu == 'e' || opcaoMenu == 'E'){
		menuGerenciarPedidos();
	}
	if(opcaoMenu == 's' || opcaoMenu == 's'){
		return 0;
	}
	else{
		printf("Opcao invalida\n\n");
        system("cls");
        main();
	}

	system("pause");
	return 0;
}


// FUNÇÃO MENU
void menu(){
	printf("Digite um comando para prosseguir:\n");
	printf("C - Gerenciar Clientes\n");
	printf("P - Gerenciar Produtos\n");
	printf("E - Gerenciar Pedidos\n");
	printf("S - Sair\n\n");
}

// FUNÇÃO MENU GERENCIAR CLIENTES
char menuGerenciarClientes(opcaoGerenciarClientes){
	char opcaogerenciarclientes;
	printf("============ Gerenciar Clientes ============\n");
	printf("Digite um comando para prosseguir:\n");
	printf("C - Cadastrar um cliente.\n");
	printf("L - Listar todos os clientes cadastrados.\n");
	printf("B - Buscar cliente ja cadastrado.\n");
	printf("A - Atualizar um cliente cadastrado.\n");
	printf("E - Excluir um cliente cadastrado.\n");	
	scanf(" %c", &opcaogerenciarclientes);
	return opcaogerenciarclientes;		
}

// FUNÃ‡ÃƒO MENU GERENCIAR PRODUTOS
void menuGerenciarProdutos(){
	printf("============== Gerenciar Produtos ==============\n");
	printf("Digite um comando para prosseguir:\n");
	printf("C - Cadastrar um produto.\n");
	printf("L - Listar todos os produtos cadastrados.\n");
	printf("B - Buscar produto ja cadastrado.\n");
	printf("A - Atualizar um produto cadastrado.\n");
	printf("E - Excluir um produto cadastrado.\n");
	printf("S - Atualizar estoque de um produto.\n");
}

// FUNÇÃO MENU GERENCIAR PEDIDOS
void menuGerenciarPedidos(){
	printf("============== Gerenciar Pedidos ==============\n");
	printf("Digite um comando para prosseguir:\n");
	printf("C - Cadastrar um pedido.\n");
	printf("L - Listar todos os pedidos de um cliente.\n");
	printf("D -“ Listar todos os pedidos em um dia especÃ­fico.\n");
}

// FUNÇÃO CADASTRAR CLIENTE
Cliente cadastrarCliente(Cliente c) {
	Cliente cliente;
    printf("Informe o codigo do cliente:\n");
    scanf(" %[^\n]s", cliente.codigo);
    printf("Informe o nome do cliente:\n");
    scanf(" %[^\n]s", cliente.nome);
    printf("Informe o CPF ou CNPJ do cliente:\n");
    scanf(" %[^\n]s", cliente.cpf_cnpj);
    printf("Informe o telefone do cliente:\n");
    scanf(" %[^\n]s", cliente.telefone);
    
    printf("\nInforme os dados do endereco\n");
    printf("Logradouro:\n");
    scanf(" %[^\n]s", cliente.enderecos.logradouro);
    printf("CEP:\n");
    scanf(" %[^\n]s", cliente.enderecos.cep);
    printf("Bairro:\n");
    scanf(" %[^\n]s", cliente.enderecos.bairro);    
    printf("Cidade:\n");
    scanf(" %[^\n]s", cliente.enderecos.cidade);    
    printf("Estado:\n");
    scanf(" %[^\n]s", cliente.enderecos.estado);    
    
    return cliente;
}


// FUNÇÃO IMPRIMIR CLIENTE
Cliente imprimirCliente(char *linha) {
	Cliente clienteimprimir;
		strcpy(clienteimprimir.codigo, strtok(linha, ";"));
		strcpy(clienteimprimir.nome, strtok(NULL, ";"));
		strcpy(clienteimprimir.cpf_cnpj, strtok(NULL, ";"));
		strcpy(clienteimprimir.telefone, strtok(NULL, ";"));
		strcpy(clienteimprimir.enderecos.logradouro, strtok(NULL, ";"));
		strcpy(clienteimprimir.enderecos.bairro, strtok(NULL, ";"));
		strcpy(clienteimprimir.enderecos.cep, strtok(NULL, ";"));
		strcpy(clienteimprimir.enderecos.cidade, strtok(NULL, ";"));
		strcpy(clienteimprimir.enderecos.estado, strtok(NULL, ";"));
		
		
		printf("Codigo: %s\n", clienteimprimir.codigo);
	    printf("Nome: %s\n", clienteimprimir.nome);
	    printf("CPF: %s\n", clienteimprimir.cpf_cnpj);
	    printf("Telefone: %s\n", clienteimprimir.telefone);
	    
	    printf("Endereco: \nLogradouro: %s\n", clienteimprimir.enderecos.logradouro);
	    printf("Bairro: %s\n", clienteimprimir.enderecos.bairro);
	    printf("CEP: %s\n", clienteimprimir.enderecos.cep);
	    printf("Cidade: %s\n", clienteimprimir.enderecos.cidade);
	    printf("Estado: %s\n\n", clienteimprimir.enderecos.estado);
	
	//pessoa1.genero = *strtok(NULL, ";");
	//char *idade = strtok(NULL, ";");
	
	return clienteimprimir;
}

// FUNÇÃO CADASTRAR PRODUTO
cadProduto cadastrarProduto() {
    cadProduto produto;
    printf("Informe o codigo do produto:\n");
    scanf(" %d", &produto.codigo);
    printf("Informe o nome do produto:\n");
    scanf(" %[^\n]s", produto.nome);
    printf("Informe o fornecedor:\n");
    scanf(" %[^\n]s", produto.fornecedor);
    printf("Informe a quantidade:\n");
    scanf(" %d", produto.quantidade);
    printf("Informe o valor unitario do produto:\n");
    scanf(" %f", produto.valorUnitario);

    return produto;
}


//  FUNÇÃO IMPRIMIR PRODUTO
void imprimirProduto(char *linha) {
		cadProduto imprimeprod;
        printf("Codigo: %s\n", imprimeprod.codigo);
        printf("Nome: %s\n", imprimeprod.nome);
        printf("Fornecedor: %s\n", imprimeprod.fornecedor);
        printf("Quantidade; %d\n", imprimeprod.quantidade);
        printf("Valor Unitario: %.f\n", imprimeprod.valorUnitario);
}


