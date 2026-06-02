compile: raylib-test.c raylib.h
	gcc raylib-test.c -o a.exe -O1 -Wall -Wno-missing-braces -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm