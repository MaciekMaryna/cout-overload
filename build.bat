@echo off
echo Check:
echo  - output.log 
echo  - error.log
g++ .\main.cpp -o main.exe > output.log 2> error.log
