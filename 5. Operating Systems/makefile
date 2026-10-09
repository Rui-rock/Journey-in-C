GCC = gcc
CFLAGS = --std=c99
WARNINGS = -Wall -Werror

PROG1 = a1.c
PROG2 = a2.c 

all: examples, graysh

examples: 
	$(GCC) -o a1 a1.c $(CFLAGS) $(WARNINGS)
	$(GCC) -o a2 a2.c $(CFLAGS) $(WARNINGS)

graysh: hw1.c
	$(GCC) -o hw1 hw1.c $(CFLAGS) $(WARNINGS)
