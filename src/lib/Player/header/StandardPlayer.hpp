#ifndef __STANDARDPLAYER__
#define __STANDARDPLAYER__
#include <iostream>
using namespace std;

class StandardPlayer{
    protected:
    int ID; 
    string name;
    long long int point;  
    
    public:
    // getter and setter
    void setPlayerName(string name);
    string getPlayerName();
    void setPlayerPoint(long long int point);
    long long int getPlayerPoint();
    void setPlayerID(int ID);
    int getPlayerID();
    virtual void status()=0;

    void addPoint(long long int amount);


    // operator
    bool operator>(StandardPlayer& enemy);
    bool operator==(const StandardPlayer& enemy);
    bool operator<(StandardPlayer& enemy);
};

#endif