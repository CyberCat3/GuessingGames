extern crate rand;

use rand::Rng;
use std::io::{stdin, stdout, Write};

fn main() {
    // Our rng
    let mut rng = rand::thread_rng();

    loop {
        // Generates a random number between 0 and 100.
        let random_number = rng.gen_range(1, 101);

        println!("Guess a number between 1 - 100!");
        loop {
            print_and_flush("Guess: ");

            // Reads a line from stdin and parses it, trim is necessary to remove \n
            let guess: u32 = match read_line().trim().parse() {
                Ok(num) => num,
                Err(_) => {
                    println!("Please type a number!");
                    continue;
                }
            };

            if guess < random_number { println!("Higher!"); }
            else if guess > random_number { println!("Lower!"); }
            else {
                println!("You guessed it!");
                break;
            }
        }

        println!("Play again?");
        print_and_flush("(Y/n): ");
        // reads a line, trims it, makes it lowercase,
        // gets the first character, then checks if it's 'n',
        // and if it is, stops the game.
        if read_line().trim().to_lowercase().chars().nth(0).unwrap() == 'n' {
            break;
        }
    }
}

fn print_and_flush(input: &str) {
    print!("{}", &input);
    // stdout flushes automatically on \n, so we need to do it manually.
    stdout().flush().expect("Couldn't flush stdout");
}

fn read_line() -> String {
    // Creates a string buffer for reading stdin.
    let mut string_buffer = String::new();

    // reads a line from stdin in puts it into our buffer.
    // If we can't read a line, let's just crash the entire program.
    stdin().read_line(&mut string_buffer).expect("Couldn't read line");
    string_buffer // implicit return
}
