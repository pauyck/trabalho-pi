#include <stdio.h>
#include <stdlib.h>

int main ()
{
	// CRIANDO PONTEIRO PARA O ARQUIVO
	FILE *arquivoDeDados;
	
	// CRIANDO O ARQUIVO E APONTANDO PARA O PONTEIRO
	arquivoDeDados = fopen(	"arquivoDeDados.txt", "w");
	
	// IMPRIME NO ARQUIVO
	fprintf(arquivoDeDados, "Testes");
	
	//FECHA O ARQUIVO
	fclose(arquivoDeDados);
	
	system("pause");
	return 0;
}

