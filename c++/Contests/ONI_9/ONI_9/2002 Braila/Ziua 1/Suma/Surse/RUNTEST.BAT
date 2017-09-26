@echo off
cls
echo CONCURENT %2    TESTUL %1
echo ===============================
REM pregatire pentru executie
copy teste\%1.IN suma.IN /y >nul

REM lansare executie program concurent
REM %2 numele programului concurentului, 1 timpul
timer.exe %2 1

copy teste\%1.IN suma.IN /y >nul
copy teste\%1.out corect.txt /y >nul


evsuma

del *.IN
del *.OUT
