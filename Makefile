c   = gcc
src = src/*.c
arg = -std=c99 -lreadline -lpthread -lm
out = bin/MCYeti

build:
	mkdir -p bin
	$(c) $(src) $(arg) -s -o $(out)

debug:
	mkdir -p bin
	$(c) $(src) $(arg) -g -o $(out)