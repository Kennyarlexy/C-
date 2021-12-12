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
    if (str.substr(0, 3) != "tag" && str.substr(0, 4) != "<tag" && str.substr(0, 5) != "</tag") {
        return 0;
    }

    for (int n = 1; n <= iteration; n++)
    {
        int i = 1;
        while (i <= 3)
        {
            ss >> ch;
            if (ch == '/' || ch == '<') {
                continue;
            } else if (ch == '~') {
                break;
            }
            i++;
        }
        if (!(ss >> number)) {
            return 0;
        }
        ss >> ch;
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

    int n = 0;
    while (n < N)
    {
        std::getline(std::cin, tag);
        if (get_Int(tag) == 0) {
            N--;
            continue;
        }
        tags.push_back(tag);
        pos[get_Int(tag) - 1].push_back(n);
        n++;
    }

    std::string ser;
    std::vector<std::string> result;
    for (int i = 0; i < Q; i++)
    {
        std::cin >> ser;
        int ser_segment = std::count(ser.begin(), ser.end(), '.') + 1;
        bool is_valid = true;
        int begin = 0;
        int begin_in_tags = 0;
        int layer = 1;
        for (int j = 1; j <= ser_segment; j++)
        {
            int order = get_Int(ser, j) - 1;
            if (order < 0) {
                is_valid = false;
                break;
            } else if (order > N/2 - 1) {
                is_valid = false;
                break;
            }
            begin_in_tags = pos[order][0];
            if (begin_in_tags > 0) {
                for (int k = begin; k < begin_in_tags; k++)
                {
                    if (tags[k][1] == 't') {
                        layer++;
                    } else if (tags[k][1] == '/') {
                        layer--;
                    } else {
                        is_valid = false;
                        break;
                    }
                }
                if (layer != j) {
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

    for (std::string answer : result)
    {
        std::cout << answer << std::endl;
    }

    return 0;
}



/*
20 19
<tag1 v1 = "123" v2 = "43.4" v3 = "hello">
</tag1>
<tag2 v4 = "v2" name = "Tag2">
<tag3 v1 = "Hello" v2 = "World!">
</tag3>
<tag4 v1 = "Hello" v2 = "Universe!">
</tag4>
</tag2>
<tag5>
<tag7 new_val = "New">
</tag7>
</tag5>
<tag6>
<tag8 intval = "34" floatval = "9.845">
<ntag nv = "4$">
<nvtag nv = "6$">
</nvtag>
</ntag>
</tag8>
</tag6>
tag1~v1
tag1~v2
tag1~v3
tag4~v2
tag2.tag4~v1
tag2.tag4~v2
tag2.tag3~v2
tag5.tag7~new_val
tag5~new_val
tag7~new_val
tag6.tag8~intval
tag6.tag8~floatval
tag6.tag8~val
tag8~intval
tag6.tag8.ntag~nv
tag6.tag8.ntag.nvtag~nv
tag6.tag8.nvtag~nv
randomtag~nv
tag283.tag21.den~jef
*/