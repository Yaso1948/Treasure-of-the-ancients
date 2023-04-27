prog:ES.o main.o function.o
	gcc function.o ES.o main.o -o prog -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer
main.o:main.c
	gcc -c main.c -g
ES.o:ES.c
	gcc -c ES.c -g
function.o:function.c
	gcc -c function.c -g
