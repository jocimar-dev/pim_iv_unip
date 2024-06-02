@echo off
set CC=gcc
set CFLAGS=-Wall -Iinclude
set SRCDIR=src
set BINDIR=bin
set TARGET=%BINDIR%\program.exe

if not exist %BINDIR% (
    mkdir %BINDIR%
)

echo Compiling...
%CC% %CFLAGS% %SRCDIR%\main.c %SRCDIR%\usuario.c %SRCDIR%\industria.c %SRCDIR%\relatorio.c -o %TARGET%

echo Done!
pause
