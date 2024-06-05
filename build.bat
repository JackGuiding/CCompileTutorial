gcc src\main.c -c -o build\main.o
gcc src\Physics2D.c -c -o build\Physics2D.o
gcc build\main.o build\Physics2D.o lib\raylib.dll -o bin\main.exe
start bin\main.exe