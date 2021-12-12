#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vect1 = {1, 2, 3, 4, 5};
    vector<int> vect2 = vect1;
    vector<int>::iterator itr;


    vect1.insert(vect1.begin() + 2, 100);
    for (itr = vect1.begin(); itr != vect1.end(); itr++)
    {
        cout << *itr << " ";
    }

    for (itr = vect2.begin(); itr != vect2.end(); itr++)
    {
        cout << *itr << " ";
    }
    return 0;
}