#include "../header/GameState.hpp"


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

int GameState::getPrize() {
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
        if(ID == player.getPlayerID()){
            temp = player;
            return temp;
        }
    }
}

pair<int, Player> GameState::getWhoseTurn(){
    return Turn;
}

void GameState::setPrize(int amount){
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
            
            if(Turn.first >= 6){
                Turn.first = 0;
                Turn.second = AllPlayer.at(0);
            }
            else{
                Turn.first++;
                Turn.second = AllPlayer.at(Turn.first);
            }
        }
        else {
            if(Turn.first >= 6){
                Turn.first = 0;
                Turn.second = AllPlayer.at(0);
            }
            else{
                Turn.first++;
                Turn.second = AllPlayer.at(Turn.first);
            }
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
    cout << "Player in turn : " << endl;
    // print informasi player
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
        
        PrizePool = PrizePool / 2;

        break;
    case 4: // 4. Ability
        

        break;
    default:
        break;
    }
}

template <typename T>
T GameState::highestValue(vector<T> objects){
    T max; // possible bug

    for(auto obj : objects){
        if(obj > max){
            max = obj;
        }
    }

    return max;
}

void GameState::resetGameState(){
    Round = 1;
    PrizePool = DEFAULT_PRIZE;

    // tunggu ability, player, player card selesai.
}

bool GameState::checkAllWin(){
    Player highestScore = highestValue(AllPlayer);

    if (highestScore.getPlayerPoint() >= 4294967296){
        return true;
    }
    else{
        return false;
    }

}

Player GameState::getAllWinner(){

    for (auto player : AllPlayer){
        if(player.getPlayerPoint() >= 4294967296){
            return player;
        }
    }
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
    
    vector<Card> cardList;
    vector<Card> temp;
    Combo maxCombo;

    cardList.push_back(player.getCardOne());
    cardList.push_back(player.getCardTwo());

    if(CardTable.getTableCardCount() > 0){
        for(auto card : CardTable.getTableCard()){
            cardList.push_back(card);
        }
    }

    int range = (1 << cardList.size()) - 1;

    for (int i = 0; i <= range; i++){
        cout << "Masuk loop highest combo" << endl;
        int x = 0, y = i;

        while(y > 0){
            if(y & 1 == 1){
                temp.push_back(cardList.at(x));
            }
            
            x++;
            y = y >> 1;
        }
        cout << "in\n";
        Combo tempCombo(temp); // bug here

        if(tempCombo.value() >= maxCombo.value()){
            maxCombo = tempCombo;

        }
        cout << "out\n";

    }
    cout << "Keluar loop highest combo" << endl;


    return maxCombo;
}

void GameState::getRoundWinner(){
    
    cout << "Masuk round winner\n";
    Player &max = AllPlayer.front();

    for (auto player : AllPlayer){
        cout << "Masuk loop round winner\n";

        if(playerHighestCombo(player).value() >= playerHighestCombo(max).value()){
            max = player;
        }
    }

    cout << "This Round Winner is: " << endl;
    max.addPoint(PrizePool);  
    max.status();  
}