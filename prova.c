#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	
	struct horario{
		int horas;
		int minutos;
		int segundos;
	};
	
	struct horario agora;
	
	int x;
	
	agora.horas = 17;
	agora.minutos = 20;
	agora.segundos = 10;
	
	printf("%d : %d : %d", agora.horas, agora.minutos, agora.segundos);
}
	
	
