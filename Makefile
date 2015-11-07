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
	rm -rf build/* ims tests/*.out.run doc/documentation.pdf



# Documentation
documentation: doc/documentation.tex
	pdflatex  -output-directory=./doc/ doc/documentation.tex