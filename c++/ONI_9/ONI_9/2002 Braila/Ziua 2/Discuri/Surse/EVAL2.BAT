@echo off
del *.txt
del *.IN
del *.OUT
DEL discuri.rez

for %%i in (1 2 3 4 5 6 7 8 9 10) do call  runtest2 %%i %1

copy discuri.rez punctaj.txt > nul
echo Foaie punctaj concurent %1 >> nume.txt

afiseaza %1

copy nume.txt+punctaj.txt final.txt

rem copy final.txt prn


copy final.txt c:\ddd\discuri\rez\%1  > nul

type final.txt

pause


Sterg_o.bat

