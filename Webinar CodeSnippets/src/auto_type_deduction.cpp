#include <iostream>
#include <vector>
#include <memory>
#include <variant>
#include <numeric>
#include <map>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <utility>

int x = 0;

const int *get1(); 
const int &get2();
const int *get3(); 
const int &get4();
const int *get5();
const int &get6();

int main()
{
    /* Different kinds of variables */
    // const int temp = 27;
    // auto x = 27;           // (x is neither a pointer nor a reference), x's type is int
    // const auto cx = x;     // (cx is neither a pointer nor a reference), cs's type is const int
    // const auto& rx = x;    // (rx is a non-universal reference), rx's type is a reference to a const int

    // auto&& uref1 = x;      // x is int and lvalue, so uref1's type is int&
    // auto&& uref2 = cx;     // cx is const int and lvalue, so uref2's type is const int &
    // auto&& uref3 = 27;     // 27 is an int and rvalue, so uref3's type is int&&

    // const auto val1   = get1(); //const int *const val1
    // const auto val2   = get2(); //const int const &val2
    // const auto *val3  = get3(); //const int *const int val3
    // const auto &val4  = get4(); //const int &const int val4
    // const auto &val5  = get5(); //const int &const int *val5
    // //const auto &&val6 = get6(); //error as val is not an rvalue reference
    // const auto &&val7 = 27; //const int &&val7

    // std::cout<<typeid(val1).name()<<"\n";
    // std::cout<<typeid(val2).name()<<"\n";
    // std::cout<<typeid(val3).name()<<"\n";
    // std::cout<<typeid(val4).name()<<"\n";
    // std::cout<<typeid(val5).name()<<"\n";
    // std::cout<<typeid(val6).name()<<"\n";
    // std::cout<<typeid(val7).name()<<"\n";
    
    /* union of unique pointers */
    // std::unique_ptr<int> pt1 = std::make_unique<int>(10);
    // std::unique_ptr<int> pt2 = std::make_unique<int>(20);
    // std::unique_ptr<int> pt3 = std::make_unique<int>(30);
    // std::vector<std::unique_ptr<int>> my_vector;
    // my_vector.push_back(std::move(pt1));
    // my_vector.push_back(std::move(pt2));
    // my_vector.push_back(std::move(pt3));
    // for(std::vector<std::unique_ptr<int>>::iterator i = begin(my_vector); i != end(my_vector); ++i) {
    //     std::cout<<*(*i)<<"\n";
    // }
    // for(auto i = begin(my_vector); i != end(my_vector); ++i) {
    //      std::cout<<*(*i)<<"\n";
    // }

    /* auto problem for map */
    // std::unordered_map<std::string, int> my_map {{"abc",1},{"def",2}};
    // for(auto i: my_map) {

    // }

    /* auto problem for vactor of bool */
    // std::vector<bool> my_bool_vec {1,1,1,1,1,0,0,0};
    // auto is_b2_set = my_bool_vec[2];

    /* explicit and type upgradation */
    // int b = 10;
    // short a = std::numeric_limits<short>::max();
    // int a = std::numeric_limits<int>::max();
    // short c = 10;
    // short d = std::numeric_limits<short>::max(); 
    // std::cin >>a;
    // auto t = c+d;
    // std::cout << t <<"\n";
    // auto sum = static_cast<long>(a)+b;
    // long e = 0;
    // auto f = e;
    // f = a + a;
    // std::cout << f <<"\n";
          
    return 0;

}