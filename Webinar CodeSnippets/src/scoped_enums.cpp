#include <iostream>

// enum options {
// 	OPTION_1 = 1,
// 	OPTION_2 = 2
// };

// enum more_options {
// 	OPTION_A = 1,
//     OPTION_B = 2,
//     OPTION_C = 3,
//     OPTION_D = 4
// };


enum class options {
    OPTION_1 = 1,
 	OPTION_2 = 2
};

enum class more_options {
	OPTION_A = 1,
    OPTION_B = 2,
    OPTION_C = 3,
    OPTION_D = 4
};

int main()
{
    auto val = options::OPTION_1;
    //val = options::OPTION_B;
    std::cout << (int)val << "\n";
    return 0;
}