loop do
    target = rand(1..100) # .. is inclusive range, ... is exclusive on upper bound
    guess = nil
    
    puts "Guess a number between 1 - 100!"

    while guess != target do
        print "Guess: "
        begin # begin-rescue is equivalent to try-catch.
            guess = Integer(STDIN.gets) # STDIN. prefix is nessecary, else gets also reads command line args.
        rescue
            puts "Please type a number!"
            next # continue is called next in ruby.
        end
    
        if    guess < target then puts "Higher!"
        elsif guess > target then puts "Lower!"
        end
    end
    puts "You guessed it!"
    puts "Play again?"
    puts "(Y/n): "
    # reads user input, trims it, gets the first character, check if it's no, in which case we stop the game.
    if STDIN.gets.lstrip().downcase[0] == "n" then break end
end