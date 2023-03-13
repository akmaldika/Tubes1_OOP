#include "Cards/header/Card.hpp"
#include "Cards/header/Combo.hpp"
#include "GameEngine/header/GameEngine.hpp"
#include "GameState/header/GameState.hpp"
#include "InventoryHolder/header/DeckCard.hpp"
#include "InventoryHolder/header/PlayerCard.hpp"
#include "InventoryHolder/header/TableCard.hpp"
#include "Player/Player.hpp"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    GameState gameState; // udah construct game state, sama isinya (def const)
    int opt;
    string filename;


    cout << "Splash Screen" << endl;


    cout << "Pilih urutan deck:" << endl;
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
            cout << "Input Invalid! Silahkan ulangi." << endl;
        }
    }

    if (opt == 2){
        while(true){
            try{
                cin >> filename ;

                GameState fromfile(filename);
                gameState = fromfile; 
                
            }
            catch(...){
                cout << "File tidak ditemukan!"<< endl;
            }
        }
    }

    // PLAY FIRST ROUND
    

    
    





    return 0;
}

