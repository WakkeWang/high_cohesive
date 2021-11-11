all:
	gcc main.c led.c do.c -o utils
clean:
	rm utils
