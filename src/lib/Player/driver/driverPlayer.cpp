#include "../header/Player.hpp"
using namespace std;

int main(){
    Card card1(1,"merah");
    Card card2(2,"kuning");
    Card card3(3,"hijau");
    Card card4(4,"biru");
    // AbilityCard ability1("test ability 1");
    // Card ability2("test ability 2");


    // CONSTRUKTOR

    // player
    Player player(card1,card2);

    string name;
    cout << "Masukkan nama pemain : ";
    player.setPlayerName(name);
    cout << endl;
    // Deckcard
    DeckCard deckCard;

    // PlayerCard
    PlayerCard playerCard(deckCard.takeCard(), deckCard.takeCard(), NULL, 3);

    // getter and setter
    // player.setPlayerName(name);
    player.setPlayerPoint(100);
    player.setPlayerID(3);
    player.setCardOne(card1);
    player.setCardTwo(card2);
    // player.setAbility("terbang");

    player.status();
}