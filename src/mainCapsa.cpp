#include "IncludeAllCapsa.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    /*
        INISIALISAI VARIABEL
    */
    GameStateCapsa gameState; // udah construct game state, sama isinya (def const)
    int opt;
    int gameCounter = 0;
    string filename;
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
    
    InputApp deckOrder;
    opt = deckOrder.takeIntInput(2);

    // Input Deck From File
    if (opt == 2){
        cout << "\n----------   Input Deck Card File    ---------- " << endl;
        InputApp deckCardFile;
        GameStateCapsa stateFromfile("../test/" + deckCardFile.takeFilenameInput("Card"));
        gameState = stateFromfile;
    }

    // Input Player Name
    InputApp playerName;
    cout << "\n----------   Input Player Name    ---------- " << endl;

    int i = 0;
    for (auto& player : gameState.getAllPlayer()){
        cout << "Player " << i << " : ";
        i++;
        playerName.takeStrInput();
        player.setPlayerName(playerName.getStrInput());
    }

    while(!gameState.checkAllWin()){
        gameCounter++;
        cout << "\n                             GAME " << gameCounter << "\n";

        gameState.updateTurn();
        for (int i = 0; i < 4 ; i++){ // per turn
            gameState.printInterface(); // nanti ganti
            gameState.inputAction();
            //gameState.inputRandom();
            gameState.evaluateAction();
            gameState.NextTurn();
        }
        
        gameState.NextRound();
        gameState.resetGameState();
        
    } 


    // for (int i=0; i<7; i++){
    //     gameState.getPlayer(i).status();
    // }

    cout << "---------   The winner of the game is:    ---------- " << endl;

    gameState.getAllWinner().status();
    cout << "------------------   Congrats    -------------------- " << endl;

    gameState.printLeaderboard();

    // Try Again
    cout << "\n----------   Do you want to try again?    ---------- " << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;

    InputApp tryAgain;
    int tryAgainOpt = tryAgain.takeIntInput(2);
    if (tryAgainOpt == 1){
        system("make run");
    }
    else {
        cout << "\nThank you for playing!" << endl;
    }

    return 0;
}