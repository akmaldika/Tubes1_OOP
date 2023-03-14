//#include "Ability.hpp"
#include "../../Player/header/Player.hpp"
#include "../../InventoryHolder/header/TableCard.hpp"
#include "../../InventoryHolder/header/DeckCard.hpp"
#include "../../Cards/header/Combo.hpp"
#include "../../utilityFunction.cpp"
#include <vector>
#include <iostream>

using namespace std;

/*
    KELAS GAMESTATE
    State dari game pada setiap roundnya

*/
class GameState {

    private:
    // ATTRIBUTE
        vector<Player> AllPlayer;  // array semua player yang terurut berdasarkan gilirannya
        int PrizePool;  // poin hadiah
        int Round; // hitungan ronde

        /*  TURN
            giliran player yang mana saat ini.
            pair->first = urutan player/ index dalam vector
            pair->second = objek playernya
        */
        pair<int, Player&> Turn;
        TableCard CardTable; // kartu di meja
        DeckCard deck; // kartu dalam deck

        /*
            aksi player di turn ini
            0. Empty
            1. Double
            2. Next
            3. Half
            4. Ability
        */
        int Action;
        bool Reverse;

        const int DEFAULT_PRIZE = 64;

    public:
    // CONSTRUCTOR
        /*
            Const
            AllPlayer = diisi dengan player 1 sampai 7
            PrizePool = diisi dengan default
            Round = diisi dengan ronde satu
            CardTable = instantiasi TableCard dengan jumlah 0
        */
        GameState();
        GameState(string filename);

    // Get Method
        int getPrize();
        int getRound();
        TableCard getTableCard();
        Player& getPlayer(int ID); // setiap player ada id 1-7 yang terpisah dari urutannya.
        pair<int,Player> getWhoseTurn(); // return giliran siapa skrg

    // Set Method
        void setPrize(int amount);

    
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

        void AddCardToTable(Card cardAdded); // tambah kartu di meja

        void evaluateAction();

        void printState();

        void inputAction();

        void inputActionFirstRound();

        void useAbility(); // blm implementasi

        void resetGameState(); // reset game state kecuali point player
        
        bool checkAllWin();

        Player getAllWinner();

        //bool checkRoundWin();

        void getRoundWinner(); //langsung tambahin skor ke winner round ini

        Combo playerHighestCombo(Player player);

        void operator=(const GameState& copy);

        void printInterface();
};