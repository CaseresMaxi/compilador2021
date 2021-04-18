"C:\GnuWin32\bin\flex" Lexico.l
pause
C:\MinGW\bin\gcc.exe C:\Users\maxy_\Desktop\clase-1\lex.yy.c -o PruebaFINAL.exe
pause
pause
PruebaFINAL.exe codigo.txt

del lex.yy.c
del PruebaFINAL.exe
pause