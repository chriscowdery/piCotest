exampleTest: picotest.o exampleTest.o
	gcc -o exampleTest picotest.o exampleTest.o 

picotest.o: picotest.c picotest.h
	gcc -c picotest.c

exampleTest.o: exampleTest.c
	gcc -c exampleTest.c

clean:
	rm *.o
	rm exampleTest

all: exampleTest