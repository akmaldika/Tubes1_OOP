#include "../header/PlayerCard.hpp"
#include "../header/TableCard.hpp"
#include "../header/DeckCard.hpp"
#include "../header/DeckAbilityCard.hpp"

int main() {
    // Card
    Card kartu1(1,"merah");
    Card kartu2(2,"kuning");
    Card kartu3(3,"hijau");
    Card kartu4(4,"biru");
    Card kartu5(5,"hello");
    Card kartu6(6,"world");

    /*
        CONSTRUCTOR
    */
    // DeckCard
    DeckCard deckCard;
    DeckCard deckCardFile("../../../test/deckCard.txt");

    // DeckAbilityCard
    DeckAbilityCard deckAbilityCard;
    DeckAbilityCard deckAbilityCardFile("../../../test/deckAbilityCard.txt");

    // PlayerCard
    PlayerCard playerCard(deckCard.takeCard(), deckCard.takeCard(), deckAbilityCard.takeCard(), 1);

    // TableCard
    vector<Card> table;
    table.push_back(deckCard.takeCard());
    table.push_back(deckCard.takeCard());
    TableCard tableCard(table);

    /*
        COPY CONSTRUCTOR
    */
    // PlayerCard
    PlayerCard playerCardCopy(playerCard);

    // TableCard
    TableCard tableCardCopy(tableCard);

    // DeckCard
    DeckCard deckCardCopy(deckCard);

    // DeckAbilityCard
    DeckAbilityCard deckAbilityCardCopy(deckAbilityCard);

    /*
        SETTER AND GETTER
    */
   // PlayerCard
    playerCard.printCard();
    playerCard.setFirstPlayerCard(kartu3);
    playerCard.setSecondPlayerCard(kartu4);
    playerCard.setAbilityCard(deckAbilityCard.takeCard());
    playerCard.setID(2);
    playerCard.printCard();

    cout << playerCard.getFirstPlayerCard().getColor() << endl;
    cout << playerCard.getSecondPlayerCard().getColor() << endl;
    cout << playerCard.getAbilityCard()->getAbilityCard() << endl;
    cout << playerCard.getPlayerCardCount() << endl << endl;

    // TableCard
    tableCard.printCard();
    vector<Card> testTableCard;
    testTableCard.push_back(kartu5);
    testTableCard.push_back(kartu6);
    tableCard.setTableCard(testTableCard);
    tableCard.printCard();

    cout << tableCard.getTableCard()[0].getColor() << endl;
    cout << tableCard.getTableCardCount() << endl << endl;

    // DeckCard
    deckCard.printCard();
    deckCardFile.printCard();
    vector<Card> testDeckCard;
    testDeckCard.push_back(kartu5);
    testDeckCard.push_back(kartu6);
    deckCard.setDeckCard(testDeckCard);
    deckCard.printCard();

    cout << deckCard.getDeckCard()[0].getColor() << endl;
    cout << deckCard.getDeckCardCount() << endl << endl;

    // DeckAbilityCard
    deckAbilityCard.printCard();
    deckAbilityCardFile.printCard();
    vector<AbilityCard*> testDeckAbilityCard;
    deckAbilityCard.setDeckAbilityCard(deckAbilityCardFile.getDeckAbilityCard());
    deckAbilityCard.printCard();

    cout << deckAbilityCard.getDeckAbilityCard()[0]->getAbilityCard() << endl;
    cout << deckAbilityCard.getDeckAbilityCardCount() << endl << endl;

    /*
        OPERATOR OVERLOADING
    */
    // PlayerCard
    playerCard = playerCard - kartu4;
    playerCard = playerCard + kartu3;

    // TableCard
    tableCard = tableCard + kartu3;
    tableCard = tableCard - kartu5;

    // DeckCard
    deckCard = deckCard + kartu3;
    deckCard = deckCard - kartu5;

    // DeckAbilityCard
    deckAbilityCard = deckAbilityCard + new Quarter();
    deckAbilityCard = deckAbilityCard - deckAbilityCard.getDeckAbilityCard()[0];

    /*
        PRINT CARD
    */
    // PlayerCard
    playerCard.printCard();

    // TableCard
    tableCard.printCard();

    // DeckCard
    deckCard.printCard();

    // DeckAbilityCard
    deckAbilityCard.printCard();

    return 0;
}