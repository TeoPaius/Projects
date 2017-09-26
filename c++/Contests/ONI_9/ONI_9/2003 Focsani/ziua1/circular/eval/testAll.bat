@echo off
del CIRCULAR.pct
for %%i IN (0 1 2 3 4 5 6 7 8 9) DO  call test.bat %1 %%i
cls
echo Pentru problema CIRCULAR ati obtinut urmatoarele punctaje:
afisare %1
pause
del CIRCULAR.in
del CIRCULAR.out
del CIRCULAR.ok







