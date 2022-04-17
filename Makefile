CC = gcc
CFLAGS = -W -Wall
manager: main.c manager.o
	$(CC) $(CFLAGS) -o $@ $^
manager_debug: main.c manager.c
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^
clean:
	rm *.o
	rm manager manager_debug
