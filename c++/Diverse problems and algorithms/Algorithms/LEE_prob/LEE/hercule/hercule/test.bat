@echo off
cls
copy teste\%1.out %1.out /y >nul     

copy teste\%1.in hercule.in /y >nul 
copy teste\%1.in %1.in /y >nul



timer.exe %2 0.1

validh %1  

if exist hercule.out copy hercule.out %1.o 
pause
echo Fisier concurent: 
type %1.o
REM pause

echo Fisier comisie:
type %1.out


pause

 del hercule.in
 del hercule.out
 del *.in 
 del *.out
