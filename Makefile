CFLAGS=--std=c11 -Wall -pedantic -Isrc/ -ggdb -Wextra -Werror -DDEBUG
CC=gcc

all: rotate_img

bmp.o: bmp.c
	$(CC) -c $(CFLAGS) $< -o $@

util.o: util.c
	$(CC) -c $(CFLAGS) $< -o $@

check.o: check.c
	$(CC) -c $(CFLAGS) $< -o $@

from_bmp: from_bmp.c
	$(CC) -c $(CFLAGS) $< -o $@

open_close_file.o: open_close_file.c
	$(CC) -c $(CFLAGS) $< -o $@

rotate_picture.o: rotate_picture.c
	$(CC) -c $(CFLAGS) $< -o $@

to_bmp.o: to_bmp.c
	$(CC) -c $(CFLAGS) $< -o $@

main.o: main.c
	$(CC) -c $(CFLAGS) $< -o $@

rotate_img: main.o to_bmp.o rotate_picture.o open_close_file.o from_bmp.o check.o util.o bmp.o
	$(CC) -o rotate_img $^

clean:
	rm -f main.o util.o bmp.o to_bmp.o rotate_picture.o open_close_file.o from_bmp.o check.o

