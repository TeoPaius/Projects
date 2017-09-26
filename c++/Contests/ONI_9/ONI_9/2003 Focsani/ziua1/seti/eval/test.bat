@echo off
cls
echo Problema  - SETI
echo __________________
echo Testul %2
copy teste\%2.in SETI.in
timer %1 1
copy SETI.OUT %2.O
copy teste\%2.oK SETI.ok
verif.exe seti.in seti.out
pause
