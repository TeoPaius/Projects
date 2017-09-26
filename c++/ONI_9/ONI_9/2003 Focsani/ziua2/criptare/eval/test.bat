@echo off
cls
echo Problema  - CRIPTARE
echo __________________
echo Testul %2
copy teste\%2.in CRIPTARE.in
timer %1 1
copy CRIPTARE.OUT %2.O
copy teste\%2.oK criptare.ok
verif.exe
pause
