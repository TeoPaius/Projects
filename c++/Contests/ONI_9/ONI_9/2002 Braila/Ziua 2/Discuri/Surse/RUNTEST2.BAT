@echo off
echo CONCURENT %2    TESTUL %1
echo ===============================
REM pregatire pentru executie
copy c:\ddd\discuri\teste\%1.in discuri.in >nul

REM lansare executie program concurent
REM %2 numele programului concurentului, 1 timpul
timer.exe %2 5

copy c:\ddd\discuri\teste\%1.in discuri.in  >nul
copy c:\ddd\discuri\teste\%1.out corect.txt >nul

evdisc.exe



