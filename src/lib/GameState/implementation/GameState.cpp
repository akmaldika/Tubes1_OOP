#include "../header/GameState.hpp"


/*
    Ini ada beberapa yang agak diragukan. 
    1. getPlayer apakah sudah aman soalnya pake & ?  takutnya error di playernya malah jadi ketimpa. but i'm not sure 
    2. next turn bisa dioptimize soalnya ada redundancy. Reverse ama yg ga reverse kenapa sama aja (?)
    3. generic function highest value bakalan dihapus karena udah ada max dunction di utility function, pake ini aja ntar
*/

/*
    bagian ini aku gatau bisa apa ga
*/
Card tempCard;
Player temp;

pair<int, Player&> emptyPlayer(0,temp); // inisiasi pair kosong buat turn

GameState::GameState() 
: Turn(emptyPlayer)
{
    PrizePool = DEFAULT_PRIZE;
    Round = 1;

    for (int i = 0; i < 7 ; i++){ // ngisi kartu player
        Card card1 = deck.takeCard();
        Card card2 = deck.takeCard();
        Player tempPlayer(card1, card2);

        AllPlayer.push_back(tempPlayer); // masukin player ke dalem array

    }

    Turn.first = 0;
    Turn.second = AllPlayer.front();
    Reverse = false;

    Action = 0;
}

GameState::GameState(string filename)
: Turn(emptyPlayer), deck(filename)
{

    PrizePool = DEFAULT_PRIZE;
    Round = 1;

    for (int i = 0; i < 7 ; i++){ // ngisi kartu player
        Card card1 = deck.takeCard();
        Card card2 = deck.takeCard();
        Player tempPlayer(card1, card2);

        AllPlayer.push_back(tempPlayer); // masukin player ke dalem array

    }

    Turn.first = 0;
    Turn.second = AllPlayer.front();
    Reverse = false;
    
    Action = 0;

}

long int GameState::getPrize() {
    return PrizePool;
}

int GameState::getRound() {
    return Round;
}

TableCard GameState::getTableCard() {
    return CardTable;
}

Player& GameState::getPlayer(int ID) {
    Player &temp = AllPlayer.front();

    for (Player player : AllPlayer){
        if (ID == player.getPlayerID()){
            temp = player;
        }
    }
    return temp;
}

pair<int, Player> GameState::getWhoseTurn(){
    return Turn;
}

void GameState::setPrize(long int amount){
    PrizePool = amount;
}

void GameState::NextRound(){
    Round++;

    // add satu card ke table card
    AddCardToTable(deck.takeCard());
    Player temp(tempCard,tempCard);
    temp = AllPlayer.front();

    NextTurn();
}

void GameState::NextTurn(){
// nandain player udah main
// dan majuin/mundurin pointer turn 
    Turn.second.setPlayed(true);

    while(Turn.second.getPlayed()){
        if(!Reverse){
            Turn.first = (Turn.first+1)%7;
            Turn.second = AllPlayer.at(Turn.first);
        }
        else {
            Turn.first = ((Turn.first-1)+7)%7;
            Turn.second = AllPlayer.at(Turn.first); 
        }
    }

}

void GameState::AddCardToTable(Card cardAdded){
    CardTable = CardTable + cardAdded;
}

void GameState::printState(){
    cout << "Round       : " << Round << endl;
    cout << "Prize Pool  : " << PrizePool << endl;
    cout << "Turn        : " << Turn.second.getPlayerID() << " " << Turn.second.getPlayerName() << endl;
    cout << "Table Card  : " << endl;
    CardTable.printCard();


}

void GameState::inputAction(){
    cout << "\nPlayer in turn : " << endl;
    Turn.second.status();

    cout << "Action Choice  : " << endl;
    cout << "1. Double " << endl;
    cout << "2. Next " << endl;
    cout << "3. Half " << endl;
    cout << "4. Use Ability" << endl;

    int input;
    while (true){
        try{
            cin >> input;
            if(input > 4 || input < 1){ // blm ada handling buat string
                throw (input);
            }
            else {
                break;
            }
        }

        catch(...){
            cout << "Input Tidak Valid! Silahkan ulangi" << endl;
        }
    }
    
    Action = input;
}

void GameState::inputRandom(){
    cout << "\nPlayer in turn : " << endl;
    Turn.second.status();

    cout << "Action Choice  : random 1,2,3" << endl;
    srand(time(0));
    Action = rand() % (3 - 1 +1) + 1;

    cout << "My Action is: " << Action << endl;
}


void GameState::inputActionFirstRound(){
    cout << "\nPlayer in turn : " << endl;
    Turn.second.status();
    cout << "Action Choice  : " << endl;
    cout << "1. Double " << endl;
    cout << "2. Next " << endl;
    cout << "3. Half " << endl;

    int input;
    while (true){
        try{
            cin >> input;
            if(input > 3 || input < 1){ // blm ada handling buat string
                throw (input);
            }
            else {
                break;
            }
        }

        catch(...){
            cout << "Input Tidak Valid! Silahkan ulangi" << endl;
        }
    }
    
    Action = input;
}

void GameState::evaluateAction(){
    switch (Action)
    {
    case 1: // 1. Double

        PrizePool = PrizePool * 2;
        //cout << "masuk satu";
        
        break;
    case 2: // 2. Next
        // nothing
        break;
    case 3: // 3. Half
        
        if(!(PrizePool / 2 < 1)){
            PrizePool = PrizePool / 2;
        }

        break;
    case 4: // 4. Ability
        
        break;
    default:
        break;
    }
}

void GameState::resetGameState(){
    Round = 1;
    PrizePool = DEFAULT_PRIZE;

    for (int i = 0; i < 5 ; i++){ // kosongin table card
        CardTable = CardTable - CardTable.getTableCard().at(i);
    }

    for (auto player : AllPlayer){ // set played false dan ganti kartu tiap pemain
        player.setPlayed(false);

        player.setCardOne(deck.takeCard());
        player.setCardTwo(deck.takeCard());
    }
}

bool GameState::checkAllWin(){
    Player highestScorePlayer = max(AllPlayer);

    return (highestScorePlayer.getPlayerPoint() >= 4294967296);
}

// Precondional: Telah ditemukan pemenang pada game 
Player GameState::getAllWinner(){
    return max(AllPlayer);
}

void GameState::operator=(const GameState& copy){
    AllPlayer = copy.AllPlayer;
    PrizePool = copy.PrizePool;
    Round = copy.Round;
    Turn = copy.Turn;
    CardTable = copy.CardTable;
    deck = copy.deck;
    Action = copy.Action;
    Reverse = copy.Reverse;

}

void GameState::printInterface(){
    cout << " ________________________________________________________________________________" << endl;
    cout << "|                                                                                |" << endl;
    cout << "|                                                                                |" << endl;
    cout << "|                                                                                |" << endl;
    cout << "|                                                                                |" << endl;
    cout << "|                                                                                |" << endl;
    cout << "|                                                                                |" << endl;
    cout << "|                                                                                |" << endl;
    cout << "|                                                                                |" << endl;


}

Combo GameState::playerHighestCombo(Player player){
    
    vector<Card> cardList; //kumpulan kartu yang bisa digunakan untuk menemukan kombinasi
    vector<Card> possibleCombination;//kombinasi kartu yang mungkin
    vector<Combo> listPossibleCombination;// list semua kombinasi kartu yang mungkin

    // Filling the cardList
    cardList.push_back(player.getCardOne());
    cardList.push_back(player.getCardTwo());
    if(CardTable.getTableCardCount() > 0){
        for(auto card : CardTable.getTableCard()){
            cardList.push_back(card);
        }
    }
    // Pencarian semua kombinasi yang mungkin
    if(cardList.size()>5){ // Jika ada lebih dari satu kombinasi yang mungkin
        for (int i=0; i<(cardList.size()-4);i++){
            for (int j=i+1; j<(cardList.size()-3);j++){
                for (int k=j+1; j<(cardList.size()-2);k++){
                    for(int l=k+1; j<(cardList.size()-1); l++){
                        for(int m=l+1; m<cardList.size();m++){
                            possibleCombination = {cardList[i], cardList[j], cardList[k], cardList[l], cardList[m]};
                            listPossibleCombination.push_back(Combo(possibleCombination));
                        }
                    }
                }
            }
        }
    } else { // Jika hanya ada satu kombinasi yang mungkin
        listPossibleCombination.push_back(Combo(cardList));
    }

    return max(listPossibleCombination);
}


// Temporary
void GameState::getRoundWinner(){
    
    cout << "Masuk round winner\n";
    Player winnerPlayer = max(AllPlayer);

    cout << "This Round Winner is: " << endl;
    winnerPlayer.addPoint(PrizePool);  
    winnerPlayer.status();  
}

void GameState::setReverse(const bool& reverse)
{
    this->Reverse = reverse;
}

bool GameState::getReverse() const
{
    return this->Reverse;
}