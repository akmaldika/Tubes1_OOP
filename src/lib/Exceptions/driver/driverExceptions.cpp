#include "../header/Exceptions.hpp"
#include <exception>
#include <iostream>

int main(){
    string temp;
    int intInput;
    int range = 3;
    
    cin >> temp;
    try
    {
        intInput = stoi(temp);

        if (intInput > range)
        {
            throw IntInputOutOfRangeException(range);
        }
    }
    catch (IntInputOutOfRangeException& err)
    {
        cout<<err.what()<<endl;
    }     
    catch (IntInputException& err){
        cout<<err.what()<<endl;
    }
    catch(exception& e){
        cout << IntInputException().what()<<endl;
    }

    return 0;
}