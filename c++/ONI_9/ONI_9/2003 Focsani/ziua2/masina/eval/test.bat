@echo off
cls
echo Problema  - MASINA
echo __________________
echo Testul %2
copy teste\%2-MASINA.in MASINA.in
timer %1 1
copy MASINA.OUT %2.O
REM copy teste\%2.oK MASINA.ok
verifdos.exe
pause
