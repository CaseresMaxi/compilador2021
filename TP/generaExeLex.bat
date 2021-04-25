"E:\Lenguajes\GnuWin32\bin\flex" Lexico2.l
pause
"E:\Lenguajes\GnuWin32\bin\bison" -dyv sintactico.y
pause
E:\Lenguajes\MinGW\bin\gcc.exe lex.yy.c y.tab.c -o TPFinal.exe
pause
pause

TPFinal.exe codigo2.txt

del lex.yy.c
del TPFinal.exe
del y.tab.c 
del y.tab.h
pause