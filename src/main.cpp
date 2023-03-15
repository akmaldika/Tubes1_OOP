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
                cout << "Deck Card Filename (inside test folder): ";
                cin >> filename ;

                GameState stateFromfile("../test/" + filename + ".txt");
                gameState = stateFromfile; 
                
            }
            catch(...){
                cout << "----------   File Not Found!    ---------- "<< endl;
            }
        }

        while(true){
            try{
                cout << "Deck Ability Filename (inside test folder): ";
                cin >> filename ;

                DeckAbilityCard deckFromfile("../test/" + filename + ".txt");
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
        gameState.HandUpdate();
        cout << "out\n";
        for (int i = 0; i < 7 ; i++){ // per turn
            gameState.printInterface(); // nanti ganti
            //gameState.inputAction();
            gameState.inputRandom();
            gameState.evaluateAction();
            gameState.NextTurn();
        }
        gameState.NextRound();


        //Draw Ability Card
        for (int i = 0; i < 7 ; i++){
            gameState.getPlayer(i).setAbility(abilityDeck.getDeckAbilityCard().at(i));
        }
        //cout << "Ciee udh dapat ability"<<endl;

        //PLAY ROUND 2-7
        for(int i = 0; i < 5 ; i++){ // per round
            gameState.HandUpdate();
            for(int j = 0; j < 7 ; j++){ // per turn
                gameState.printInterface(); // nanti ganti
                //gameState.inputAction();
                gameState.inputRandom();
                gameState.evaluateAction();
                gameState.NextTurn();
            }
            gameState.NextRound();
        }
        gameState.getGameWinner();

        gameState.resetGameState();
    } 


    // for (int i=0; i<7; i++){
    //     gameState.getPlayer(i).status();
    // }
    cout << "The winner of the game is: " << endl;
    gameState.getAllWinner().status();

    gameState.printLeaderboard();

    cout << "\nDo you want to try again?" << endl;
    char c;
    while(true){
        try{
            cout << "\n(y/n) Your Choice : ";
            cin >> c;
            if(!(c == 'n' || c == 'y')){
                throw (c);
            }
            else {
                break;
            }
        }
        catch(...){
            cout << "\n----------   Invalid Input!    ---------- " << endl;
        }
    }
    if (c == 'y'){
        system("../bin/main");
    }
    else {
        cout << "\nThank you for playing!" << endl;
    }

    return 0;
}