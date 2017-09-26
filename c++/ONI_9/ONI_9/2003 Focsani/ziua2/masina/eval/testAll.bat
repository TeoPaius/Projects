@echo off
del MASINA.pct
for %%i IN (1 2 3 4 5 6 7 8 9) DO  call test.bat %1 %%i
cls
echo Pentru problema MASINA ati obtinut urmatoarele punctaje:
afisare %1
pause
del MASINA.in
del MASINA.out
del MASINA.ok







