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

pair<int, Player &> emptyPlayer(0, temp); // inisiasi pair kosong buat turn

GameState::GameState()
    : Turn(emptyPlayer)
{
    PrizePool = DEFAULT_PRIZE;
    Round = 1;

    for (int i = 0; i < 7; i++)
    { // ngisi kartu player
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

    for (int i = 0; i < 7; i++)
    { // ngisi kartu player
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

long int GameState::getPrize()
{
    return PrizePool;
}

int GameState::getRound()
{
    return Round;
}

TableCard GameState::getTableCard()
{
    return CardTable;
}


Player& GameState::getPlayer(int ID) {
    Player *temp = &AllPlayer.at(0);

    for (Player& player : AllPlayer){
        if (ID == player.getPlayerID()){
            temp = &player;
        }
    }
    return *temp;
}

pair<int, Player&> GameState::getWhoseTurn()
{
    return Turn;
}

void GameState::setPrize(long int amount)
{
    PrizePool = amount;
}

void GameState::NextRound()
{
    Round++;

    // add satu card ke table card
    AddCardToTable(deck.takeCard());
    Player temp(tempCard, tempCard);
    temp = AllPlayer.front();

    // set turn ke pemain setelah pemain giliran pertama di round sebelumnya.
    Turn.first = (Turn.first + 1) % 7;
    Turn.second = AllPlayer.at(Turn.first);
}

void GameState::NextTurn()
{
    // nandain player udah main
    // dan majuin/mundurin pointer turn
    Turn.second.setPlayed(true);

    while (Turn.second.getPlayed())
    {
        if (!Reverse)
        {
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
        else
        {
            if (Turn.first == 0)
            {
                Turn.first = 6;
                Turn.second = AllPlayer.at(Turn.first);
            }
            else
            {
                Turn.first--;
                Turn.second = AllPlayer.at(Turn.first);
            }
        }
    }
}

void GameState::AddCardToTable(Card cardAdded)
{
    CardTable = CardTable + cardAdded;
}

void GameState::printState()
{
    cout << "Round       : " << Round << endl;
    cout << "Prize Pool  : " << PrizePool << endl;
    cout << "Turn        : " << Turn.second.getPlayerID() << " " << Turn.second.getPlayerName() << endl;
    cout << "Table Card  : " << endl;
    CardTable.printCard();
}

void GameState::inputAction()
{

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

    while (true)
    {
        try
        {
            command.takeStrInput();
            if (command.getStrInput() == "DOUBLE" || command.getStrInput() == "NEXT" || command.getStrInput() == "HALF" || command.getStrInput() == "REROLL" || command.getStrInput() == "QUADRUPLE" || command.getStrInput() == "QUARTER" || command.getStrInput() == "REVERSE" || command.getStrInput() == "SWAP" || command.getStrInput() == "SWITCH" || command.getStrInput() == "ABILITYLESS")
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

void GameState::inputRandom()
{

    // vector<string> com = {
    //     "DOUBLE", "NEXT", "HALF", "REROLL", "QUADRUPLE"
    //     , "QUARTER", "REVERSE", "SWAP", "SWITCH", "ABILITYLESS"
    // };

    vector<string> com = {"NEXT", "DOUBLE", "HALF"};

    srand(time(0));
    int choice = rand() % com.size();

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

void GameState::evaluateAction()
{

    while (true)
    {
        try
        {
            if (Action == "DOUBLE")
            {
                PrizePool = PrizePool * 2;
                break;
            }
            else if (Action == "HALF")
            {
                if (!(PrizePool / 2 < 1))
                {
                    PrizePool = PrizePool / 2;
                }
                break;
            }

            // ABILITY
            else if (Action == "REROLL")
            {
                Reroll reroll;
                if (Turn.second.getAbility()->getAbilityCard() == reroll.getAbilityCard())
                {
                    reroll.useAbilityCard(this->deck, Turn.second);
                    Turn.second.setAbility(&reroll);

                    break;
                }
                else
                {
                    throw "You don't have this ability! or\nmaybe someone has dispell tour ability :(";
                }
            }
            else if (Action == "QUADRUPLE")
            {
                Quadruple quadruple;
                if (Turn.second.getAbility()->getAbilityCard() == quadruple.getAbilityCard())
                {
                    quadruple.useAbilityCard(this->PrizePool);
                    Turn.second.setAbility(&quadruple);

                    break;
                }
                else
                {
                    throw "You don't have this ability! or\nmaybe someone has dispell tour ability :(";
                }
            }
            else if (Action == "QUARTER")
            {
                Quarter Quarter;
                if (Turn.second.getAbility()->getAbilityCard() == Quarter.getAbilityCard())
                {
                    Quarter.useAbilityCard(this->PrizePool);
                    Turn.second.setAbility(&Quarter);

                    break;
                }
                else
                {
                    throw "You don't have this ability! or\nmaybe someone has dispell tour ability :(";
                }
            }
            else if (Action == "REVERSE")
            {
                ReverseDirection ReverseDirection;
                if (Turn.second.getAbility()->getAbilityCard() == ReverseDirection.getAbilityCard())
                {
                    ReverseDirection.useAbilityCard(this->Reverse);
                    Turn.second.setAbility(&ReverseDirection);

                    break;
                }
                else
                {
                    throw "You don't have this ability! or\nmaybe someone has dispell tour ability :(";
                }
            }
            else if (Action == "SWAP")
            {
                SwapCard SwapCard;
                if (Turn.second.getAbility()->getAbilityCard() == SwapCard.getAbilityCard())
                {
                    vector<Player> PlayerList;
                    remove_copy_if(this->AllPlayer.begin(), this->AllPlayer.end(), back_inserter(PlayerList),
                                   [this](Player p)
                                   { return p.getPlayerID() == this->Turn.second.getPlayerID(); });

                    cout << Turn.second.getPlayerName() << " used Swap Card ability!" << endl;
                    cout << "Choose the player you want to swap card with : " << endl;

                    int i = 0;
                    for (auto player : PlayerList)
                    {
                        i++;
                        cout << i << ". " << player.getPlayerName() << endl;
                    }

                    InputApp inputApp;
                    Player player1;

                    inputApp.takeIntInput(i);
                    player1 = PlayerList[inputApp.getIntInput() - 1];
                    PlayerList.erase(PlayerList.begin() + inputApp.getIntInput() - 1);
                    break;

                    cout << "Choose other player you want to swap card with : " << endl;

                    i = 0;
                    for (auto player : PlayerList)
                    {
                        i++;
                        cout << i << ". " << player.getPlayerName() << endl;
                    }

                    Player player2;

                    inputApp.takeIntInput(i);
                    player2 = PlayerList[inputApp.getIntInput() - 1];
                    PlayerList.erase(PlayerList.begin() + inputApp.getIntInput() - 1);

                    bool isKiri1;
                    bool isKiri2;

                    cout << "Choose left or right card for " << player1.getPlayerName() << " : " << endl;
                    cout << "1. Left" << endl
                         << "2. Right" << endl;

                    inputApp.takeIntInput(2);
                    isKiri1 = isKiri1 == 1 ? true : false;

                    cout << "Choose left or right card for " << player2.getPlayerName() << " : " << endl;
                    cout << "1. Left" << endl
                         << "2. Right" << endl;

                    inputApp.takeIntInput(2);
                    isKiri2 = isKiri2 == 1 ? true : false;

                    SwapCard.useAbilityCard(player1, isKiri1, player2, isKiri2);
                    Turn.second.setAbility(&SwapCard);

                    break;
                }
                else
                {
                    throw "You don't have this ability! or\nmaybe someone has dispell tour ability :(";
                }
            }
            else if (Action == "SWITCH")
            {
                Switch Switch;
                if (Turn.second.getAbility()->getAbilityCard() == Switch.getAbilityCard())
                {
                    vector<Player> PlayerList;
                    remove_copy_if(this->AllPlayer.begin(), this->AllPlayer.end(), back_inserter(PlayerList),
                                   [this](Player p)
                                   { return p.getPlayerID() == this->Turn.second.getPlayerID(); });

                    cout << Turn.second.getPlayerName() << " used Switch ability!" << endl;
                    cout << "Your card now :" << endl;
                    Turn.second.getCardOne().print();
                    Turn.second.getCardTwo().print();

                    cout << "Choose the player you want to switch card with : " << endl;
                    int i = 0;
                    for (auto player : PlayerList)
                    {
                        i++;
                        cout << i << ". " << player.getPlayerName() << endl;
                    }

                    InputApp inputApp;
                    Player playerOther;

                    inputApp.takeIntInput(i);
                    playerOther = PlayerList[inputApp.getIntInput() - 1];

                    auto itr = find(AllPlayer.begin(), AllPlayer.end(), playerOther);
                    int idx = distance(AllPlayer.begin(), itr);

                    Switch.useAbilityCard(Turn.second, AllPlayer[idx]);
                    Turn.second.setAbility(&Switch);

                    cout << "Your card now :" << endl;
                    Turn.second.getCardOne().print();
                    Turn.second.getCardTwo().print();

                    break;
                }
                else
                {
                    throw "You don't have this ability! or\nmaybe someone has dispell tour ability :(";
                }
            }
            else if (Action == "ABILITYLESS")
            {
                Abilityless abilityLess;
                if (Turn.second.getAbility()->getAbilityCard() == abilityLess.getAbilityCard())
                {
                    vector<Player> PlayerList;
                    remove_copy_if(this->AllPlayer.begin(), this->AllPlayer.end(), back_inserter(PlayerList),
                                   [this](Player p)
                                   { return p.getPlayerID() == this->Turn.second.getPlayerID(); });

                    if (find_if(PlayerList.begin(), PlayerList.end(), [](Player &p)
                                { return p.getAbility()->getAbilityCard() != p.getAbility()->getAbilityCardOff(); }) != PlayerList.end())
                    {
                        // Case 4
                        cout << "Poor you, All Player has used Ability, you displell your own Ability Card" << endl;
                    }
                    else
                    {
                        cout << Turn.second.getPlayerName() << " will dispell other player ability!" << endl;
                        cout << "Choose the player you want to dispell ability with : " << endl;
                        int i = 0;
                        for (auto player : PlayerList)
                        {
                            i++;
                            cout << i << ". " << player.getPlayerName() << endl;
                        }

                        InputApp inputApp;
                        Player playerOther;

                        inputApp.takeIntInput(i);
                        playerOther = PlayerList[inputApp.getIntInput() - 1];

                        auto itr = find(AllPlayer.begin(), AllPlayer.end(), playerOther);
                        int idx = distance(AllPlayer.begin(), itr);

                        if (AllPlayer[idx].getAbility()->getAbilityCard() == AllPlayer[idx].getAbility()->getAbilityCardOff())
                        {
                            // Case 2
                            cout << "This player " << AllPlayer[idx].getPlayerName() << " has used Ability Card, You used the Abilityless card in vain :( !" << endl;
                        }
                        else
                        {
                            // Case 1
                            abilityLess.useAbilityCard(AllPlayer[idx]);
                            Turn.second.setAbility(&abilityLess);
                        }
                    }

                    break;
                }
                else
                {
                    // Case Tidak punya kemampuan
                    throw "You don't have this ability! or\nmaybe someone has dispell tour ability :(";
                }
            }
            else
            {
                break;
            } // ACTION : NEXT
        }
        catch (const char *msg)
        {
            cout << msg << endl;
        }
    }
}

void GameState::resetGameState()
{
    Round = 1;
    PrizePool = DEFAULT_PRIZE;
    DeckCard decknew;
    deck = decknew;

    for (auto kartu : CardTable.getTableCard())
    { // kosongin table card
        CardTable = CardTable - kartu;
    }

    for (auto player : AllPlayer)
    { // set played false dan ganti kartu tiap pemain
        player.setPlayed(false);

        player.setCardOne(deck.takeCard());
        player.setCardTwo(deck.takeCard());
    }
}

bool GameState::checkAllWin()
{
    // cout << "Evaluating all score...\n";
    // for (auto player: AllPlayer){
    //     player.status();
    // }
    Player highestScorePlayer = max(AllPlayer);
    // highestScorePlayer.status();
    // 4294967296
    return (highestScorePlayer.getPlayerPoint() >= 4294967296);
}

// Precondional: Telah ditemukan pemenang pada game
Player GameState::getAllWinner()
{
    return max(AllPlayer);
}

void GameState::operator=(const GameState &copy)
{
    AllPlayer = copy.AllPlayer;
    PrizePool = copy.PrizePool;
    Round = copy.Round;
    Turn = copy.Turn;
    CardTable = copy.CardTable;
    deck = copy.deck;
    Action = copy.Action;
    Reverse = copy.Reverse;
}

void GameState::printInterface()
{

    cout << " _____________________________________________________________________\n";
    cout << "                                                                      \n";
    cout << "                            ROUND " << Round << endl;
    cout << "      PRIZE POOL : " << PrizePool << endl;
    cout << "      WHOSE TURN : (" << Turn.first << ") " << Turn.second.getPlayerName() << endl;
    cout << endl;
    cout << "                        CARD ON TABLE :\n";
    CardTable.printCard();
}

Combo GameState::playerHighestCombo(Player &player)
{

    vector<Card> cardList;                 // kumpulan kartu yang bisa digunakan untuk menemukan kombinasi
    vector<Card> possibleCombination;      // kombinasi kartu yang mungkin
    vector<Combo> listPossibleCombination; // list semua kombinasi kartu yang mungkin

    // Filling the cardList
    cardList.push_back(player.getCardOne());
    cardList.push_back(player.getCardTwo());
    if (CardTable.getTableCardCount() > 0)
    {
        for (auto card : CardTable.getTableCard())
        {
            cardList.push_back(card);
        }
    }
    //cout << "in\n";

    // Pencarian semua kombinasi yang mungkin
    if (cardList.size() > 5)
    { // Jika ada lebih dari satu kombinasi yang mungkin
        for (int i = 0; i < (cardList.size() - 4); i++)
        {
            for (int j = i + 1; j < (cardList.size() - 3); j++)
            {
                for (int k = j + 1; k < (cardList.size() - 2); k++)
                {
                    for (int l = k + 1; l < (cardList.size() - 1); l++)
                    {
                        for (int m = l + 1; m < cardList.size(); m++)
                        {
                            possibleCombination = {cardList[i], cardList[j], cardList[k], cardList[l], cardList[m]};
                            Combo possibleCombo(cardList);
                            float tempVal = possibleCombo.value(); // Supaya evaluasi tipeya
                            listPossibleCombination.push_back(possibleCombination);
                        }
                    }
                }
            }
        }
    }
    else
    { // Jika hanya ada satu kombinasi yang mungkin
        Combo possibleCombo(cardList);
        float tempVal = possibleCombo.value(); // Supaya evaluasi tipeya
        listPossibleCombination.push_back(possibleCombo);
    }
    return max<Combo>(listPossibleCombination);
}

// Temporary
void GameState::getGameWinner(){

    Player *winner = &AllPlayer[0];
    float highestComboWinner =  playerHighestCombo(*winner).value();

    for(auto& player : AllPlayer){
        
        float highestComboPlayer = playerHighestCombo(player).value();
        if( highestComboPlayer> highestComboWinner){
            winner = &player;
            highestComboWinner = highestComboPlayer; 
        }
    }

    cout << "This Round Winner is: " << endl;
    winner->addPoint(PrizePool);  
    winner->status();  
}

void GameState::setReverse(const bool &reverse)
{
    this->Reverse = reverse;
}

bool GameState::getReverse() const
{
    return this->Reverse;
}

void GameState::printLeaderboard()
{

    vector<Player> copyPlayers = sortDsc(AllPlayer);
    int i = 0;

    cout << "\nGAMBLING HALL OF FAME" << endl;
    cout << "No.  Name\t (point)" << endl;
    for (auto player : copyPlayers){
        i++;
        cout << i << ".   " << player.getPlayerName() << "\t (" << player.getPlayerPoint() << ")\n";
    }
}

void GameState::HandUpdate()
{
    for (auto &player : AllPlayer)
    {
        Combo fff = playerHighestCombo(player);
        player.setCombo(fff);
    }
}

void GameState::setPlayerName(int ID, string name)
{
    for (auto &player : AllPlayer)
    {
        if (player.getPlayerID() == ID)
        {
            player.setPlayerName(name);
        }
    }
}


vector<Player>& GameState::getAllPlayer(){
    return AllPlayer;
}

void GameState::updateTurn(){
    Turn.second = AllPlayer.at(Turn.first);
}