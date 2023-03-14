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
}

class 


#endif /* EXCEPTIONS_HPP */
