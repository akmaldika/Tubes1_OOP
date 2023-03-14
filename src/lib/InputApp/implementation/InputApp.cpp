#include "../header/InputApp.hpp"

InputApp::InputApp() : InputApp ("", -1) {}

InputApp::InputApp(string str, int i)
{
    this->strInput = str;
    this->strInput = i;
}

string InputApp::getStrInput() const
{
    return this->strInput;
}

int InputApp::gerIntInput() const
{
    return this->intInput;
}

void InputApp::setStrInput(string str)
{
    this->strInput = str;
}

void InputApp::setIntInput(int i)
{
    this->intInput = i;
}

void InputApp::takeStrInput()
{
    cin >> this->strInput;
}

void InputApp::takeIntInput()
{
    string temp;
    
    cin >> temp;
    try
    {
        this->intInput = stoi(temp);
    }
    catch (const exception& e)
    {
        throw e;
    }
}

void InputApp::takeIntInput(int i)
{
    string temp;
    
    cin >> temp;
    try
    {
        this->intInput = stoi(temp);

        if (this->intInput > i || this->intInput < 1)
        {
            throw "Input out of range";
        }
    }
    catch (const exception& e)
    {
        throw "Input must be a number from 1 to "+ to_string(i);
    }
}