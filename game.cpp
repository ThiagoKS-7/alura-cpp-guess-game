#include<iostream> /*lib de I/O*/
using namespace std;
void println(string value) { 
    cout << value << endl;
}


namespace Game {
    class GuessGame {
        public:
            const int SECRET_NUM = 32;
            int attempts = 0;
            double score = 1000.0;
            bool debug = true;
            bool found_secret = false;

            void play() {
                if (debug) {
                    cout << "Secret number is : " << SECRET_NUM << endl;
                }
                println("******************************");
                println("*  Welcome to Guessing Game  *");
                println("******************************");
                while (!found_secret) {
                    ask_guess();
                }
            }
            double calculate_penalty(int guess) {
                double penalty = abs((double)(SECRET_NUM - guess)/2);
                return penalty > 0 ? penalty : 1;
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
                score = score -  calculate_penalty(current_guess);
                cout << score;
                if (current_guess > SECRET_NUM)
                {   
                    inform_response("You guessed too high! try again\n");
                } else if (current_guess < SECRET_NUM)
                {
                    inform_response("You guessed too low! try again\n");
                } else 
                {
                    found_secret = true;
                    inform_response("You guessed right,congrats!\n");
                    cout.precision(2);
                    //precisa explicitar pra não sair em notação científica
                    cout << fixed; 
                    cout << "FINAL SCORE: " << score << endl;
                }
                
            }
    };
}
