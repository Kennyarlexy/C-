#include <iostream>
#include <vector>
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

//will erase str partially
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

void countDepth(int &init_Depth, string str)
{
    if (str[1] != '/') {
        init_Depth++;
    } else {
        init_Depth--;
    }
}

string getValue(string attribute, string tag)
{
    attribute = " " + attribute + " ";
    auto found = tag.find(attribute);
    if (found != string::npos) {
        int index = int(found);
        int start = index + attribute.length() + 3;
        int end = start + 1;
        int i = 0;
        while (true)
        {
            if (tag[end] == '"') {
                break;
            }
            end++;
        }
        int length = end - start;
        string value = tag.substr(start, length);
        
        return value;
    } else {
        return "Not Found!";
    }
}

int main()
{
    int N, Q;
    cin >> N >> Q;
    cin.ignore(100, '\n');

    vector<string> container;
    for (int i = 0; i < N; i++)
    {
        string temp;
        getline(cin, temp);
        container.push_back(temp);
    }

    for (int i = 0; i < Q; i++)
    {
        string search;
        cin >> search;

        string tag;
        int countFound = 0;
        int n_segment = countSegment(search);
        bool isValid = true;

        for (int j = 1; j <= n_segment; j++)
        {
            string segment = parseSegment(search);
            int depth = 0;
            for (int l = 0; l < N; l++)
            {
                countDepth(depth, container[l]);
                if (container[l].find("<" + segment) != string::npos && depth == j) {
                    countFound++;
                    if (j == n_segment) {
                        tag = container[l];
                    }
                    break;
                }
            }

            if (countFound < j) {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            cout << getValue(search, tag) << endl;
        } else {
            cout << "Not Found!" << endl;
        }
    }

    return 0;
}