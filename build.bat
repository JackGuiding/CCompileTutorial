gcc src\main.c -c -o build\main.o
gcc build\main.o lib\raylib.dll -o bin\main.exe
start bin\main.exe