@echo off

echo GENERATE

echo Lib files:
if not exist external\stb\stb_image.h (
    echo     Downloading stb_image.h
    powershell wget https://github.com/nothings/stb/blob/master/stb_image.h?raw=true -o external\stb\stb_image.h
    echo     stb_image.h present
)

if not exist external\stb\stb_image_write.h (
    echo     Downloading stb_image_write.h
    powershell wget https://github.com/nothings/stb/blob/master/stb_image_write.h?raw=true -o external\stb\stb_image_write.h
) else (
    echo     stb_image_write.h present
)

echo Generating build files

cmake -S . -B build/
