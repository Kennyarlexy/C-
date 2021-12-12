#include <iostream>
#include <string>
using namespace std;

int countSegment(string str)
{
    int count = 1;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '.') {
            count++;
        }
    }

    return count;
}

string parseSegment(string &str)
{
    int i = 0;
    while (str[i] != '.' && str[i] != '~')
    {
        i++;
    }
    string segment = str.substr(0, i);
    str.erase(str.begin(), str.begin() + i + 1);

    return segment;
}


int main()
{  
    string str = "tag1.tag2.tag3~name";
    string test = "lkjfhatkljtaglskjfalksjf";
    string segment = parseSegment(str);
    if (test.find(segment) != string::npos) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }



    return 0;
}