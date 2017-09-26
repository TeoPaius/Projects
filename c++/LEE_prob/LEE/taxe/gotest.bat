@echo off
echo ======================
echo Testul %2
copy in\taxe%2.10 taxe.in /y
timer %1 19
if Errorlevel 2 goto timeout
copy out\rez%2.10 taxe.rez/y
echo ------------------------
echo REZULTATUL CONCURENTULUI
type taxe.out
echo ...
echo ------------------------
echo REZULTATUL COMISIEI
type taxe.rez
echo ...
echo ------------------------
echo DACA REZULTATELE COINCID, SE ACORDA 10 PUNCTE ALTFEL SE ACORDA 0 PUNCTE
goto end
:timeout
echo TIMPUL ESTE DEPASIT. SE ACORDA 0 PUNCTE
:end
pause
if exist taxe.in del taxe.in
if exist taxe.out del taxe.out
if exist taxe.rez del taxe.rez
echo .

