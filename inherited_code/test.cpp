#include <iostream>

using namespace std;

class Food
{
    string _name;
    int _test = 10;
public:
    Food() {};
    Food(string name)
    {
        _name = name;
    }
    ~Food()
    {
        cout << _name << " is destructed" << endl;
    }
    string getName()
    {
        return _name;
    }
    int getInt()
    {
        return _test;
    }
};

int main()
{
    Food burger = Food("Burger");
    cout << burger.getName() << endl;
    cout << Food("Pizza").getName() << endl;
    cout << "^After pizza is created lets see if it's destructed" << endl;

    return 0;
}