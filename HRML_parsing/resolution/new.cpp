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
        int point_count = std::count(ser.begin(), ser.end(), '.');
        bool is_valid = true;
        if (point_count > 0) {
            int outer_index, outer_start, outer_end;
            int inner_index, inner_start, inner_end;
            for (int iterate = 1; iterate <= point_count; iterate++)
            {
                outer_index = get_Int(ser, iterate) - 1; //pos of tag1 in vector -> pos[0]; tag2 -> pos[1]  ...
                outer_start = pos[outer_index][0], outer_end = pos[outer_index][1];
                inner_index = get_Int(ser, iterate + 1) - 1;
                inner_start = pos[inner_index][0], inner_end = pos[inner_index][1];
                if ((outer_start > inner_start && outer_end < inner_end)) {
                    is_valid = false;
                    break;
                } else {
                    int check = 0;
                    for (int j = outer_start + 1; j < inner_start; j++)
                    {
                        if (tags[j][1] == '/') {
                            check--;
                        } else {
                            check++;
                        }
                    }
                    if (check != 0) {
                        is_valid = false;
                        break;
                    }
                }
            }
            if (is_valid) {
                std::string attribute = get_Attribute(ser);
                std::string open_tag = tags[inner_start];
                result.push_back(get_Value(attribute, open_tag));
            } else {
                result.push_back("Not Found!");
            }
        } else {
            int index = get_Int(ser) - 1;
            int start = pos[index][0], end = pos[index][1];
            for (int j = 0; j < pos.size(); j++)
            {
                if (j == index) {
                    continue;
                }
                int check_start = pos[j][0], check_end = pos[j][1];
                if (check_start < start && check_end > end) {
                    is_valid = false;
                    break;
                }
            }
            if (is_valid) {
                std::string attribute = get_Attribute(ser);
                std::string open_tag = tags[start];
                result.push_back(get_Value(attribute, open_tag));
            } else {
                result.push_back("Not Found!");
            }
        }
    }

    for (std::string answer : result)
    {
        std::cout << answer << std::endl;
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