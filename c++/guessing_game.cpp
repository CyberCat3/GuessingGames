#include <iostream> // For reading cin and writing to cout.
#include <chrono> // For getting time, used to seed our rng.
#include <random> // For generating random numbers.
#include <string> // Used for readLine
#include <cctype> // Used for lowercasing chars.

#define forever for (;;) 

using namespace::std;

bool is_no(string& str) {
    int first_non_whitespace_char = str.find_first_not_of(' '); // get the index of the first non-whitespace chararacter.
    char the_char = str.at(first_non_whitespace_char); // Gets the character
    return tolower(the_char) == 'n';
}

int main() {
    uint64_t seed = chrono::system_clock::now().time_since_epoch().count(); // gets the time since Unix Epoch.
    minstd_rand rng(seed); // Creates our rng and seeds it.
    string inputbuffer; // string buffer for reading lines.

    forever {
        int target = rng() % 100 + 1; // gets a random number between 1 - 100 (inclusive).
        int guess = -1;

        cout << "Guess a number between 1 - 100!\n";

        while (guess != target) {
            cout << "Guess: ";
            getline(cin, inputbuffer); // read a line from cin into string buffer.

            try {
                guess = stoi(inputbuffer); // attempt to convert readline to a number.
            } catch (invalid_argument const &e) {
                cout << "Please type a number!\n";
                continue;
            }

            if      (guess < target) { cout << "Higher!\n"; }
            else if (guess > target) { cout << "Lower!\n"; }
        }
        cout << "You guessed it!\n";
        cout << "Play again?\n";
        cout << "(Y/n): ";
        getline(cin, inputbuffer);
        // Stop the game if the user said no.
        if (is_no(inputbuffer)) {
            break;
        }
    }
    return 0;
}