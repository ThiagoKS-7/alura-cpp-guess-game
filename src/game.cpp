#include <iostream> /*lib de I/O*/
#include <cstdlib>
using namespace std;



void println(string value) { 
    cout << value << endl;
}

namespace Game {
    class GuessGame {
        public:
            const int SECRET_NUM = rand() % 100; /*valores de 1 a 100*/
            int attempts = 1;
            int difficulty = 0;
            int max_attempts = 0;
            int current_guess;
            double score = 1000.0;
            double penalty;
            bool debug = false;
            bool found_secret = false;

            void play() {
                if (debug) {
                    cout << "[DEBUG] Secret number is : " << SECRET_NUM << endl;
                }
                println("******************************");
                println("*  Welcome to Guessing Game  *");
                println("******************************");
                max_attempts = get_max_attempts_by_difficulty();
                while (!found_secret && attempts <= max_attempts) {
                    ask_guess();
                }
                if (!found_secret) {
                    println("\n***************");
                    println("*  GAME OVER  *");
                    println("***************");
                    println("Sorry, you lost. The secret number was: " + to_string(SECRET_NUM));
                }
            }
        private:
            int get_max_attempts_by_difficulty() {
                while (difficulty < 1 || difficulty > 3) {
                    println("\nChoose your difficulty level: ");
                    println("(1) Easy, (2) Normal, (3) Hard");
                    cout << "> ";
                    cin >> difficulty;
                }
                switch (difficulty) {
                    case 1:
                        return 15;
                    case 2:
                        return 10;
                    case 3:
                        return 5;
                    default:
                        return 10;
                }
            }
            double calculate_penalty(int guess) {
                penalty = abs((double)(SECRET_NUM - guess)/2);
                return penalty > 0 ? penalty : 1;
            }
            void ask_guess() {
                if (attempts == 1) {
                    println("Attempt #1: ");
                }
                cout << "Write your guess: ";
                cin >> current_guess;
                validate_guess(current_guess);
            }
            void validate_guess(int current_guess) {
                score = score -  calculate_penalty(current_guess);
                if (current_guess > SECRET_NUM)
                {   
                    inform_response("You guessed too high! Try again\n");
                } else if (current_guess < SECRET_NUM)
                {
                    inform_response("You guessed too low! Try again\n");
                } else 
                {
                    found_secret = true;
                    cout.precision(2);
                    //precisa explicitar pra não sair em notação científica
                    cout << fixed; 
                    println("\n**************");
                    println("*  WINNER!!  *");
                    println("**************");
                    cout << "FINAL SCORE: " << score << endl;
                }
            }
            void inform_response(string res) {
                cout << res;
                attempts ++;
                if (!found_secret && attempts <= max_attempts) {
                    cout << "\nAttempt #" << attempts << ": " << endl;
                }
            }
    };
}
