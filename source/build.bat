@echo off

cls

if exist main.o del main.o


echo Compile
wla-z80 -o main.o main.asm 

echo [objects] > linkfile
echo main.o >> linkfile

echo Link
wlalink linkfile output.sms

if exist output.sms.sym del output.sms.sym
if exist main.o del main.o

cp output.sms ..\MegaMan2.sms

echo Run
::java -jar C:\SEGA\Emulicious\Emulicious.jar output.sms
output.sms

@echo on