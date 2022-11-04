all: main.o funcs.o caesar.o decrypt.o
	g++ -o main main.o funcs.o caesar.o decrypt.o

main: main.o funcs.o caesar.o decrypt.o
	g++ -o main main.o funcs.o caesar.o decrypt.o

tests: tests.o funcs.o caesar.o decrypt.o
	g++ -o tests tests.o funcs.o caesar.o decrypt.o



funcs.o: funcs.cpp funcs.h caesar.h decrypt.h

main.o: main.cpp funcs.h caesar.h decrypt.h

caesar.o: caesar.cpp caesar.h

decrypt.o: decrypt.cpp decrypt.h

tests.o: tests.cpp doctest.h funcs.h caesar.h decrypt.h

clean:
	rm -f main.o funcs.o tests.o
