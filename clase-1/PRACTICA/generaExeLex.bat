C:\GnuWin32\bin\flex Lexico.l
pause
C:\MinGW\bin\gcc.exe lex.yy.c -o PruebaFINAL.exe
pause
pause
PruebaFINAL.exe codigo.txt

del lex.yy.c
del PruebaFINAL.exe
pause