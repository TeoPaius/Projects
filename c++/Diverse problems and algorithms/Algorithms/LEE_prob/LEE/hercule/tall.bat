@echo off
del punctaj.txt >nul
for %%i in (1  2  3  4  5 6 7 8 9 10) do call test %%i %1
afiseaza %1
pause
call sterg_o