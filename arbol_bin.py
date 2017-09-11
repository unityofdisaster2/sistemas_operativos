import os
def arbol(nodos, nivel):
	if nivel==0:
		return 0
	else:
		for i in range(nodos):
			if os.fork()==0:
				arbol(nodos,nivel-1)
				break
			else:
				os.wait()
	print "hijo: "+str(os.getpid())+"padre: "+str(os.getppid())
	os._exit(0)
	return 0

arbol(2,2)