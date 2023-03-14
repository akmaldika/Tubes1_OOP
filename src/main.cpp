#include "IncludeAll.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    /*
        INISIALISAI VARIABEL
    */
    GameState gameState; // udah construct game state, sama isinya (def const)
    int opt;
    int gameCounter = 0;
    string filename;
    DeckAbilityCard abilityDeck;
    Player winner;


    

    /*
        ALGORITMA PERMAINAN
    */    
 cout<<R"(
 _____________________________________________________________________
|               _             _               _                       |
|              (_)_   _  __| (_)   ___  _ __ | | ___ _ __             |
|              | | | | |/ _` | |  / _ \| '_ \| |/ _ | '_ \            |
|              | | |_| | (_| | | | (_) | | | | |  __| | | |           |
|             _/ |\__,_|\__,_|_|  \___/|_| |_|_|\___|_| |_|           |
|            |__/                                                     |
|                       _______________________                       | 
|                      \_____________________/                        |
|                       \       __O__       /                         |
|                        \      =(_)=      /              +           |
|       +                _\  ___________  /_         .  . . .         |
|        . . +          ( \\/ ___   ___.\// )       +.. .. .+         |
|        .. .. :         \    (o)) ((o)    /       ... .. . .         |
|       .. : .. .:. .    (_)    /   \    (_)      ..+.. + ...+        |
|       . .+ . ++. .       \:. (_   _) .:/         +  + :.. + :       |
|        . __... . +        )::::\_/::::(            :. __  . .       |
|        _(  \ __ .        (:::\_|_|_/:::)          __ /  )_          |
|       (  \  (  \      __  \:::\_|_/:::/  __      /  )  /  )         |
|        \  \  \  \    /  )  \:::::::::/  (  \    /  /  /  /          |
|       ( \  \  \  \__/  /    |\:::::/|    \  \__/  /  /  //)         |
|        \ \_ \_ \_     / ____| |___| |____ \     _/ _/ _/ /          |
|         \            /_/ ||   |___|   || \_\            /           |
|          \          /\   ||  (_____)  ||   /\          /            | 
|           \________/ \\  ||___________||  // \________/             | 
|____________\\_______//    |___________|   \\______//________________|
              \______/_:                   :_\______/

        )" << endl;
    
    cout << "             \"Sudahi tubesmu sini judi bersamaku        \n";
    cout << "                    Eh tubesnya bikin bandar judi yah\"   \n";
    cout << "                                             - The Dealer\n\n";

    cout << "----------   Choose Deck Order By    ---------- " << endl;
    cout << "1. Random" << endl;
    cout << "2. File" << endl;
    

    while(true){
        try{
            cout << "(1/2) Your Choice : ";
            cin >> opt;
            if(!(opt == 1 || opt == 2)){
                throw (opt);
            }
            else {
                break;
            }
        }
        catch(...){
            cout << "----------   Invalid Input!    ---------- " << endl;
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
                cout << "----------   File Not Found!    ---------- "<< endl;
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
                cout << "----------   File Not Found!    ---------- "<< endl;
            }
        }
    }

    while(!gameState.checkAllWin()){
        gameCounter++;
        cout << "\n                         GAME " << gameCounter << "\n";

        // PLAY FIRST ROUND
        for (int i = 0; i < 7 ; i++){ // per turn
            gameState.printInterface(); // nanti ganti
            gameState.inputActionFirstRound();
            //gameState.inputRandom();
            gameState.evaluateAction();
            gameState.NextTurn();
        }
        gameState.NextRound();


        // Draw Ability Card
        for (int i = 0; i < 7 ; i++){
            gameState.getPlayer(i).setAbility(abilityDeck.getDeckAbilityCard().at(i));
        }

        //PLAY ROUND 2-7
        for(int i = 0; i < 5 ; i++){ // per round
            for(int j = 0; j < 7 ; j++){ // per turn
                gameState.printInterface(); // nanti ganti
                gameState.inputAction();
                //gameState.inputRandom();
                gameState.evaluateAction();
                gameState.NextTurn();
            }
            gameState.NextRound();
        }
        gameState.getGameWinner();

        gameState.resetGameState();
    } 


    winner = gameState.getAllWinner();
    // for (int i=0; i<7; i++){
    //     gameState.getPlayer(i).status();
    // }
    cout << "The winner of the game is: " << endl;
    winner.status();

    return 0;
}

