@echo off
if not exist guessing_game.exe (
  echo Compiling...
  g++ -O3 guessing_game.cpp -o guessing_game.exe
)
guessing_game.exe