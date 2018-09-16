#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

typedef struct estructura
{
	int n,inicio[3],fin[3],num_hilo;
	int *arreglo;
}valores_hilo;




void *cuenta(void *valor)
{
	int i;
	for(i = 0; i<16; i++)
	{
		printf("valor arreglo %d\n",*(int *)valor+i);	
	}
	return 0;
}


int main(int argc, char **argv)
{
	int j;
	int n=16;
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};


	valores_hilo *val_hilo;

	pthread_t hilo[4];
	pthread_attr_t atributos;
	pthread_attr_init(&atributos);

	val_hilo = (valores_hilo *)malloc(sizeof(valores_hilo));
	val_hilo->n = n;
	val_hilo->arreglo = (int*)malloc(sizeof(int)*n);
	val_hilo->arreglo = arr;
	val_hilo->inicio[0] = 0;
	val_hilo->fin[0] = n/4;
	for(j = 0; j<4; j++)
	{
		pthread_create(&hilo[j],&atributos,cuenta,arr);
	}

	for(j = 0; j<4; j++)
	{
		pthread_join(hilo[j],NULL);		
	}
	return 0;
}