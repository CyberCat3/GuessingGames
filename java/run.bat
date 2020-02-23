@echo off
if not exist GuessingGame.jar (
  echo Compiling...
  javac GuessingGame.java
  jar -cfe GuessingGame.jar GuessingGame GuessingGame.class
  del  GuessingGame.class
)
java -jar GuessingGame.jar