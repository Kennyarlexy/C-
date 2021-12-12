#include <iostream>
#include <string>
#include <vector>
#include <sstream>


int main() 
{
    int N, Q;
    std::cin >> N >> Q;
    std::cin.ignore(1000, '\n');
    //std::string whole, temp;
    std::vector<std::string> full_tags;
    std::string full_tag;

    int i = 0;
    while (i++ < N)
    {
        std::getline(std::cin, full_tag);
        if (i <= N/2) {
            full_tags.push_back(full_tag);
        }
    }

    std::cout << "Length of the vector is : " << full_tags.size() << std::endl;
    std::cout << "index 0 in the vector : " << full_tags[0] << std::endl;
    std::cout << "index 1 in the vector : " << full_tags[1] << std::endl;

    std::string ser, str, att; //ser is the input to search, str is the index in the form of string to later be converted to int index
    int index, wave_index; //index of the tag in the vector

    std::vector<std::string> result;
    i = 0;
    while (i++ < Q)
    {
        std::getline(std::cin, ser);
        std::size_t found = ser.find('~');
        wave_index = int(found);
        str = ser.substr(wave_index - 1, 1);

        std::stringstream ss; //to convert to int index
        ss.str(str);
        ss >> index;
        index--; //got the index of vector to search

        att = ser.substr(wave_index + 1, ser.length() - (wave_index + 1)); //got the name of the attribute
        std::cout << "Looking for " << att << "\n" << std::endl;
        found = full_tags[index].find(att);
        if (found != std::string::npos) {
            int att_index = int(found);
            std::cout << att << " is found at index : " << att_index << std::endl;
            std::string value = "", add = "";
            //value = full_tags[index].substr(att_index + att.length() + 4, 4);
            int j = 0;
            while (true)
            {
                add = full_tags[index][att_index + att.length() + 4 + j]; //get a character from full_tag in full_tags
                if (add == "\"") {
                    break;
                }
                value += add;
                j++;
            }
            std::cout << "true value is : " << value << std::endl;
            result.push_back(value);
        } else {
            result.push_back("Not Found!");
        }
    }
    
    for (std::string data : result)
    {
        std::cout << data << std::endl;
    }
    return 0;
}



    // for (int i = 0; i < N; i++)
    // {
    //     // fflush(stdin);
    //     std::cout << "iteration-" << i + 1 << std::endl;
    //     getline(std::cin, temp);
    //     std::cout << "temp = " << temp << std::endl;
    //     whole += temp;
    //     if (i < N - 1) {
    //         whole += " ";
    //     }
    //     std::cout << "end of iteration-" << i + 1 << "\n" << std::endl;
    // }
    
    // std::cout << whole << std::endl;

    // std::string full_open_full_open_full_sers, close_full_open_full_sers;
    // int index = 1;
    // while (index <= N/2)
    // {
    //     full_open_full_open_full_sers += "full_ser" + std::to_string(index);
    //     close_full_open_full_sers += "/" + full_open_full_open_full_sers;
    //     std::size_t full_open_found = whole.find(full_open_full_open_full_sers);
    //     std::size_t close_found = whole.find(close_full_open_full_sers);
    //     if (full_open_found != std::string::npos) {
    //         std::cout << full_open_full_open_full_sers << " ";
    //         std::cout << "\tfound at: " << int(full_open_found) << std::endl;
    //     }
    //     if (close_found != std::string::npos) {
    //         std::cout << close_full_open_full_sers << " ";
    //         std::cout << "\tfound at: " << int(close_found) << std::endl;
    //     }
    //     full_open_full_open_full_sers.clear();
    //     close_full_open_full_sers.clear();
    //     index++;
    // }

    // for (int i = 0; i < Q; i++)
    // {
        
    // }