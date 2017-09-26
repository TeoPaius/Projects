@echo off
del *.txt >nul
for %%i in (1 2 3 4 5 6 7 8 9 10) do call  runtest %%i %1
cls

echo Foaie punctaj concurent %1 >> nume.txt

copy rezultat.txt punctaj.txt > nul


afiseaza %1

copy nume.txt+punctaj.txt final.txt

rem copy final.txt prn


copy final.txt c:\oni2002\sumarez\%1

type final.txt

pause


Sterg_o.bat


