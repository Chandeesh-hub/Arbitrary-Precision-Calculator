apc.out: main.o add.o apc.o div.o mul.o sub.o mod.o pow.o
	gcc -o apc.out main.o add.o apc.o div.o mul.o sub.o mod.o pow.o
main.o: main.c
	gcc -c main.c
apc.o: apc.c
	gcc -c apc.c
add.o: add.c
	gcc -c add.c
sub.o: sub.c
	gcc -c sub.c
mul.o: mul.c
	gcc -c mul.c
div.o: div.c
	gcc -c div.c
mod.o: mod.c
	gcc -c mod.c
pow.o: pow.c
	gcc -c pow.c
clean:
	rm -f apc.out main.o add.o apc.o div.o mul.o sub.o pow.o mod.o