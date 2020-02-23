use rand::{thread_rng, Rng};
use std::io::{stdin, stdout, Write};

fn main() {
    let mut rng = thread_rng(); // our random number generator.
    let mut line = String::new(); // our string buffer for reading user input.

    loop {
        println!("Guess a number between 1 - 100!");
        let target = rng.gen_range(1, 101); // low: inclusive, high: exclusive

        loop {
            print!("Guess: ");
            stdout().flush().unwrap(); // need the flush after print!
            line.clear(); // clear the buffer so it doesn't accumulate
            stdin().read_line(&mut line).unwrap(); // read a line from stdin into our string buffer

            let guess: i32 = match line.trim().parse() { // parse the input
                Ok(num) => num,
                Err(_) => {
                    println!("Please type a number!");
                    continue;
                }
            };

            if      guess < target  { println!("Higher!"); }
            else if guess > target  { println!("Lower!");  }
            else if guess == target { break;               }
        }

        println!("You guessed it!");
        println!("Play again?");
        print!("(Y/n): ");
        stdout().flush().unwrap();

        line.clear();
        stdin().read_line(&mut line).unwrap();

        if line.trim_start().to_lowercase().starts_with("n") {
            break;
        }
    }
}