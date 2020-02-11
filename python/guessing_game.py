import random

while True:
    print("Guess a number between 1 - 100!")

    target = random.randint(1, 100)    
    guess = -1

    while guess != target:
        try:
            guess = int(input("Guess: "))
        except ValueError:
            print("Please type a number!")
            continue
        
        if guess < target:
            print("Higher!")
        elif guess > target:
            print("Lower!")

    print("You guessed it!")

    print("Play again?")
    if input("(Y/n): ").strip().lower().startswith("n"):
        break
