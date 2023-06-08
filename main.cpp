#include"src/game.cpp"
#include <ctime>

using namespace Game;

int main() {
    srand(time(NULL));
    GuessGame game;
    game.play();
    return 0;
}

