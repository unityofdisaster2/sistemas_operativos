import os
def arbol_procesos(nodos, nivel):
	if nivel==0:
		return 0
	else:
		for i in range(0,nodos):
			if os.fork()==0:
				if i==0:
					arbol_procesos(3,nivel-1)
				elif i==1:
					arbol_procesos(4,nivel-1)
				break
			else:
				os.wait()
	print "hijo: "+str(os.getpid())+" padre: "+str(os.getppid())
	os._exit(0)
	return 0	

arbol_procesos(2,3)