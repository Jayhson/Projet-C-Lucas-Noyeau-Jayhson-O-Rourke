libmylib.a: search.o lancementLoad.o load.o prefixe.o creationArbre.o parse.o 
	ar -rs libmylib.a search.o lancementLoad.o load.o prefixe.o creationArbre.o parse.o  

#search.o: search.c lib.h
#	gcc -c search.c

#lancementLoad.o: lancementLoad.c lib.h
#	gcc -c lancementLoad.c
	
#load.o: load.c lib.h
#	gcc -c load.c

#prefixe.o: prefixe.c lib.h
#	gcc -c prefixe.c

#creationArbre.o: creationArbre.c lib.h
#	gcc -c creationArbre.c

#parse.o: parse.c lib.h
#	gcc -c parse.c

%.o: %.c lib.h
	gcc -c $<
clean:
	rm -rf *.o
	

	
		



	

	

