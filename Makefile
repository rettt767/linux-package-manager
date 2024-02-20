
lpk: main.o help.o version.o io.o
	gcc target/lib/*.o -o target/lpk

main.o: src/main.c
	gcc src/main.c -c -o target/lib/main.o

help.o: src/operation/help.c
	gcc src/operation/help.c -c -o target/lib/help.o

version.o: src/operation/version.c
	gcc src/operation/version.c -c -o target/lib/version.o

io.o: src/io/write.c
	gcc src/io/write.c -c -o target/lib/io.o

clean:
	rm target/lpk
	rm -r target/lib/*.o