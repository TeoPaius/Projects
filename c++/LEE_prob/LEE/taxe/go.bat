@echo off
if "%1"=="" goto eroare1
if not exist %1 goto eroare2
cd in
..\comisie\in.exe -y
cd..
cd out
..\comisie\out.exe -y
cd..
cls
for %%i in (1 2 3 4 5 6 7 8 9 10) do call gotest %1 %%i
echo gata
echo .
echo .
goto end
:eroare1
echo Trebuie precizat numele complet al executabilului care se testeaza
goto end
:eroare2
echo Executabilul precizat nu exista sau este scris incorect sau incomplet
:end 
