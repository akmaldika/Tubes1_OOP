#include "../header/PlayerCapsaCard.hpp"
#include <random>
#include <algorithm>

int main() {
    vector<CapsaCard> deckCapsa;
    vector<string> interfaces {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    vector<string> kinds {"diamond", "club", "heart", "spade"};
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            deckCapsa.push_back(CapsaCard(interfaces[i], kinds[j]));
        }
    }
    //Shuffle
    random_device rd;
    mt19937 g(rd());
    shuffle(deckCapsa.begin(), deckCapsa.end(), g);

    vector<CapsaCard> deckPlayerCapsa;
    for (int i = 0; i < 13; i++) {
        deckCapsa[i].print();
        deckPlayerCapsa.push_back(deckCapsa[i]);
    }

    PlayerCapsaCard playerCapsaCard(deckPlayerCapsa, 0);
    playerCapsaCard.printCard();

    return 0;
}