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
Player * temp;

pair<int, Player*> emptyPlayer(0, temp); // inisiasi pair kosong buat turn

GameState::GameState()
    : Turn(emptyPlayer), Pivot(emptyPlayer)
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
    Turn.second = &AllPlayer.at(0);
    Reverse = false;

    Pivot.first = 0;
    Pivot.second = &AllPlayer.at(0);

    Action = "";
}

GameState::GameState(string filename)
    : Turn(emptyPlayer), deck(filename), Pivot(emptyPlayer)
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
    Turn.second = &AllPlayer.at(0);
    Reverse = false;

    Pivot.first = 0;
    Pivot.second = &AllPlayer.at(0);

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

DeckCard GameState::getDeck()
{
    return this->deck;
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

pair<int, Player*> GameState::getWhoseTurn()
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

    for (auto &player : AllPlayer){
        player.setPlayed(false);
    }

    // set turn ke pemain setelah pemain giliran pertama di round sebelumnya.
    Pivot.first = (Pivot.first + 1) % 7;
    Pivot.second = &AllPlayer.at(Pivot.first);
    Turn = Pivot;
}

void GameState::NextTurn()
{
    // nandain player udah main
    // dan majuin/mundurin pointer turn
    Player &temp = *Turn.second;
    temp.setPlayed(true);

    while (Turn.second->getPlayed())
    {
        // cout << Turn.first << endl;
        if (!Reverse)
        {
            if (Turn.first == 6)
            {
                Turn.first = 0;
                Turn.second = &AllPlayer.at(Turn.first);
            }
            else
            {
                Turn.first++;
                Turn.second = &AllPlayer.at(Turn.first);
            }
        }
        else
        {
            if (Turn.first == 0)
            {
                Turn.first = 6;
                Turn.second = &AllPlayer.at(Turn.first);
            }
            else
            {
                Turn.first--;
                Turn.second = &AllPlayer.at(Turn.first);
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
    Player &temp = *Turn.second;
    cout << "Round       : " << Round << endl;
    cout << "Prize Pool  : " << PrizePool << endl;
    cout << "Turn        : " << temp.getPlayerID() << " " << temp.getPlayerName() << endl;
    cout << "Table Card  : " << endl;
    CardTable.printCard();
}

void GameState::inputAction()
{

    InputApp command;
    Player &temp = *Turn.second;

    cout << "\n                 -----> YOUR TURN <-----" << endl;
    temp.status();

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

void GameState::evaluateAction(AbilityCard& offAbility)
{
    Player &temp = *Turn.second;

    while (true)
    {
        try
        {
            if (Action == "DOUBLE")
            {
                //cout << "in\n";
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
                if (temp.getAbility()->getAbilityCard() == reroll.getAbilityCard() && !temp.getAbility()->isAbilityOff())
                {
                    cout << "You throw your card  :" << endl;
                    temp.getMyCard().printCard();

                    reroll.useAbilityCard(this->deck, temp);
                    temp.setAbility(&offAbility);

                    cout << "Your you get 2 new card :" << endl;
                    temp.getMyCard().printCard();
                    break;
                }
                else
                {
                    throw "You don't have this ability! or\nmaybe someone has dispell your ability :(";
                }
            }
            else if (Action == "QUADRUPLE")
            {
                Quadruple quadruple;
                if (temp.getAbility()->getAbilityCard() == quadruple.getAbilityCard() && !temp.getAbility()->isAbilityOff())
                {
                    cout << temp.getPlayerName() << " use QUADRUPLE! prize pool increase" << endl 
                            <<  this->PrizePool << " -> ";
                    
                    quadruple.useAbilityCard(this->PrizePool);
                    temp.setAbility(&offAbility);

                    cout << this->PrizePool << endl;

                    break;
                }
                else
                {
                    throw "You don't have this ability! or\nmaybe someone has dispell your ability :(";
                }
            }
            else if (Action == "QUARTER")
            {
                Quarter Quarter;
                if (temp.getAbility()->getAbilityCard() == Quarter.getAbilityCard() && !temp.getAbility()->isAbilityOff())
                {
                    cout << temp.getPlayerName() << " use QUARTER!";
                    if (this->PrizePool == 1)
                    {
                        cout << " but prize pool was low" << endl
                            << " prize didn't change = ";
                    }
                    else
                    {
                        cout << " prize pool decrease" << endl
                            <<  this->PrizePool << " -> ";
                    }

                    Quarter.useAbilityCard(this->PrizePool);
                    temp.setAbility(&offAbility);

                    cout << this->PrizePool << endl;
                    break;
                }
                else
                {
                    throw "You don't have this ability! or\nmaybe someone has dispell your ability :(";
                }
            }
            else if (Action == "REVERSE")
            {
                ReverseDirection ReverseDirection;
                if (temp.getAbility()->getAbilityCard() == ReverseDirection.getAbilityCard() && !temp.getAbility()->isAbilityOff())
                {
                    vector<int> turnReverse;
                    cout << temp.getPlayerName() << " use REVERSE!" << endl
                        << "Rest turn this round: ";
                    int nextTurn;
                    pair<int, Player*> tempPivot(this->Pivot);
                    tempPivot.first = (tempPivot.first + 1) % AllPlayer.size();
                    if (!this->Reverse)
                    {
                        nextTurn = (this->Turn.first - 1 + AllPlayer.size()) % AllPlayer.size();
                        for (int i = 0; i < this->AllPlayer.size(); i++)
                        {
                            // cout << (nextTurn - i + AllPlayer.size()) % AllPlayer.size() << endl;
                            if (
                                !AllPlayer[(nextTurn - i + AllPlayer.size()) % AllPlayer.size()].getPlayed() &&
                                AllPlayer[(nextTurn - i + AllPlayer.size()) % AllPlayer.size()].getPlayerID() != temp.getPlayerID()
                                )
                            {
                                cout << "P" << AllPlayer[(nextTurn - i + AllPlayer.size()) % AllPlayer.size()].getPlayerID() << " ";
                            }
                        }
                        cout << endl << "Turn next round: ";
                        for (int i = 0; i < this->AllPlayer.size(); i++)
                        {
                            cout << "P" << AllPlayer[(tempPivot.first - i + AllPlayer.size()) % AllPlayer.size()].getPlayerID() << " ";

                        }
                        cout << endl;
                    }
                    else
                    {
                        nextTurn = (this->Turn.first + 1) % AllPlayer.size();
                        for (int i = 0; i < this->AllPlayer.size(); i++)
                        {
                            // cout << (nextTurn - i + AllPlayer.size()) % AllPlayer.size() << endl;
                            if (
                                !AllPlayer[(nextTurn + i) % AllPlayer.size()].getPlayed() &&
                                AllPlayer[(nextTurn + i) % AllPlayer.size()].getPlayerID() != temp.getPlayerID()
                                )
                            {
                                cout << "P" << AllPlayer[(nextTurn + i) % AllPlayer.size()].getPlayerID() << " ";
                            }
                        }
                        cout << endl << "Turn next round: ";
                        for (int i = 0; i < this->AllPlayer.size(); i++)
                        {
                            cout << "P" << AllPlayer[(tempPivot.first + i) % AllPlayer.size()].getPlayerID() << " ";

                        }
                        cout << endl;
                    }

                    ReverseDirection.useAbilityCard(this->Reverse);
                    temp.setAbility(&offAbility);

                    inputAction();                    
                }
                else
                {
                    throw "You don't have this ability! or\nmaybe someone has dispell your ability :(";
                }
            }
            else if (Action == "SWAP")
            {
                SwapCard SwapCard;
                if (temp.getAbility()->getAbilityCard() == SwapCard.getAbilityCard() && !temp.getAbility()->isAbilityOff())
                {
                    vector<Player> PlayerList;
                    Player &temp2 = temp;
                    remove_copy_if(this->AllPlayer.begin(), this->AllPlayer.end(), back_inserter(PlayerList),
                                   [this](Player p)
                                   { Player &temp2 = *this->Turn.second;
                                    return p.getPlayerID() == temp2.getPlayerID(); });

                    cout << temp.getPlayerName() << " used Swap Card ability!" << endl;
                    cout << "Choose the player to swap card : " << endl;

                    InputApp inputApp;

                    int i = 0;
                    for (auto player : PlayerList)
                    {
                        i++;
                        cout << i << ". P" << player.getPlayerID() << " " << player.getPlayerName() << endl;
                    }

                    Player player1;

                    inputApp.takeIntInput(i);
                    player1 = PlayerList[inputApp.getIntInput() - 1];
                    PlayerList.erase(PlayerList.begin() + inputApp.getIntInput() - 1);
                    
                    auto itr = find(AllPlayer.begin(), AllPlayer.end(), player1);
                    int idx1 = distance(AllPlayer.begin(), itr);
                    
                    cout << "Choose other player to swap card with P" << player1.getPlayerID() << ": " << endl;

                    i = 0;
                    for (auto player : PlayerList)
                    {
                        i++;
                        cout << i << ". P" << player.getPlayerID() << " " << player.getPlayerName() << endl;
                    }

                    Player player2;

                    inputApp.takeIntInput(i);
                    player2 = PlayerList[inputApp.getIntInput() - 1];

                    auto itr2 = find(AllPlayer.begin(), AllPlayer.end(), player2);
                    int idx2 = distance(AllPlayer.begin(), itr2);

                    cout << "P" << AllPlayer[idx1].getPlayerID() << " " << AllPlayer[idx1].getPlayerName() << " cards: " << endl;
                    AllPlayer[idx1].getMyCard().printCard();
                    cout << "P" << AllPlayer[idx2].getPlayerID() << " " << AllPlayer[idx2].getPlayerName() << " cards: " << endl;
                    AllPlayer[idx2].getMyCard().printCard();
                    
                    bool isKiri1;
                    bool isKiri2;

                    cout << "Choose left or right card for " << player1.getPlayerName() << " : " << endl;
                    cout << "1. Left" << endl
                         << "2. Right" << endl;

                    inputApp.takeIntInput(2);
                    isKiri1 = inputApp.getIntInput() == 1 ? true : false;

                    cout << "Choose left or right card for " << AllPlayer[idx2].getPlayerName() << " : " << endl;
                    cout << "1. Left" << endl
                         << "2. Right" << endl;

                    inputApp.takeIntInput(2);
                    isKiri2 = inputApp.getIntInput() == 1 ? true : false;

                    SwapCard.useAbilityCard(this->AllPlayer[idx1], isKiri1, this->AllPlayer[idx2], isKiri2, this->AllPlayer[idx2]);
                    temp.setAbility(&offAbility);

                    cout << "P" << AllPlayer[idx1].getPlayerID() << " " << AllPlayer[idx1].getPlayerName() << " cards: " << endl;
                    AllPlayer[idx1].getMyCard().printCard();
                    cout << "P" << AllPlayer[idx2].getPlayerID() << " " << AllPlayer[idx2].getPlayerName() << " cards: " << endl;
                    AllPlayer[idx2].getMyCard().printCard();
                    break;
                }
                else
                {
                    throw "You don't have this ability! or\nmaybe someone has dispell your ability :(";
                }
            }
            else if (Action == "SWITCH")
            {
                Switch Switch;
                if (temp.getAbility()->getAbilityCard() == Switch.getAbilityCard() && !temp.getAbility()->isAbilityOff())
                {
                    vector<Player> PlayerList;
                    remove_copy_if(this->AllPlayer.begin(), this->AllPlayer.end(), back_inserter(PlayerList),
                                   [this](Player p)
                                   { Player &temp2 = *this->Turn.second;
                                    return p.getPlayerID() == temp2.getPlayerID(); });

                    cout << temp.getPlayerName() << " used Switch ability!" << endl;
                    cout << "Your card now :" << endl;
                    temp.getMyCard().printCard();

                    cout << "Choose the player you want to switch card with : " << endl;
                    int i = 0;
                    for (auto player : PlayerList)
                    {
                        i++;
                        cout << i << ". P" << player.getPlayerID() << " " << player.getPlayerName() << endl;

                    }

                    InputApp inputApp;
                    Player playerOther;

                    inputApp.takeIntInput(i);
                    playerOther = PlayerList[inputApp.getIntInput() - 1];
                    auto itr = find(AllPlayer.begin(), AllPlayer.end(), playerOther);
                    int idx = distance(AllPlayer.begin(), itr);

                    Switch.useAbilityCard(temp, AllPlayer[idx], temp);
                    temp.setAbility(&offAbility);

                    cout << "Your take P" << playerOther.getPlayerID() << " " << playerOther.getPlayerName() << "card" << endl
                        << "Your card now :" << endl;
                    temp.getMyCard().printCard();
                    break;
                }
                else
                {
                    throw "You don't have this ability! or\nmaybe someone has dispell your ability :(";
                }
            }
            else if (Action == "ABILITYLESS")
            {
                Abilityless abilityLess;
                if (temp.getAbility()->getAbilityCard() == abilityLess.getAbilityCard() && !temp.getAbility()->isAbilityOff())
                {
                    vector<Player> PlayerList;
                    remove_copy_if(this->AllPlayer.begin(), this->AllPlayer.end(), back_inserter(PlayerList),
                                   [this](Player p)
                                   {Player &temp2 = *this->Turn.second;
                                    return p.getPlayerID() == temp2.getPlayerID(); });

                    if (find_if(PlayerList.begin(), PlayerList.end(), [](Player &p)
                                { return !p.getAbility()->isAbilityOff(); }) == PlayerList.end())
                    {
                        // Case 4
                        cout << "Poor you, All Player has used Ability, you displell your own Ability Card" << endl;
                        temp.setAbility(&offAbility);
                    }
                    else
                    {
                        cout << temp.getPlayerName() << " will dispell other player ability!" << endl;
                        cout << "Choose the player you want to dispell ability with : " << endl;
                        int i = 0;
                        for (auto player : PlayerList)
                        {
                            i++;
                            cout << i << ". P" << player.getPlayerID() << " " << player.getPlayerName() << endl;

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
                            temp.setAbility(&offAbility);
                        }
                        else
                        {
                            // Case 1
                            cout << "You dispell " << AllPlayer[idx].getAbility()->getAbilityCard() << " ability!" << endl;
                            abilityLess.useAbilityCard(AllPlayer[idx]);
                            temp.setAbility(&offAbility);
                        }
                    }

                    break;
                }
                else
                {
                    // Case Tidak punya kemampuan
                    throw "You don't have this ability! or\nmaybe someone has dispell your ability :(";
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
            inputAction();
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
    Player &temp = *Turn.second;

    cout << " _____________________________________________________________________\n";
    cout << "                                                                      \n";
    cout << "                            ROUND " << Round << endl;
    cout << "      PRIZE POOL : " << PrizePool << endl;
    cout << "      WHOSE TURN : (" << Turn.first << ") " << temp.getPlayerName() << endl;
    cout << endl;
    cout << "                        CARD ON TABLE :\n";
    CardTable.printCard();
}

Combo<Card> GameState::playerHighestCombo(Player &player)
{

    vector<Card> cardList;                 // kumpulan kartu yang bisa digunakan untuk menemukan kombinasi
    vector<Card> possibleCombination;      // kombinasi kartu yang mungkin
    vector<Combo<Card>> listPossibleCombination; // list semua kombinasi kartu yang mungkin

    // Filling the cardList
    if (CardTable.getTableCardCount() > 0)
    {
        for (auto card : CardTable.getTableCard())
        {
            cardList.push_back(card);
        }
    }
    cardList.push_back(player.getCardOne());
    cardList.push_back(player.getCardTwo());
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
                            Combo<Card> possibleCombo(cardList);
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
        Combo<Card> possibleCombo(cardList);
        float tempVal = possibleCombo.value(); // Supaya evaluasi tipeya
        listPossibleCombination.push_back(possibleCombo);
    }

    if ((this->Round == 6) && (player.getListFinalCombo().size()==0)){ // Simpan semua possible combination untuk handling tie breaker di akhir game
        vector<Combo<Card>> best = sortDsc<Combo<Card>>(listPossibleCombination); 
        player.setListFinalCombo(best);
    }

    return max<Combo<Card>>(listPossibleCombination);
}

// Temporary
void GameState::getGameWinner(){

    Player *winner = &AllPlayer[0];
    vector<Player> playersTied;
    float highestComboWinner =  playerHighestCombo(*winner).value();
    bool tied = false;
    int numTieBreaker = 0;
    int i =1;
    int n = AllPlayer.size();
    while (i < n){
        auto& player = AllPlayer[i];
        float highestComboPlayer = playerHighestCombo(player).value();
        if( highestComboPlayer> highestComboWinner){
            winner = &player;
            highestComboWinner = highestComboPlayer; 
        } else if (highestComboPlayer == highestComboWinner)
        {
            // Jika terjadi kasus sama
            playersTied.push_back(player);
        }
        i++;
    }

    // Cek apakah highestCombo ada yang sama jika terdapat beberapa combo yang sama
    if (playersTied.size() > 0){
        if(highestComboWinner == playersTied[0].getCombo().value()){
            tied = true;
        }
    }

    // TIE BREAKER
    while (tied && numTieBreaker>0){
        numTieBreaker++;
        tied = false; // default
        winner = &playersTied[0];
        vector<Player> tempTied;
        highestComboWinner =  winner->getListFinalCombo()[numTieBreaker].value();
        i =1;
        n = playersTied.size();
        // Pencarian value yang lebih besar
        while (i < n){
            auto& player = playersTied[i];
            float highestComboPlayer = player.getListFinalCombo()[numTieBreaker].value();
            if( highestComboPlayer> highestComboWinner){
                winner = &player;
                highestComboWinner = highestComboPlayer; 
            } else if (highestComboPlayer == highestComboWinner)
            {
                // Jika terjadi kasus sama
                tempTied.push_back(player);
            }
            
            i++;
        }
        playersTied = tempTied;        
        if (playersTied.size() > 0){
            if(highestComboWinner == playersTied[0].getCombo().value()){
                tied = true;
        }
    }
    }




    cout << "This Game Winner is: " << endl;
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
        Combo<Card> bestCombo = playerHighestCombo(player);
        player.setCombo(bestCombo);
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
    Turn.second = &AllPlayer.at(Turn.first);
}