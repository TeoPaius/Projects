@echo off
cls
echo Problema  - SCAUNE
echo __________________
echo Testul %2
copy teste\%2.in SCAUNE.IN
timer %1 1
copy SCAUNE.OUT %2.O
copy teste\%2.oK SCAUNE.OK
verif.exe
pause
