E:\Lenguajes\GnuWin32\bin\flex Lexico.l
E:\Lenguajes\GnuWin32\bin\bison -dyv Sintactico.y
pause
E:\Lenguajes\MinGW\bin\gcc.exe lex.yy.c y.tab.c -o Segunda.exe
pause

Segunda.exe prueba.txt

del lex.yy.c
del y.tab.c 
del y.tab.h
del y.output
pause