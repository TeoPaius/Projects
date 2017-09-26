@echo off
del SCAUNE.pct
for %%i IN (0 1 2 3 4 5 6 7 8 9) DO  call test.bat %1 %%i
cls
echo Pentru problema SCAUNE ati obtinut urmatoarele punctaje:
afisare %1
pause
del SCAUNE.in
del SCAUNE.out
del SCAUNE.ok







