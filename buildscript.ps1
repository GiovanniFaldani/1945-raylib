Copy-Item -Path ".\assets" -Destination ".\bin\assets" -Recurse
Copy-Item ".\lib\raylib.dll" -Destination ".\bin"
# TODO Remember to update with additional source files
clang -I .\include\ -o .\bin\1945.exe -L .\lib -l raylibdll .\src\main.c .\src\sprites.c