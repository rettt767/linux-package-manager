
lpk: main.o help.o version.o
	gcc target/lib/*.o -o target/lpk

main.o: src/main.c
	mkdir target
	mkdir target/lib
	gcc src/main.c -c -o target/lib/main.o

help.o: src/operation/help.c
	gcc src/operation/help.c -c -o target/lib/help.o

version.o: src/operation/version.c
	gcc src/operation/version.c -c -o target/lib/version.o

clean:
	rm -rf target