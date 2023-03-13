#include "../header/Player.hpp"
using namespace std;

int main(){
    Card card1(1,"merah");
    Card card2(2,"kuning");
    Card card3(3,"hijau");
    Card card4(4,"biru");
    Card ability1("test ability 1");
    Card ability2("test ability 2");

    // construktor
    Player player(card1,card2,ability1);
    PlayerCard playerCard(card1,card2,ability1,3);

    // getter and setter
    player.setPlayerName("Satria");
    player.setPlayerPoint(100);
    player.setPlayerID(3);

    // cout << player.getPlayerName() << endl;
    // cout << player.getPlayerID() << endl;
    // cout << player.getPlayerPoint() << endl;

    player.status();
}