#include<iostream> /*lib de I/O*/
using namespace std;
void println(string value) { 
    cout << value << endl;
}


namespace Game {
    class GuessGame {
        public:
            int secret_num = 32;
            int attempts = 0;
            bool debug = true;
            bool found_secret = false;
            void play() {
                if (debug) {
                    cout << "Secret number is : " << secret_num << endl;
                }
                println("******************************");
                println("*  Welcome to Guessing Game  *");
                println("******************************");
                while (!found_secret) {
                    ask_guess();
                }
            }
        private:
            void ask_guess() {
                int current_guess;
                cout << "Write your guess: ";
                cin >> current_guess;
                validate_guess(current_guess);
            }
            void inform_response(string res) {
                cout << "Attempt " << attempts << endl;
                cout << res;
            }
            void validate_guess(int current_guess) {
                attempts ++;
                if (current_guess > secret_num)
                {
                    inform_response("You guessed to  high! try again\n");
                } else if (current_guess < secret_num)
                {
                    inform_response("You guessed to  low! try again\n");
                } else 
                {
                    found_secret = true;
                    inform_response("You guessed right,congrats!\n");
                    cout << "FINAL SCORE: " << 123 << endl;
                }
                
            }
    };
}
