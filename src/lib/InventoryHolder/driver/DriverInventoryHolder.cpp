#include "../header/PlayerCard.hpp"
#include "../header/TableCard.hpp"
#include "../header/DeckCard.hpp"

int main() {
    // Card
    Card kartu1(1,"Merah");
    Card kartu2(2,"Kuning");
    Card kartu3(3,"Hijau");
    Card kartu4(4,"Biru");
    Card kartu5(5,"hello");
    Card kartu6(6,"world");
    Card kartuAbility1("terbang tapi boong");
    Card kartuAbility2("turu + bangun");

    /*
        CONSTRUCTOR
    */
    // DeckCard
    DeckCard deckCard;
    DeckCard deckCardFile("../../../test/deckCard.txt");

    // PlayerCard
    PlayerCard playerCard(deckCard.takeCard(), deckCard.takeCard(), kartuAbility1, "Ghazi");

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

    /*
        SETTER AND GETTER
    */
   // PlayerCard
    playerCard.printCard();
    playerCard.setFirstPlayerCard(kartu3);
    playerCard.setSecondPlayerCard(kartu4);
    playerCard.setAbilityCard(kartuAbility2);
    playerCard.setOwner("Akmal");
    playerCard.printCard();

    cout << playerCard.getFirstPlayerCard().getColor() << endl;
    cout << playerCard.getSecondPlayerCard().getColor() << endl;
    cout << playerCard.getAbilityCard().getAbility() << endl;
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

    /*
        PRINT CARD
    */
    // PlayerCard
    playerCard.printCard();

    // TableCard
    tableCard.printCard();

    // DeckCard
    deckCard.printCard();

    return 0;
}