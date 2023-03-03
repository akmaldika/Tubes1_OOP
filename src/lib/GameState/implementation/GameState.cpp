#include "../header/GameState.hpp"


/*
    bagian ini aku gatau bisa apa ga
*/
Player temp;

vector<Card> emptyCards; // inisiasi vector kosong buat table card
                    // karena kan awalnya gaada kartu
pair<int, Player> emptyPlayer(0,temp); // inisiasi pair kosong buat turn

GameState::GameState() 
: CardTable(emptyCards), Turn(emptyPlayer)
{
    PrizePool = DEFAULT_PRIZE;
    Round = 1;

    for (int i = 0; i < 7 ; i++){
        Card card1 = deck.takeCard();
        Card card2 = deck.takeCard();
        Card emptyAbility("gada ability"); // sementara aja sampai kelas ability selesai
        Player tempPlayer(card1, card2, emptyAbility);

        AllPlayer.push_back(tempPlayer); // masukin player ke dalem array
    }

    Turn.first = 0;
    Turn.second = AllPlayer.front();


}

int GameState::getPrize() {
    return PrizePool;
}

int GameState::getRound() {
    return Round;
}

TableCard GameState::getTableCard() {
    return CardTable;
}

// Player GameState::getPlayer(int ID) {
    
// }