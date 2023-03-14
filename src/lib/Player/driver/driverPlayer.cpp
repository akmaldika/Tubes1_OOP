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

    // Deckcard
    DeckCard deckCard;

    // PlayerCard
    PlayerCard playerCard(deckCard.takeCard(), deckCard.takeCard(), NULL, 3);

    // getter and setter
    player.setPlayerName("Satria");
    player.setPlayerPoint(100);
    player.setPlayerID(3);
    player.addCardOne(card1);
    player.addCardTwo(card2);
    // player.setAbility("terbang");

    player.status();
}