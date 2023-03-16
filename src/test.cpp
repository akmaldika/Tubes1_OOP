#include <iostream>
#include <string>
#include <vector>

class Class1
{
    private:
        /* data */
        int a;
    public:
        Class1(/* args */)
        {
            a = 100;
        }
        int geta()
        {
            return a;
        }
};

class Class2 : public Class1
{
    private:
        /* data */
    public:
        Class2(/* args */) : Class1() {}
        void ubah(int& a)
        {
            a = 200;
        };
};

class Class3
{
    public :
        int b;
        Class2 c;

        Class3(/* args */) : c(), b(6) {}
        void ubahh()
        {
            c.ubah(b);
        };
};

using namespace std;
int main()
{
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }

    return 0;
}