@echo off
if not exist guessing_game.exe (
  echo Compiling...
  go build -o guessing_game.exe
)
guessing_game.exe