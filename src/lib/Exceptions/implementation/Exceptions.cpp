#include "../header/Exceptions.hpp"
Exceptions::Exceptions(string msg){
    this->msg = msg;
}
string Exceptions::what(){
    return this->msg;
}

FileNotFoundException::FileNotFoundException(string fileName): 
Exceptions("File "+ fileName +" is not found"){}

IntInputOutOfRangeException::IntInputOutOfRangeException(int range):
Exceptions("Input out of range. Input must be a number from 1 to " + to_string(range)){}

IntInputException::IntInputException():
Exceptions("Input is not valid. Input must be a number"){}

InvalidCommandException::InvalidCommandException(string command):
Exceptions(command + " is not a valid command"){}