prog:function.o main.o
	gcc function.o main.o -o prog -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer
main.o:main.c
	gcc -c main.c -g
function.o:function.c
	gcc -c function.c -g
