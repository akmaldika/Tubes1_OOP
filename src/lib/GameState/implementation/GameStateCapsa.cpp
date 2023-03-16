#include "../header/GameStateCapsa.hpp"

/*
    Ini ada beberapa yang agak diragukan.
    1. getPlayer apakah sudah aman soalnya pake & ?  takutnya error di playernya malah jadi ketimpa. but i'm not sure
    2. next turn bisa dioptimize soalnya ada redundancy. Reverse ama yg ga reverse kenapa sama aja (?)
    3. generic function highest value bakalan dihapus karena udah ada max dunction di utility function, pake ini aja ntar
*/

/*
    bagian ini aku gatau bisa apa ga
*/
CapsaCard tempCard;
PlayerCapsa temp;

pair<int, PlayerCapsa &> emptyPlayer(0, temp); // inisiasi pair kosong buat turn

GameStateCapsa::GameStateCapsa()
    : Turn(emptyPlayer)
{
    Round = 1;
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


    for (int i = 0; i < 4; i++)
    { // ngisi kartu player
        vector<CapsaCard> cardsAllocation;
        //Ambil kartu untuk player
        for (int j=0; j<13; j++ ){
            cardsAllocation.push_back(deckCapsa.back());
            deckCapsa.pop_back();
        }
        PlayerCapsa tempPlayerCapsa(i+1,"Player "+to_string(i+1), cardsAllocation);
        AllPlayer.push_back(tempPlayerCapsa); // masukin player ke dalem array
    }

    Turn.first = 0;
    Turn.second = AllPlayer.at(0);
    Action = "";
}

GameStateCapsa::GameStateCapsa(string filename)
    : Turn(emptyPlayer)
{
    Round = 1;
    vector<CapsaCard> deckCapsa;
    bool inputDone = false;
    // Read from file
    ifstream file;
    file.open(filename);
    while (!inputDone){
        try{
            if (file.is_open()) {
                string line;
                vector<CapsaCard> deckCapsa;
                string interface;
                string color;
                while (file >> interface >> color) {
                    deckCapsa.push_back(CapsaCard(interface, color));
                }
                inputDone = true;
            }
            else {
                throw FileNotFoundException(filename);
            }
        } catch(FileNotFoundException& err){
            cout<<err.what()<<endl;
        }
    }

    for (int i = 0; i < 4; i++)
    { // ngisi kartu player
        vector<CapsaCard> cardsAllocation;
        //Ambil kartu untuk player
        for (int j=0; j<13; j++ ){
            cardsAllocation.push_back(deckCapsa.back());
            deckCapsa.pop_back();
        }
        PlayerCapsa tempPlayerCapsa(i+1,"Player "+to_string(i+1), cardsAllocation);
        AllPlayer.push_back(tempPlayerCapsa); // masukin player ke dalem array
    }

    Turn.first = 0;
    Turn.second = AllPlayer.at(0);

    Action = "";
}

int GameStateCapsa::getRound(){
    return this->Round;
}

PlayerCapsa& GameStateCapsa::getPlayer(int ID) {
    PlayerCapsa *temp = &AllPlayer.at(0);

    for (PlayerCapsa& player : AllPlayer){
        if (ID == player.getPlayerID()){
            temp = &player;
        }
    }
    return *temp;
}



pair<int, PlayerCapsa&> GameStateCapsa::getWhoseTurn()
{
    return Turn;
}

void GameStateCapsa::NextRound()
{
    Round++;

    // set turn ke pemain setelah pemain giliran pertama di round sebelumnya.
    
    // Reset GameState
    resetGameState();
    Turn.first = (Turn.first + 1) % 4;
    Turn.second = AllPlayer.at(Turn.first);

    for (int i=0; i<4; i++){
        AllPlayer[i].addPoint(AllPlayer[i].getNumWin()*bid);
    }
}

void GameStateCapsa::NextTurn()
{
    // dan majuin/mundurin pointer turn
    if (Turn.first == 6)
    {
        Turn.first = 0;
        Turn.second = AllPlayer.at(Turn.first);
    }
    else
    {
        Turn.first++;
        Turn.second = AllPlayer.at(Turn.first);
    }
        
}

void GameStateCapsa::printState()
{
    cout << "Round       : " << Round << endl;
    cout << "Bid  : " << this->bid << endl;
    cout << "Turn        : " << Turn.second.getPlayerID() << " " << Turn.second.getPlayerName() << endl;
    cout << "Table Card  : " << endl;
}

void GameStateCapsa::inputAction()
{

    InputApp command;

    cout << "\n                 -----> YOUR TURN <-----" << endl;

    cout << " ____________________________\n";
    cout << "|      LIST OF COMMAND       |" << endl;
    cout << "|____________________________|" << endl;
    cout << "| SHOWCARD   |    SHOWSTATUS |" << endl;
    cout << "| NEXT       |               |" << endl;
    cout << "|____________|_______________|" << endl;
    cout << " What do you want to do? ";

    while (true)
    {
        try
        {
            command.takeStrInput();
            if (command.getStrInput() == "SHOWCARD" || command.getStrInput() == "SHOWCARD")
            {
                break;
            }
            else
            {
                throw InvalidCommandException(command.getStrInput()); // nanti diganti
            }
        }

        catch (InvalidCommandException &er)
        {
            cout << er.what() << endl;
        }
    }

    Action = command.getStrInput();
}

void GameStateCapsa::evaluateAction()
{

    while (true)
    {
        try
        {
            if (Action == "SHOWCARD")
            {
                Turn.second.status();
                break;
            }
            else if (Action == "SHOWSTATUS")
            {
                Turn.second.getMyCard().printCard();
                break;
            }
            else
            {
                break;
            } // ACTION : NEXT
        }
        catch (const char *msg)
        {
            cout << msg << endl;
            inputAction();
        }
    }

    // Udh action
    // Lakukan adu combo

    // Adu back
    for (int i=0; i < 3; i++){
        if (AllPlayer[Turn.first].getMyCard().getBackCombo()> AllPlayer[(Turn.first+i)%4].getMyCard().getBackCombo()){
            AllPlayer[Turn.first].setNumWin(AllPlayer[Turn.first].getNumWin()+1);
        } else {
            AllPlayer[Turn.first].setNumWin(AllPlayer[Turn.first].getNumWin()-1);
        }
    }



}

void GameStateCapsa::resetGameState()
{
    Round = 1;
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


    for (int i = 0; i < 4; i++)
    { // ngisi kartu player
        vector<CapsaCard> cardsAllocation;
        //Ambil kartu untuk player
        for (int j=0; j<13; j++ ){
            cardsAllocation.push_back(deckCapsa.back());
            deckCapsa.pop_back();
        }
        PlayerCapsaCard newHands(cardsAllocation, i+1);
        AllPlayer[i].setMyCard(newHands);
    }

}

bool GameStateCapsa::checkAllWin()
{
    // cout << "Evaluating all score...\n";
    PlayerCapsa highestScorePlayer = max(AllPlayer);
    // highestScorePlayer.status();
    // 4294967296
    return (highestScorePlayer.getPlayerPoint() >= 10000);
}

// Precondional: Telah ditemukan pemenang pada game
PlayerCapsa GameStateCapsa::getAllWinner()
{
    return max(AllPlayer);
}

void GameStateCapsa::operator=(const GameStateCapsa &copy)
{
    AllPlayer = copy.AllPlayer;
    Round = copy.Round;
    Turn = copy.Turn;
    Action = copy.Action;
}

void GameStateCapsa::printInterface()
{

    cout << " _____________________________________________________________________\n";
    cout << "                                                                      \n";
    cout << "                            ROUND " << Round << endl;
    cout << "      BID : " << bid << endl;
    cout << "      WHOSE TURN : (" << Turn.first << ") " << Turn.second.getPlayerName() << endl;
    cout << endl;
}

void GameStateCapsa::printLeaderboard()
{

    vector<PlayerCapsa> copyPlayers = sortDsc(AllPlayer);
    int i = 0;

    cout << "\nGAMBLING HALL OF FAME" << endl;
    cout << "No.  Name\t (point)" << endl;
    for (auto player : copyPlayers){
        i++;
        cout << i << ".   " << player.getPlayerName() << "\t (" << player.getPlayerPoint() << ")\n";
    }
}

void GameStateCapsa::setPlayerName(int ID, string name)
{
    for (auto &player : AllPlayer)
    {
        if (player.getPlayerID() == ID)
        {
            player.setPlayerName(name);
        }
    }
}

vector<PlayerCapsa>& GameStateCapsa::getAllPlayer(){
    return AllPlayer;
}

void GameStateCapsa::updateTurn(){
    Turn.second = AllPlayer.at(Turn.first);
}