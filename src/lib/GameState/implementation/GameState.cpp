#include "../header/GameState.hpp"


/*
    bagian ini aku gatau bisa apa ga
*/
Card tempCard;
Player temp(tempCard,tempCard,tempCard);

pair<int, Player> emptyPlayer(0,temp); // inisiasi pair kosong buat turn

GameState::GameState() 
: Turn(emptyPlayer)
{
    PrizePool = DEFAULT_PRIZE;
    Round = 1;

    for (int i = 0; i < 7 ; i++){ // ngisi kartu player
        Card card1 = deck.takeCard();
        Card card2 = deck.takeCard();
        Card emptyAbility("Empty"); // sementara aja sampai kelas ability selesai
        Player tempPlayer(card1, card2, emptyAbility);

        AllPlayer.push_back(tempPlayer); // masukin player ke dalem array

    }

    Turn.first = 0;
    Turn.second = AllPlayer.front();

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
        Card emptyAbility("Empty"); // sementara aja sampai kelas ability selesai
        Player tempPlayer(card1, card2, emptyAbility);

        AllPlayer.push_back(tempPlayer); // masukin player ke dalem array

    }

    Turn.first = 0;
    Turn.second = AllPlayer.front();
    
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

Player GameState::getPlayer(int ID) {
    for (Player player : AllPlayer){
        if(ID == player.getID()){
            return player;
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
    Player temp(tempCard,tempCard,tempCard);
    temp = AllPlayer.front();

    NextTurn();
}

void GameState::NextTurn(bool reverse){
    if(!reverse){
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

void GameState::AddCardToTable(Card cardAdded){
    CardTable = CardTable + cardAdded;
}

void GameState::printState(){
    cout << "Round       :" << Round << endl;
    cout << "Prize Pool  :" << PrizePool << endl;
    cout << "Turn        :" << Turn.second.getID() << " " << Turn.second.getPlayerName() << endl;
    cout << "Table Card  :" << endl;
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
    cout << "Player in turn : " << endl;
    // print informasi player
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

bool GameState::checkForWin(){
    Player highestScore = highestValue(AllPlayer);

    if (highestScore.getPlayerPoint() >= 4294967296){
        return true;
    }
    else{
        return false;
    }

}

Player GameState::getWinner(){

    for (auto player : AllPlayer){
        if(player.getPlayerPoint() >= 4294967296){
            return player;
        }
    }
}





