#include <stdio.h>
#include <stdlib.h>

// VARIAVEIS GLOBAIS

// CADASTRO DE CLIENTE
// DECLARA«√O DA ESTRUTURA
typedef struct Endereco {
	char logradouro[100];
	char cep[8];
	char bairro[30];
	char cidade[30];
	char estado[30];
} Endereco;

typedef struct {
	int codigo;
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
void imprimirCliente();
void imprimirProduto();
void imprimirCliente();

// FUN«’ES COM STRUCT
Cliente cadastrarCliente();

int main (){
	// DECLARA«√O DAS VARIAVEIS LOCAIS
	char opcaoMenu;

	// CRIANDO PONTEIRO PARA O ARQUIVO
	FILE *arquivoDeDados;

//	// CRIANDO O ARQUIVO E APONTANDO PARA O PONTEIRO
//	arquivoDeDados = fopen(	"arquivoDeDados.txt", "w+");
//
//	if (arquivoDeDados!=NULL){
//			// IMPRIME NO ARQUIVO
//		    fputs ("fopen example",arquivoDeDados);
//
//			//FECHA O ARQUIVO
//		    fclose (arquivoDeDados);
//		}

	menu();	
	scanf("%c", &opcaoMenu);
	
	if(opcaoMenu == 'c' || opcaoMenu == 'C'){
		char opcaoGerenciarClientes = menuGerenciarClientes();
		
			FILE *arquivo;
			arquivo = fopen("arquivoDeDados.txt", "w+");
			if(arquivo == NULL) {
				printf("N„o foi possÌvel abrir o arquivo.");
				return 1;}
				
				if(opcaoGerenciarClientes == 'C' || opcaoGerenciarClientes == 'c') {	
				Cliente cliente = cadastrarCliente();
				fprintf(arquivoDeDados, "%d;%s;%s;%s;%s;%s;%s;%s;%s\n", cliente.codigo, cliente.nome, cliente.cpf_cnpj, cliente.telefone, 
				cliente.enderecos.logradouro, cliente.enderecos.cep, cliente.enderecos.bairro, cliente.enderecos.cidade, cliente.enderecos.estado); 
				
				fclose(arquivo);
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
				printf("Opcao invalida\nSaindo do sistema... \n");
			}

	system("pause");
	return 0;
}


// FUN√á√ÉO MENU
void menu(){
	printf("Digite um comando para prosseguir:\n");
	printf("C - Gerenciar Clientes\n");
	printf("P - Gerenciar Produtos\n");
	printf("E - Gerenciar Pedidos\n");
	printf("S - Sair\n\n");
}

// FUN√á√ÉO MENU GERENCIAR CLIENTES
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

// FUN√á√ÉO MENU GERENCIAR PRODUTOS
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

// FUN«√O MENU GERENCIAR PEDIDOS
void menuGerenciarPedidos(){
	printf("============== Gerenciar Pedidos ==============\n");
	printf("Digite um comando para prosseguir:\n");
	printf("C - Cadastrar um pedido.\n");
	printf("L - Listar todos os pedidos de um cliente.\n");
	printf("D -ì Listar todos os pedidos em um dia espec√≠fico.\n");
}

// FUN«√O CADASTRAR CLIENTE
Cliente cadastrarCliente() {
  
  	Cliente cliente;
    
    printf("Informe o codigo do cliente:\n");
    scanf(" %d", &cliente.codigo);
    printf("Informe o nome do cliente:\n");
    scanf(" %[^\n]s", cliente.nome);
    printf("Informe o CPF ou CNPJ do cliente:\n");
    scanf(" %[^\n]s", cliente.cpf_cnpj);
    printf("Informe o telefone do cliente:\n");
    scanf(" %[^\n]s", cliente.telefone);
    
    printf("Informe os dados do endereco\n");
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
    
    //	- No menu de cadastro do fornecedor, o sistema deve pedir para que o usu·rio informe os dados
	//	de um cliente e o salve em arquivo	

    return cliente;
}


// FUN«√O IMPRIMIR CLIENTE
void imprimirCliente(Cliente cliente) {
    printf("Codigo: %d\n\n", cliente.codigo);
    printf("Nome: %s\n", cliente.nome);
    printf("CPF: %s\n", cliente.cpf_cnpj);
    printf("E-mail: %s\n", cliente.telefone);
    printf("Endereco: %s\n", cliente.enderecos);
}


// FUN«√O CADASTRAR PRODUTO
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

//  FUN«√O IMPRIMIR PRODUTO
    void imprimirProduto(cadProduto Produto) {
		cadProduto imprimeprod;
        printf("Codigo: %d\n\n", imprimeprod.codigo);
        printf("Nome: %s\n", imprimeprod.nome);
        printf("Fornecedor: %s\n", imprimeprod.fornecedor);
        printf("Quantidade; %d\n", imprimeprod.quantidade);
        printf("Valor Unitario: %.f\n", imprimeprod.valorUnitario);
}


