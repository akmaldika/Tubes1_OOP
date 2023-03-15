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
    Turn.second = AllPlayer.at(0);
    Reverse = false;

    Action = "";
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
    Turn.second = AllPlayer.at(0);
    Reverse = false;
    
    Action = "";

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

    // set turn ke pemain setelah pemain giliran pertama di round sebelumnya.
    Turn.first = (Turn.first + 2) % 7;
    Turn.second = AllPlayer.at(Turn.first);
}

void GameState::NextTurn(){
// nandain player udah main
// dan majuin/mundurin pointer turn 
    Turn.second.setPlayed(true);

    while(Turn.second.getPlayed()){
        if(!Reverse){
            if(Turn.first == 6){
                Turn.first = 0;
                Turn.second = AllPlayer.at(Turn.first);
            }
            else{
                Turn.first++;
                Turn.second = AllPlayer.at(Turn.first);
            }
        }
        else {
            if(Turn.first == 0){
                Turn.first = 6;
                Turn.second = AllPlayer.at(Turn.first);
            }
            else{
                Turn.first--;
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

    InputApp command;

    cout << "\n                 -----> YOUR TURN <-----" << endl;
    Turn.second.status();

    cout << " ____________________________\n";
    cout << "|      LIST OF COMMAND       |" << endl;
    cout << "|____________________________|" << endl;
    cout << "| DOUBLE     |       QUARTER |" << endl;
    cout << "| NEXT       |       REVERSE |" << endl;
    cout << "| HALF       |          SWAP |" << endl;
    cout << "| REROLL     |        SWITCH |" << endl;
    cout << "| QUADRUPLE  |   ABILITYLESS |" << endl;
    cout << "|____________|_______________|" << endl;
    cout << " What do you want to do? ";

    while (true){
        try{
            command.takeStrInput();
            if(     command.getStrInput() == "DOUBLE"
                ||  command.getStrInput() == "NEXT"
                ||  command.getStrInput() == "HALF"
                ||  command.getStrInput() == "REROLL"
                ||  command.getStrInput() == "QUADRUPLE"
                ||  command.getStrInput() == "QUARTER"
                ||  command.getStrInput() == "REVERSE"
                ||  command.getStrInput() == "SWAP"
                ||  command.getStrInput() == "SWITCH"
                ||  command.getStrInput() == "ABILITYLESS")
            {
                break;
            }
            else{
                throw InvalidCommandException(command.getStrInput()); // nanti diganti
            }
        }

        catch(InvalidCommandException &er){
            cout << er.what() << endl;
        }
    }
    
    Action = command.getStrInput();
}

void GameState::inputRandom(){
    
    // vector<string> com = {
    //     "DOUBLE", "NEXT", "HALF", "REROLL", "QUADRUPLE"
    //     , "QUARTER", "REVERSE", "SWAP", "SWITCH", "ABILITYLESS"
    // };

    vector<string> com = {"NEXT", "HALF", "DOUBLE"};

    srand(time(NULL));
    int choice = rand() % 2;  
    
    Action = com[choice];
    cout << choice << endl;
    cout << "Command : " << Action << endl;
}


// void GameState::inputActionFirstRound(){
    
//     InputApp command;

//     cout << "\n                 -----> YOUR TURN <-----" << endl;
//     Turn.second.status();

//     cout << " ____________________________\n";
//     cout << "|      LIST OF COMMAND       |" << endl;
//     cout << "|____________________________|" << endl;
//     cout << "| DOUBLE     |       QUARTER |" << endl;
//     cout << "| NEXT       |       REVERSE |" << endl;
//     cout << "| HALF       |          SWAP |" << endl;
//     cout << "| REROLL     |        SWITCH |" << endl;
//     cout << "| QUADRUPLE  |   ABILITYLESS |" << endl;
//     cout << "|____________|_______________|" << endl;
//     cout << " What do you want to do? ";

//     while (true){
//         try{
//             command.takeStrInput();
//             if(     command.getStrInput() == "DOUBLE"
//                 ||  command.getStrInput() == "NEXT"
//                 ||  command.getStrInput() == "HALF"
//                 ||  command.getStrInput() == "REROLL"
//                 ||  command.getStrInput() == "QUADRUPLE"
//                 ||  command.getStrInput() == "QUARTER"
//                 ||  command.getStrInput() == "REVERSE"
//                 ||  command.getStrInput() == "SWAP"
//                 ||  command.getStrInput() == "SWITCH"
//                 ||  command.getStrInput() == "ABILITYLESS")
//             {
//                 break;
//             }
//             else{
//                 throw "Insert Exception"; // nanti diganti
//             }
//         }

//         catch(...){
//             cout << "----------   Invalid Input!    ---------- " << endl;
//         }
//     }
    
//     Action = command.getStrInput();
// }

void GameState::evaluateAction(){

    if(Action == "DOUBLE"){
        PrizePool = PrizePool * 2;
    }
    else if(Action == "HALF"){
        if(!(PrizePool / 2 < 1)){
            PrizePool = PrizePool / 2;
        }
    }

    // ABILITY
    else if(Action == "REROLL"){
    }
    else if(Action == "QUADRUPLE"){
    }
    else if(Action == "QUARTER"){
    }
    else if(Action == "REVERSE"){
    }
    else if(Action == "SWAP"){
    }
    else if(Action == "SWITCH"){
    }
    else if(Action == "ABILITYLESS"){
    }

    else{} // ACTION : NEXT
}

void GameState::resetGameState(){
    Round = 1;
    PrizePool = DEFAULT_PRIZE;
    DeckCard decknew;
    deck = decknew;

    for (auto kartu : CardTable.getTableCard()){ // kosongin table card
        CardTable = CardTable - kartu;
    }

    for (auto player : AllPlayer){ // set played false dan ganti kartu tiap pemain
        player.setPlayed(false);

        player.setCardOne(deck.takeCard());
        player.setCardTwo(deck.takeCard());
    }
}

bool GameState::checkAllWin(){

    // cout << "Evaluating all score...\n";

    Player highestScorePlayer = max(AllPlayer);
    // highestScorePlayer.status();
    //4294967296
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

cout << " _____________________________________________________________________\n";
cout << "                                                                      \n";
cout << "                            ROUND " << Round << endl;
cout << "      PRIZE POOL : " << PrizePool << endl;
cout << "      WHOSE TURN : (" << Turn.first << ") " << Turn.second.getPlayerName() << endl;
cout << endl;
cout << "                        CARD ON TABLE :\n";
CardTable.printCard();
}

Combo GameState::playerHighestCombo(Player& player){
    
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
                for (int k=j+1; k<(cardList.size()-2);k++){
                    for(int l=k+1; l<(cardList.size()-1); l++){
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
void GameState::getGameWinner(){
    
    Player& winnerPlayer = AllPlayer[0]; // max(AllPlayer)
    float highestComboWinner =  playerHighestCombo(winnerPlayer).value();

    for(auto player : AllPlayer){
        
        float highestComboPlayer = playerHighestCombo(player).value();
        if( highestComboPlayer> highestComboWinner){
            winnerPlayer = player;
            highestComboWinner = highestComboPlayer; 
        }
    }

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

void GameState::printLeaderboard(){

    vector<Player> copyPlayers = sort(AllPlayer);

    cout << "\nGAMBLING HALL OF FAME" << endl;
    cout << " Name\t (point)" << endl;
    for (auto player : copyPlayers){
        cout << player.getPlayerName() << "\t (" << player.getPlayerPoint() << ")\n";
    }
}

void GameState::HandUpdate(){

    for(auto player : AllPlayer){
    player.setCombo(playerHighestCombo(player));
    }
}