@echo off
if not exist target/release/rust_guessing_game.exe (
  echo Compiling...
  cargo build --release
)
"target/release/rust_guessing_game.exe"