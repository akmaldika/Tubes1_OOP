//#include "Ability.hpp"
#include "../../Player/header/PlayerCapsa.hpp"
#include "../../Cards/header/Combo.hpp"
#include "../../utilityFunction.cpp"
#include "../../InputApp/header/InputApp.hpp"
#include "../../Exceptions/header/Exceptions.hpp"
#include <vector>
#include <algorithm>
#include <random>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
using namespace std;

/*
    KELAS GAMESTATE
    State dari game pada setiap roundnya

*/
class GameStateCapsa {

    private:
    // ATTRIBUTE
        vector<PlayerCapsa> AllPlayer;  // array semua player yang terurut berdasarkan gilirannya
        int Round; // hitungan ronde

        /*  TURN
            giliran player yang mana saat ini.
            pair->first = urutan player/ index dalam vector
            pair->second = objek playernya
        */
        pair<int, PlayerCapsa&> Turn;

        /*
            aksi player di turn ini
            0. Empty
            1. Double
            2. Next
            3. Half
            4. Ability
        */
        string Action;
        const int bid = 1000;

    public:
    // CONSTRUCTOR
        /*
            Const
            AllPlayer = diisi dengan player 1 sampai 7
            PrizePool = diisi dengan default
            Round = diisi dengan ronde satu
            CardTable = instantiasi TableCard dengan jumlah 0
        */
        GameStateCapsa();
        GameStateCapsa(string filename);

    // Get Method
        int getRound();
        PlayerCapsa& getPlayer(int ID); // setiap player ada id 1-7 yang terpisah dari urutannya.
        pair<int,PlayerCapsa&> getWhoseTurn(); // return giliran siapa skrg
        vector<PlayerCapsa>& getAllPlayer();
    
    // Method
        /*
            round + 1
            Tambah card diatas table
            urutan pemain diubah

        */
        void NextRound();
        /*
            Turn diganti sesuai urutan di vector
        */
        void NextTurn();

        void evaluateAction();

        void printState();

        void inputAction();

        void resetGameState(); // reset game state kecuali point player
        
        bool checkAllWin();

        PlayerCapsa getAllWinner();

        void operator=(const GameStateCapsa& copy);

        void printInterface();

        void printLeaderboard();
        
        void setPlayerName(int ID, string name);

        void updateTurn();
};