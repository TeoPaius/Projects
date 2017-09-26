@echo off
cls
echo Problema  - CIRCULAR
echo __________________
echo Testul %2
copy teste\%2.in CIRCULAR.in
timer %1 1
copy CIRCULAR.OUT %2.O
copy teste\%2.oK CIRCULAR.ok
verif.exe
pause
