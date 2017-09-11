#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int arbol_procesos(int nodos, int nivel);
int main(int argc,char **argv)
{
	arbol_procesos(2,2);
}


int arbol_procesos(int nodos, int nivel)
{
	int i,estatus;
	if(nivel==0)
	{
		return(0);
	}
	else
	{
		for(i=0;i<nodos;i++)
		{
			if(fork()==0)
			{
				arbol_procesos(nodos,nivel-1);
				break;
			}
			else
			{
				wait(&estatus);
			}
		}
	}
	printf("hijo: %d, padre: %d\n",getpid(),getppid());
	exit(0);
	return(0);
}