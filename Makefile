CC = gcc
CFLAGS = -Wall -Werror -c -g -std=c11 -I.
LDFLAGS = 

default: a.out

%.o : %.c 
	@echo Compiling $^ 
	@$(CC) $(CFLAGS) $^

a.out : main.o functions.o
	@echo Linking $@ 
	@$(CC) $^ $(LDFLAGS) -o $@

clean : 
	@rm -rf *.o
	@rm -rf a.out
	@echo All Clean!
