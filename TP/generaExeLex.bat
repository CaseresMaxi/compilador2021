C:\GnuWin32\bin\flex.exe Lexico.l
pause
C:\GnuWin32\bin\bison.exe -dyv Sintactico.y
pause
C:\MinGW\bin\gcc.exe lex.yy.c y.tab.c -o Primera.exe
pause
pause

Primera.exe prueba.txt

del lex.yy.c
del Primera.exe
del y.tab.c 
del y.tab.h
pause