#include "Ability.hpp"
#include "Player.hpp"


/*
    KELAS GAMESTATE
    State dari game pada setiap roundnya

*/
class GameState {

    private:
        Player *AllPlayer;  // array semua player yang terurut berdasarkan gilirannya
        int PrizePool;  // poin hadiah
        int round; // hitungan ronde

        TableCard cardtable;

    public:


};