#include <SFML/Audio.hpp>
#include "Game.h"


int main(){

    Game game;
    
    while (!game.gameOver()) {
        game.update();
    }
    
    if (game.gameOver()) game.closeWindow();
}