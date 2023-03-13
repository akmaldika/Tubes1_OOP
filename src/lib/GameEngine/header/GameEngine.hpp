// #include "../../GameState/header/GameState.hpp"
// #include "InventoryHolder/header/DeckCard.hpp"
// #include <iostream>

// using namespace std;


// /*
//     KELAS GAME ENGINE
//     menjalankan game setiap gamenya (satu game = 6 round)
// */
// class GameEngine {

//     private:
//         GameState gameState; // state game saat ini
//         int gameCount; // counter game keberapa saat ini
        

//     public:
//          /*
//             const game engine
//             game state default aja
//             game count = 0
//             instantiasi deck card random

//          */
//          GameEngine();

//          GameEngine(DeckCard inputDeck);

//     // Get Method
//         int getGameCount();
//         GameState getGameState();

//     // Method
        
//         /*
//             Jalankan round pertama
//             tiap player dapet giliran
//             terima input tiap player
//         */
//         void PlayFirstRound();

//         /*
//             Jalankan round setelah round pertama
//             tiap player dapat giliran
//             terima input tiap player
//             ada action tambahan
//         */
//         void PlayOtherRound();

//         /*
//             Jalanin satu game
//             didalam sini ada fungsi playFirstRound & PlayOtherRound

//         */
//         void PlayGame(); // ini mungkin di main aja

//         void calculateWinner();

        

//     // METHOD FOR USER INTERFACE
//         void printGameStatus();
//         void printGameInterface(); // blm implementasi


// };
