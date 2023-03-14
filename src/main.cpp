#include "IncludeAll.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    /*
        INISIALISAI VARIABEL
    */
    GameState gameState; // udah construct game state, sama isinya (def const)
    int opt;
    string filename;
    DeckAbilityCard abilityDeck;
    Player winner;
    
try{
    

    /*
        ALGORITMA PERMAINAN
    */
    cout << "Splash Screen" << endl;


    cout << "Deck Order By:" << endl;
    cout << "1. Random" << endl;
    cout << "2. File" << endl;

    while(true){
        try{
            cin >> opt;
            if(!(opt == 1 || opt == 2)){
                throw (opt);
            }
            else {
                break;
            }
        }
        catch(...){
            cout << "Invalid Input!" << endl;
        }
    }

    if (opt == 2){
        while(true){
            try{
                cout << "insert deck card file name: ";
                cin >> filename ;

                GameState stateFromfile(filename);
                gameState = stateFromfile; 
                
            }
            catch(...){
                cout << "File not found!"<< endl;
            }
        }

        while(true){
            try{
                cout << "insert deck ability file name: ";
                cin >> filename ;

                DeckAbilityCard deckFromfile(filename);
                abilityDeck = deckFromfile; 
                
            }
            catch(...){
                cout << "File not found!"<< endl;
            }
        }
    }

    while(!gameState.checkAllWin()){

        // PLAY FIRST ROUND
        for (int i = 0; i < 7 ; i++){ // per turn
            gameState.printState(); // nanti ganti
            //gameState.inputActionFirstRound();
            gameState.inputRandom();
            gameState.evaluateAction();
            gameState.NextTurn();
        }
        gameState.NextRound();

        cout << "masuk ronde selanjutnya\n";

        // Draw Ability Card
        for (int i = 0; i < 7 ; i++){
            gameState.getPlayer(i).setAbility(abilityDeck.getDeckAbilityCard().at(i));
        }

        //PLAY ROUND 2-7
        for(int i = 0; i < 5 ; i++){ // per round
            for(int j = 0; j < 7 ; j++){ // per turn
                gameState.printState(); // nanti ganti
                // gameState.inputAction();
                gameState.inputRandom();
                gameState.evaluateAction();
                gameState.NextTurn();
            }
            gameState.NextRound();
        }
        gameState.getRoundWinner();
    }

    winner = gameState.getAllWinner();
    cout << "The winner is: " << endl;
    winner.status();

    return 0;

}

catch(...){
    cout << "ada exception somewhere"<< endl;
}
}

