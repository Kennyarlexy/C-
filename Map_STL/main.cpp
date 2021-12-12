#include <iostream>
#include <map>
using namespace std;


int main() 
{
    int Q; cin >> Q;
    map<string, int> map;

    for (int i = 0; i < Q; i++) {
        int n;
        cin >> n;
        string X;
        cin >> X;
        switch (n)
        {
            case 1:
                int Y; 
                cin >> Y;
                if (map.find(X) != map.end()) {
                    map[X] += Y;
                } else {
                    map.insert(make_pair(X, Y));
                }
                break;
            case 2:
                map.erase(X);
                break;
            case 3:
                cout << map[X] << endl;
                break;
        }
    }

    return 0;
}



