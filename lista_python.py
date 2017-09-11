import os
for x in range(4):
	proceso = os.fork()
	if(proceso==0):
		print "hijo: "+str(os.getpid())+" Padre: "+str(os.getppid())
	elif proceso>0:
		print "soy el padre: "+str(os.getpid())
		os.wait()
		os._exit(0)	