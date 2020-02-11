import scala.io.StdIn; // For reading user input
import scala.util.Random; // For generating random numbers

// Boiler plate, like Java just without psvm method, which the 'extends app' adds.
object GuessingGame extends App {
    var playAgain = true // Scala loops don't directly support break and continue, so we use a flag instead.
    val rng = new Random()

    while (playAgain) {
        val target = rng.nextInt(100) + 1
        var guess = -1

        println("Guess a number between 1 - 100!")
        
        while (guess != target) {
            try { // everything is in try block, due to lack of continue statement.
                print("Guess: ")
                guess = StdIn.readInt()

                if      (guess < target) { println("Higher!") }
                else if (guess > target) { println("Lower!") }

            } catch {
                case e: NumberFormatException => {
                    println("Please type a number!")
                }
            }
        }
        println("You guessed it!")
        println("Play again?")
        print("(Y/n): ")
        // reads a line, trims it, makes it lowercase, gets the first character and checks if it's not 'n'.
        playAgain = StdIn.readLine().trim().toLowerCase().charAt(0) != 'n';
    }
}