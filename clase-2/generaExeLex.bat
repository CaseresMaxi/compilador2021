"F:\GnuWin32\bin\flex" Lexico2.l
pause
"F:\GnuWin32\bin\bison" -dyv sintactico.y
pause
C:\MinGW\bin\gcc.exe lex.yy.c y.tab.c -o TPFinal.exe
pause
pause

TPFinal.exe codigo2.txt

del lex.yy.c
del TPFinal.exe
del y.tab.c 
del y.tab.h
pause