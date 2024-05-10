PHONY: clear lab radiology
CC = gcc
PP = g++
CCFLAGS = -Wall -Wextra -Wvla

quick: lab.c
	$(CC) $(CCFLAGS) -c $< -o lab

lab: lab.o
	$(CC) $^ -o lab
lab.o: lab.c
	$(CC) $(CCFLAGS) -c $^

radiology: radiology.o
	$(CC) $^ -o radiology
radiology.o: radiology.c
	$(CC) $(CCFLAGS) -c $<

optics: optics.o
	$(PP) $^ -o optics
optics.o: optics.cpp
	$(PP) $(CCFLAGS) -c $^

clear:
	rm *.o lab radiology optics