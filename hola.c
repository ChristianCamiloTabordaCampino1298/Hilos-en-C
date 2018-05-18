#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>


void* imprime() {
	printf("hola %ld\n", pthread_self()); // la funcion pthread_self nos retorna el id del hilo
}

int main(int argc, char *argv[]) {
 
	int numhilos=10;   //Cantidad de hilos
	pthread_t hilos[numhilos]; 
	
	for (int i = 0; i <numhilos; i++) {	
		pthread_create(&hilos[i],NULL,imprime, NULL);
	}
	for (int i = 0; i < numhilos; i++) {
		pthread_join(hilos[i],NULL);	
	}

}
