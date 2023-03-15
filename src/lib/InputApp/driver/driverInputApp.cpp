#include "../header/InputApp.hpp"

int main()
{
    InputApp inputApp;
    while(true)
    {
        try
        {
            inputApp.takeIntInput(5);
            break;
        }
        catch (const char* e)
        {
            cout << e << endl;
        }
    }
    cout << inputApp.getIntInput() << endl;
    inputApp.takeStrInput();
    cout <<  inputApp.getStrInput() << endl;
    return 0;
}