@echo off
for %%i IN (0 1 2 3 4 5 6 7 8 9) DO  call test.bat %1 %%i
cls
echo Pentru problema ROMEO SI JULIETA ati obtinut urmatoarele punctaje:
afisare %1
pause
del RJ.in
del RJ.out
del RJ.AUX
del RJ.pct







