#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

const std::string delimiter = ":";

std::string serialize(std::vector<std::string>& input_string)
{
    std::string ss_string;
    for(const auto &word: input_string) {
        ss_string.insert(ss_string.size(), std::to_string(word.size()));
        ss_string.insert(ss_string.size(), delimiter);
        ss_string.insert(ss_string.size(), word);
    }
    return ss_string;
}

std::vector<std::string> deserialize(std::string& ss_string)
{
    std::vector<std::string> ds_string;
    std::string outp;
    auto pos = 0;
    while( ss_string.find(delimiter, pos) != std::string::npos ) {
        auto s_word_size = ss_string.substr(pos, ss_string.find(delimiter));
        std::copy_n(begin(ss_string)+pos+s_word_size.size()+delimiter.size(), std::stoi(s_word_size), std::back_inserter(outp));
        ds_string.push_back(outp);
        outp.clear();
        pos += s_word_size.size()+delimiter.size()+std::stoi(s_word_size);
    }
    return ds_string;
} 

int main()
{
    std::vector<std::string> input_string {"cat", "doggo", "27"};
    for(auto element: input_string)
        std::cout <<element <<"\n";
    
    auto ss_string = serialize(input_string);

    std::cout <<ss_string <<"\n";
    
    auto org_string = deserialize(ss_string);
    for(auto element: org_string)
        std::cout <<element <<"\n";
    
    return 0;

}

