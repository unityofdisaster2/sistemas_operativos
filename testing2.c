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
				if(i==0)
				{
					arbol_procesos(3,nivel-1);
				}
				else if(i==1)
				{
					arbol_procesos(4,nivel-1);
				}
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