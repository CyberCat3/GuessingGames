import java.util.*;
import java.lang.*;

public class GuessingGame {
    public static void main(String... args) {
        Random rng = new Random();
        Scanner scanner = new Scanner(System.in);

        do {
            int target = 1 + rng.nextInt(100);
            int guess = -1;
            System.out.println("Guess a number between 1 - 100!");
    
            while (target != guess) {
                try {
                    System.out.print("Guess: ");
                    guess = Integer.parseInt(scanner.nextLine());
                } catch (NumberFormatException e) {
                    System.out.println("Please type a number!");
                    continue;
                }
    
                if      (guess < target) { System.out.println("Higher!"); }
                else if (guess > target) { System.out.println("Lower!"); }
                else {
                    System.out.println("You guessed it!");
                }
            }
            System.out.println("Play again?");
            System.out.print("(Y/n): ");
        } while (scanner.nextLine().trim().toLowerCase().charAt(0) != 'n');


        scanner.close(); // This is not nessecary but it makes VSCode happy.
        // I hope you're happy now Code, you better be.
    }
}