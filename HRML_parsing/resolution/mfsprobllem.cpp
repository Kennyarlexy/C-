#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

int get_Int(std::string str, int iteration = 1)
{
    std::stringstream ss;
    ss << str;

    char ch;
    int number;
    for (int n = 0; n < iteration; n++)
    {
        // std::cout << "iteration-" << iteration << std::endl;
        int i = 1;
        while (i <= 3)
        {
            // std::cout << "getting char-" << i << std::endl;
            ss >> ch;
            // std::cout << "got " << ch << std::endl;
            if (ch == '/' || ch == '<' || ch == '.') {
                continue;
            } else if (ch == '~') {
                break;
            }
            i++;
        }
        ss >> number;
        // std::cout << "got number " << number << std::endl;
    }

    return number;
}

std::string get_Attribute(std::string str)
{
    int wave_index = str.find('~');
    std::string attribute = str.substr(wave_index + 1, str.length() - (wave_index + 1));

    return attribute;
}

std::string get_Value(std::string attribute, std::string tag)
{
    attribute = " " + attribute + " ";
    std::size_t found = tag.find(attribute);
    if (found != std::string::npos) {
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
        std::string value = tag.substr(start, length);
        return value;
    } else {
        return "Not Found!";
    }
    
}

int main()
{
    int N, Q;
    std::cin >> N >> Q;
    std::cin.ignore(100, '\n');

    std::vector<std::string> tags;
    std::string tag;
    std::vector<std::vector<int>> pos(N/2);

    for (int i = 0; i < N; i++)
    {
        // std::cout << "Input tag " << i + 1 << ": ";
        std::getline(std::cin, tag);
        tags.push_back(tag);
        pos[get_Int(tag) - 1].push_back(i);
    }


    std::string ser;
    std::vector<std::string> result;
    for (int i = 0; i < Q; i++)
    {
        std::cin >> ser;
        int ser_segment = std::count(ser.begin(), ser.end(), '.') + 1;
        //start  checking from index begin_pos, get it form pos vector:

        bool is_valid = true;
        //below loop is only to determine if ser is valid and therefore value will be looked
        int begin = 0;
        int begin_in_tags = 0;
        int layer = 1;
        for (int j = 1; j <= ser_segment; j++)
        {
            std::cout << "checking segment-" << j << std::endl;
            begin_in_tags = pos[get_Int(ser, j) - 1][0]; //particular index inside tags vector
            //if the first tag is not tag1 (tag1 is always the first element, therefore layer will be 0, need to check the amount of layer
            if (begin_in_tags > 0) {
                for (int k = begin; k < begin_in_tags; k++)
                {
                    if (tags[k][1] != '/') {
                        std::cout << "adding layer" << std::endl;
                        layer++;
                    } else if (tags[k][1] == '/') {
                        layer--;
                    } else {
                        is_valid = false;
                        break;
                    }
                }
                std::cout << "Layer = " << layer << std::endl;
                if (layer != j) {
                    std::cout << "tag not valid!" << std::endl;
                    is_valid = false;
                    break;
                }
            }
            begin = begin_in_tags;
        }
        if (is_valid) {
            std::string attribute = get_Attribute(ser);
            std::string open_tag = tags[begin_in_tags];
            result.push_back(get_Value(attribute, open_tag));
        } else {
            result.push_back("Not Found!");
        }
    }
    return 0;
}

/*
8 1
<tag1>
<tag2>
</tag2>
<tag3 test = "hello">
<tag4 test = "world">
</tag4>
</tag3>
</tag1>
tag3.tag4~test
*/

