## My generic makefile written by Magnus Sörensen. GPL3.0 Lisense.

## CROSS_TOLL is used if you need co add a cross platform compiler.
CROSS_TOLL=
## CC is the compiler you use in this project.
CC=$(CROSS_TOLL) g++
TTY=/dev/pts/2
## Target is the source files with out .c or .cpp  tex main.c ~> main
TARGET_C=
TARGET_CPP=Graphics Input Game Formation Actor Player Enemy main
OBJECTS_C=$(TARGET_C:=.o)
OBJECTS_CPP=$(TARGET_CPP:=.o)
## EXECFILE is the name on the exe file you want
## LFLAGS is the libary linker flags like -lncurses or -lpthread.
LFLAGS_C=
LFLAGS_CPP=-std=c++0x -lsfml-system -lsfml-graphics -lsfml-window -pthread
#LFLAGS=-lncurses -lm
## CFLAGS tells the copmiler to compile with diffrent flaggs mostly -g -Wall
FLAGS_C=-g -Wall
FLAGS_CPP=-g -Wall
## If files is from windows then run
## recode ISO-8859-1..UTF-8 main.c
## or even better for file in *.{c,h} ; do recode ISO-8859-1..UTF-8 $file; done
## Also remember to create ctags in your src dir
##  $ ctags -R

ifeq ($(OS),Windows_NT)
OS_detected := Windows
EXECFILE := game.exe
REMOVE=del
else
OS_detected := $(shell uname -s)
EXECFILE=game.out
REMOVE=rm -f
endif


$(TARGET_C):
	$(CC) $(FLAGS_C) $(LFLAGS_C) -c $@.c

$(TARGET_CPP):
	$(CC) $(FLAGS_CPP) $(LFLAGS_CPP) -c $@.cpp

all: clean $(TARGET_CPP) $(TARGET_C)
	$(CC) $(OBJECTS_CPP) $(OBJECTS_C) $(LFLAGS_CPP) $(FLAGS_CPP) -o $(EXECFILE)

run: clean all
	./$(EXECFILE)

debug: clean all
	cgdb ./$(EXECFILE)

ddd: clean all
	ddd ./$(EXECFILE) &

.PHONY: clean valgrind

valgrind: clean all
	valgrind ./$(EXECFILE)

clean:
		$(REMOVE) *.o $(EXECFILE) *.gch
