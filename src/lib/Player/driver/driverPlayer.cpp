#include "../header/Player.hpp"
using namespace std;

int main(){
    Card card1(1,"merah");
    Card card2(2,"kuning");
    Card card3(3,"hijau");
    Card card4(4,"biru");
    Card ability1("test ability 1");
    Card ability2("test ability 2");

    string name;
    cout << "Masukkan nama pemain : ";
    cin >> name;
    cout << endl;

    // CONSTRUKTOR

    // player
    Player player(card1,card2, ability1);

    // Deckcard
    DeckCard deckCard;

    // PlayerCard
    PlayerCard playerCard(deckCard.takeCard(), deckCard.takeCard(), ability1, 3);

    // getter and setter
    player.setPlayerName(name);
    player.setPlayerPoint(100);
    player.setPlayerID(3);

    player.status();

    // PlayerCard
    playerCard.setFirstPlayerCard(card3);
    playerCard.setSecondPlayerCard(card4);
    playerCard.setAbilityCard(ability2);
    // playerCard.setID(2);
    playerCard.printCard();
}