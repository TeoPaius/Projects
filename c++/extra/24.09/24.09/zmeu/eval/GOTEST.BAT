@echo off
echo ======================
echo Testul %2
copy in\zmeu.%2 zmeu.in /y
timer %1 40
if Errorlevel 2 goto timeout
copy out\zmeu.o%2 zmeu.rez/y
echo ------------------------
echo REZULTATUL CONCURENTULUI
type zmeu.out
echo ...
echo ------------------------
echo REZULTATUL COMISIEI
type zmeu.rez
echo ...
echo ------------------------
echo DACA REZULTATELE COINCID, SE ACORDA 10 PUNCTE ALTFEL SE ACORDA 0 PUNCTE
goto end
:timeout
echo TIMPUL ESTE DEPASIT. SE ACORDA 0 PUNCTE
:end
pause
if exist zmeu.in del zmeu.in
if exist zmeu.out del zmeu.out
if exist zmeu.rez del zmeu.rez
echo .

