#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <functional>
#include <string>
#include <map>
#include <random>
#include <numeric>
#include <string_view>
#include <execution>

/* Word Count */
const std::string HamletSoliloquy {
  "To be, or not to be, that is the question:"
  "Whether 'tis nobler in the mind to suffer"
  "The slings and arrows of outrageous fortune,"
  "Or to take arms against a sea of troubles"
  "And by opposing end them. To die—to sleep,"
  "No more; and by a sleep to say we end"
  "The heart-ache and the thousand natural shocks"
  "That flesh is heir to: 'tis a consummation"
  "Devoutly to be wish'd. To die, to sleep;"
  "To sleep, perchance to dream—ay, there's the rub:"
  "For in that sleep of death what dreams may come,"
  "When we have shuffled off this mortal coil,"
  "Must give us pause—there's the respect"
  "That makes calamity of so long life."
};

bool is_word_beginning(char left, char right) {
    return std::isspace(left) && !std::isspace(right);
}

std::size_t word_count(std::string_view s) {
    
    if(s.empty()) return 0;
    
    std::size_t wc = std::transform_reduce(
        std::execution::unseq,
        s.begin(), s.end()-1,
        s.begin()+1,
        std::size_t(!std::isspace(s.front()) ? 1 : 0),
        std::plus<std::size_t>(),
        is_word_beginning
    );

    return wc;
}

int main()
{
    
    /* string to lowercase */
    std::string my_string {"This is my string To test"};
    std::transform(begin(my_string), end(my_string), begin(my_string), [](char ch){return std::tolower(ch);});
    std::cout<<my_string <<"\n";

    /* Random values to be inserted to vector */
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> distribution(1.0, 100.0);
    auto randomGenerator = [&distribution, &mt](){ return distribution(mt); };
    std::vector<int> my_vector;
    my_vector.resize(20);
    std::generate(begin(my_vector), end(my_vector), randomGenerator);
    std::for_each(begin(my_vector), end(my_vector), [](auto elem){std::cout<<elem<<" ";});

    /* replace values matching condition */
    std::vector<int> my_vector {1,2,1,3,1,1,0,8,1,3,6,6,1,8,0};
    const auto acceptable_limit = 3;
    std::replace_if(begin(my_vector), end(my_vector), [](auto elem){ return elem < acceptable_limit;}, 0);
    std::for_each(begin(my_vector), end(my_vector), [](auto elem){std::cout<<elem<<" ";});

    /* sensor drift calculation */
    std::vector<int> my_vector {1,2,1,3,1,1,2,2,3,5,6,6,8,10,12};
    const auto deviation_limit = 2;
    auto it = std::adjacent_find(begin(my_vector), end(my_vector), [deviation_limit](auto elem, auto next_elem){return std::abs(next_elem-elem) > deviation_limit;});
    if(it != end(my_vector))
        std::cout <<"Unacceptable deviation found\n";
    else
        std::cout <<"Values under acceptable deviation\n";

    /* word count test */
    std::string test_string {"This is a"};// test string for word count"}; 
    std::cout<< word_count(test_string)<<"\n";
    std::cout <<num_chars <<"\n";
    
    return 0;

}