@echo off
del SETI.pct
for %%i IN (  1 2 3 4 5 6 7 8 9 10) DO  call test.bat %1 %%i
cls
echo Pentru problema SETI ati obtinut urmatoarele punctaje:
afisare.exe %1
pause
del SETI.in
del SETI.out
del SETI.ok







