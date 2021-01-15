@echo off

clear

if [ -a main.o ]
then
    rm main.o
fi

echo Compile
wla-z80 -o main.o main.asm 

echo [objects] > linkfile
echo main.o >> linkfile

echo Link
wlalink linkfile output.sms

cp output.sms ../MegaMan2.sms

echo Run
# https://linuxhint.com/what_is_dev_null
java -jar ~/SEGA/Emulicious/Emulicious.jar output.sms 2> /dev/null
#output.sms


if [ -a main.o ]
then
    rm main.o
fi
