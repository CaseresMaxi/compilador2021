C:\GnuWin32\bin\flex Lexico.l
C:\GnuWin32\bin\bison -dyv Sintactico.y

C:\MinGW\bin\gcc.exe lex.yy.c y.tab.c -o Segunda.exe


Segunda.exe prueba.txt

del lex.yy.c
del y.tab.c 
del y.tab.h
del y.output
pause