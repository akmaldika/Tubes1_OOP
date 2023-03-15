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

int InputApp::getIntInput() const
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
    string temp;
    cin >> temp;
    this->strInput = temp;
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

int InputApp::takeIntInput(int i)
{
    string temp;
    
    while (true) {
        cout << "(";
        for (int j = 1; j < i; j++) {
            cout << j << "/";
        }
        cout << i << ") Your Choice : ";
        cin >> temp;
        try
        {
            this->intInput = stoi(temp);

            if (this->intInput > i || this->intInput < 1)
            {
                throw IntInputOutOfRangeException(i);
            }
            break;
        }
        catch (IntInputOutOfRangeException& e)
        {
            cout << LIGHT_RED << endl << e.what() << RESET << endl << endl;
        }
        catch (exception& e){
            cout << LIGHT_RED << endl << IntInputException().what() << RESET << endl << endl;
        }
    }

    return this->intInput;
}

string InputApp::takeFilenameInput(string type)
{
    string filename;

    while(true){
        try{
            cout << "\nInput format (example.txt). Put inside 'test' folder." << endl;
            cout << "Deck " << type << " Filename: ";
            cin >> filename ;

            // check file exist
            ifstream file("../test/" + filename);
            if(!file){
                throw FileNotFoundException(filename);
            }

            break;
        }
        catch (FileNotFoundException& err) {
            cout << endl << LIGHT_RED << err.what() << RESET << endl;
        }
    }

    return filename;
}