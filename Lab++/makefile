PHONY: clear
CC = g++
CCFLAGS = -Wall -Wextra -Wvla

main: main.o
	$(CC) $^ -o main
main.o: main.cpp
	$(CC) $(CCFLAGS) -c $^

radiology: radiology.o
	$(CC) $^ -o radiology
radiology.o: radiology.cpp
	$(CC) $(CCFLAGS) -c $^

clear:
	rm *.o main radiology