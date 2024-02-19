
lpk: main.o
	gcc target/lib/main.o -o target/lpk

main.o: src/main.c
	mkdir target
	mkdir target/lib
	gcc src/main.c -c -o target/lib/main.o

clean:
	rm -rf target