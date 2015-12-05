CFLAGS=-O2  -lm -Wall -pedantic -g -std=c++11
OBJFILES=$(patsubst src/%.cpp, build/%.cpp.o, $(shell ls src/*.cpp))
SHELL=bash

# build
all: ims

ims: $(OBJFILES)
	g++ $(CFLAGS) build/*.o -o ims

build/%.cpp.o: src/%.cpp
	cc $(CFLAGS) -c $< -o $(subst src/, build/, $<.o)

# Clean compiled files
clean:
	rm -rf build/* ims doc/documentation.pdf

run: ims
	./ims input1.net 200
	mv output.csv output-1.csv
	./ims input2.net 200
	mv output.csv output-2.csv
	./ims input3.net 200
	mv output.csv output-3.csv
	./ims input4.net 200
	mv output.csv output-4.csv



# Documentation
documentation: doc/documentation.tex
	pdflatex  -output-directory=./doc/ doc/documentation.tex
