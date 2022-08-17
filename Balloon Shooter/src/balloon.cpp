/* Ballon shooting Program from Innovate Coder instagram

 -- Balloon Shooter --
 You are given an array of N integers. Each integer represents height of a balloon.
 So there are N balloons lined up according to their height, 
 the first one being at the leftmost and the last one being at the rightmost.
 Your aim is to destroy all these balloons. Now a balloon can only be destroyed,
 if a player shoots it with an arrow. Each arrow is shot from left to right, 
 with the height that the player chooses.
 The arrow travels from left to right until it hits a balloon, 
 at which point the balloon gets destroyed and the arrow continues to travel in the same direction
 with its height reduced by 1 unit.
 Find out the minimum number of arrows required to destroy a given set of balloons.

 -- Input Format --
 Read from a file called Input.hex
 The first line of the input contains the total number of balloons N where N is 1<N<1000000
 The subsequent lines contain height(H) of each balloon in N where H is 1<H<1000000 

 -- Constraints --
 Time Limit : 2 seconds (MAX)

 -- Output format --
 The only line which tells the minimum number of arrows required to successfully shoot all the arrows

 -- Sample Input --
 5
 2 
 1 
 4
 5
 3

 -- Expected Output --
 3
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <unordered_map>

const int Max_Balloons = 1000000;

int min_arrows(std::vector<int> &);

int main()
{
    std::ifstream ip_file("Input_Max.hex", std::ios::binary | std::ios::ate);
    if(ip_file.is_open())
    {
        int fsize = ip_file.tellg();
        ip_file.seekg(SEEK_SET);

        int n_balloons;
        ip_file.read(reinterpret_cast<char *>(&n_balloons),sizeof(n_balloons));

        if( (n_balloons > Max_Balloons) || (n_balloons < 1) || (fsize != (n_balloons+1)*sizeof(int)*2) ) {
            std::cout <<"!!! Out of Range or Size Mismatch!!! \n";
            return -1;
        }

        std::unordered_multimap<int, int> b_heights;
        int height = 0;
        b_heights.reserve(Max_Balloons);  
        
        while(ip_file.read(reinterpret_cast<char *>(&height),sizeof(height))) {
            if(height != 0 && height != '\n') {
                auto it = b_heights.find(height+1);
                if(it != b_heights.end()) {
                    b_heights.erase(height+1);
                    b_heights.insert({height, 1});
                }
                else {  
                    // insert the value, cannot use a previous arrow
                    b_heights.insert({height, 1});
                }
            }
        }

        std::cout << "Minimum number of arrows required is : " <<b_heights.size()<<  "\n" ;

        ip_file.close();
    }
    return 0;
}

















