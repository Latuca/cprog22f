intro_exe : job.o hobby.o main.o
	gcc -o intro_exe job.o hobby.o main.o

job.o : job.c
	gcc -c -o job.o job.c
  
hobby.o : hobby.c
	gcc -c -o hobby.o hobby.c
  
main.o : main.c
	gcc -c -o main.o main.c
  
clean : 
	rm *.o intro_exe