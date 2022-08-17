#include <iostream>
#include <fstream>
#include <random>

int Max_Balloon = 1000000;

int main()
{
    std::ofstream output_file("Input_Max.hex", std::ios_base::binary);
    if(output_file.is_open())
    {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(1,Max_Balloon); // distribution in range [1, 6]
        
        output_file.write(reinterpret_cast<char *>(&Max_Balloon), sizeof(Max_Balloon)) ;
        int gen_number;
        int c_newline = '\n';
        for(auto i = 0; i < Max_Balloon; i++) {
            gen_number = dist6(rng);
            output_file.write(reinterpret_cast<char *>(&c_newline), sizeof(c_newline));
            output_file.write(reinterpret_cast<char *>(&i), sizeof(i));
            //output_file << '\n';
            //output_file << dist6(rng);
        }
        output_file.write(reinterpret_cast<char *>(&c_newline), sizeof(c_newline));

        output_file.close();
    }

    return 0;

}