#include <stdio.h>
#include <stdlib.h>

// VARIAVEIS GLOBAIS

// ESCOPO DAS FUNÇÕES
void menu();
void menuGerenciarClientes();
void menuGerenciarProdutos();
void menuGerenciarPedidos();

int main (){
	
	// DECLARAÇÃO DAS VARIAVEIS LOCAIS
	char opcaoMenu;
	
	
	// CRIANDO PONTEIRO PARA O ARQUIVO
	FILE *arquivoDeDados;
	
	// CRIANDO O ARQUIVO E APONTANDO PARA O PONTEIRO
	arquivoDeDados = fopen(	"arquivoDeDados.txt", "w+");
	
	if (arquivoDeDados!=NULL){
			// IMPRIME NO ARQUIVO
		    fputs ("fopen example",arquivoDeDados);
		    
			//FECHA O ARQUIVO
		    fclose (arquivoDeDados);
		}

	// CHAMADA DA FUNÇÃO PARA IMPRIMIR O MENU
	menu();
	
	// LEITURA DAS OPÇÕES DO MENU
	
	scanf("%c", &opcaoMenu);
	
	// COMPARAÇÃO DAS OPÇÕES DO MENU
	if(opcaoMenu == 'c' || opcaoMenu == 'C'){
		// CHAMA A FUNÇÃO PARA EXIBIR O MENU CORRESPONDENTE
		menuGerenciarClientes();
	}
	if(opcaoMenu == 'p' || opcaoMenu == 'P'){
		// CHAMA A FUNÇÃO PARA EXIBIR O MENU CORRESPONDENTE
		menuGerenciarProdutos();
	}
	if(opcaoMenu == 'e' || opcaoMenu == 'E'){
		// CHAMA A FUNÇÃO PARA EXIBIR O MENU CORRESPONDENTE
		menuGerenciarPedidos();
	}
	if(opcaoMenu == 's' || opcaoMenu == 's'){
		return 0;
	}
	else{
		printf("Opção inválida\nSaindo do sistema... \n");
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
	void menuGerenciarClientes(){
		printf("============ Gerenciar Clientes ============\n");
		printf("Digite um comando para prosseguir:\n");
		printf("C - Cadastrar um cliente.\n");
		printf("L - Listar todos os clientes cadastrados.\n");
		printf("B - Buscar cliente já cadastrado.\n");
		printf("A - Atualizar um cliente cadastrado.\n");
		printf("E - Excluir um cliente cadastrado.\n");
	}
	
// FUNÇÃO MENU GERENCIAR PRODUTOS
	void menuGerenciarProdutos(){
		printf("============== Gerenciar Produtos ==============\n");
		printf("Digite um comando para prosseguir:\n");
		printf("C - Cadastrar um produto.\n");
		printf("L - Listar todos os produtos cadastrados.\n");
		printf("B - Buscar produto já cadastrado.\n");
		printf("A - Atualizar um produto cadastrado.\n");
		printf("E - Excluir um produto cadastrado.\n");
		printf("S - Atualizar estoque de um produto.\n");
	}
	
// FUNÇÃO MENU GERENCIAR PEDIDOS
	void menuGerenciarPedidos(){
		printf("============== Gerenciar Pedidos ==============\n");
		printf("Digite um comando para prosseguir:\n");
		printf("C – Cadastrar um pedido.\n");
		printf("L – Listar todos os pedidos de um cliente.\n");
		printf("D – Listar todos os pedidos em um dia específico.\n");
	}
	
	
