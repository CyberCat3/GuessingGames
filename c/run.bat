@echo off
if not exist guessing_game.exe (
  echo Compiling...
  gcc -O3 guessing_game.c -o guessing_game.exe
)
guessing_game.exe