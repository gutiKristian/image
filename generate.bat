@echo off

echo GENERATE

echo Lib files:
if not exist libs\stb_image.h (
    echo     Downloading stb_image.h
    powershell wget https://github.com/nothings/stb/blob/master/stb_image.h?raw=true -o lib\stb_image.h
    echo     stb_image.h present
)

if not exist libs\stb_image_write.h (
    echo     Downloading stb_image_write.h
    powershell wget https://github.com/nothings/stb/blob/master/stb_image_write.h?raw=true -o lib\stb_image_write.h
) else (
    echo     stb_image_write.h present
)

echo Generating build files

cmake -S . -B build/
