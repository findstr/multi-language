main:main.o multi-lan.o
	gcc -o $@ $^ -lm -llua -ldl

main.o:main.c
	gcc -g -c -o $@ $<

multi-lan.o:multi-lan.c
	gcc -g -c -o $@ $<

clean:
	-rm main
	-rm *.o
	-rm tags
