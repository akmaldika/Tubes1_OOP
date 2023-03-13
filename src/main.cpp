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
            if(opt != 1 || opt != 2){
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

    // PLAY FIRST ROUND

    gameState.printState(); // nanti ganti 


    
    





    return 0;
}

