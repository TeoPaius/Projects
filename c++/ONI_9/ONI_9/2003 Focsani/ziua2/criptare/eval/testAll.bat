@echo off
del criptare.pct
for %%i IN (0 1 2 3 4 5 6 7 8 9) DO  call test.bat %1 %%i
cls
echo Pentru problema CRIPTARE ati obtinut urmatoarele punctaje:
afisare %1
pause
del CRIPTARE.in
del CRIPTARE.out
del CRIPTARE.ok







