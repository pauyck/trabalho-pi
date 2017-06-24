#include <stdio.h>
#include <stdlib.h>

// VARIAVEIS GLOBAIS

// ESCOPO DAS FUNÇÕES DO MENU
void menu();
void menuGerenciarClientes();
void menuGerenciarProdutos();
void menuGerenciarPedidos();

// FUNÇÕES DO CLIENTE
Cliente cadastrarCliente();
void imprimirCliente(Cliente cliente);

// FUNÇÕES DO PRODUTO
Produto cadastrarProduto();
void imprimirProduto (Produto produto);

// CADASTRO DE CLIENTE
// DECLARAÇÃO DA ESTRUTURA
typedef struct Endereco {
	char logradouro[100];
	char cep[8];
	char bairro[30];
	char cidade[30];
	char estado[30];
} Endereco;

typedef struct Cliente {
	int codigo;
	char nome[100];
	char cpf_cnpj[14];
	char telefone[8];
	Endereco enderecos[];
} Cliente;


typedef struct Produto {
    int  codigo;
    char nome[100];
    char fornecedor[100];
    char categoria;
    int quantidade;
    float valorUnitario;
} Produto;


Cliente cadastrarCliente();
void imprimirCliente(Cliente cliente);

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

// FUNÇÃO CADASTRAR CLIENTE
    Cliente cadastrarCliente() {

        Cliente cliente;
        printf("Informe o código do cliente:\n");
        scanf(" %d", &cliente.codigo);
        printf("Informe o nome do cliente:\n");
        scanf(" %[^\n]s", cliente.nome);
        printf("Informe o CPF ou CNPJ do cliente:\n");
        scanf(" %[^\n]s", cliente.cpf_cnpj);
        printf("Informe o telefone do cliente:\n");
        scanf(" %[^\n]s", cliente.telefone);

        return cliente;
}
// FUNÇÃO IMPRIMIR CLIENTE
    void imprimirCliente(Cliente cliente) {

        printf("Código: %d\n\n", cliente.codigo);
        printf("Nome: %s\n", cliente.nome);
        printf("CPF: %s\n", cliente.cpf_cnpj);
        printf("E-mail: %s\n", cliente.telefone);
        printf("Endereço: %s\n", cliente.enderecos);
}


// FUNÇÃO CADASTRAR PRODUTO
    Produto cadastrarProduto() {

        Produto produto;
        printf("Informe o código do produto:\n");
        scanf(" %d", &produto.codigo);
        printf("Informe o nome do produto:\n");
        scanf(" %[^\n]s", produto.nome);
        printf("Informe o fornecedor:\n");
        scanf(" %[^\n]s", produto.fornecedor);
        printf("Informe a quantidade:\n");
        scanf(" %d", produto.quantidade);
        printf("Informe o valor unitário do produto:\n");
        scanf(" %f", produto.valorUnitario);

        return produto;
    }

//  FUNÇÃO IMPRIMIR PRODUTO
    void imprimirProduto(Produto Produto) {

        printf("Código: %d\n\n", Produto.codigo);
        printf("Nome: %s\n", produto.nome);
        printf("Fornecedor: %s\n", produto.fornecedor);
        printf("Quantidade; %d\n", produto.quantidade);
        printf("Valor Unitário: %.f\n", produto.valorUnitario);
}
    }
