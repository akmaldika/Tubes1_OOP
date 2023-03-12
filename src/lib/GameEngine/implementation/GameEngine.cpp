#include "../header/GameEngine.hpp"


GameEngine::GameEngine(){
    gameCount = 1;
}

GameEngine::GameEngine(DeckCard inputDeck)
: gameState(inputDeck)
{
    gameCount = 1;
    
}

int GameEngine::getGameCount(){
    return gameCount;
}

void GameEngine::PlayFirstRound(){
    for (int i = 0; i < 7 ; i++){
        printGameInterface();
        gameState.inputActionFirstRound();
        gameState.evaluateAction();
        gameState.NextTurn();
    }
}

void GameEngine::PlayOtherRound(){ // add card table
    for(int i = 0; i < 7; i++){
        printGameInterface();
        gameState.inputAction();
        gameState.NextTurn();
    }
}