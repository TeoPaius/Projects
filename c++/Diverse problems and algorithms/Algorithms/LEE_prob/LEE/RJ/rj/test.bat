@echo off
cls
echo Problema 2 - ROMEO SI JULIETA
echo __________________
echo Testul %2
copy teste\%2-rj.in rj.in
timer %1 1
copy teste\%2-rj.aux rj.aux
verif.exe %2
pause
