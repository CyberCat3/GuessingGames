package main

import (
	"bufio"     // for the scanner
	"fmt"       // for println
	"math/rand" // for rng
	"os"        // for stdin
	"strconv"   // for converting strings to integers
	"strings"   // for trimming
	"time"      // for seeding our rng
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	rng := rand.NewSource(time.Now().UnixNano())

	for {
		fmt.Println("Guess a number between 1 - 100!")

		target := int(rng.Int63()%100 + 1)
		guess := -1 // shorthand for 'var guess = 1;'

		for target != guess {
			fmt.Print("Guess: ")
			scanner.Scan()
			input, err := strconv.Atoi(strings.TrimSpace(scanner.Text()))

			if err != nil {
				fmt.Println("Please type a number!")
				continue
			}
			guess = input

			if guess < target {
				fmt.Println("Higher!")
			} else if guess > target {
				fmt.Println("Lower!")
			}
		}
		fmt.Println("You guessed it!")

		fmt.Println("Play again?")
		fmt.Print("(Y/n): ")
		scanner.Scan()
		if strings.HasPrefix(strings.ToLower(strings.TrimSpace(scanner.Text())), "n") {
			break
		}
	}
}
