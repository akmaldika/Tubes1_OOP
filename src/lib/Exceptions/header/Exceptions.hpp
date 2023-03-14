#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP
#include <string>
using namespace std;
class Exceptions{
    protected:
        string msg;
    public:
        Exceptions(string);
        string what();
};

class FileNotFoundException: public Exceptions{
    public:
        FileNotFoundException(string);
};

class IntInputOutOfRangeException: public Exceptions{
    public:
        IntInputOutOfRangeException(int);
};
class IntInputException: public Exceptions{
    public:
        IntInputException();
};

class InvalidCommandException: public Exceptions{
    public:
        InvalidCommandException(string);
};

#endif /* EXCEPTIONS_HPP */
