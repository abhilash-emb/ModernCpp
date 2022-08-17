/* Progressive Taxation - Taken from Daily Programmer (Reddit) ****************************
Tax is calculated on the net income based on which tax slab the income falls in
0      - 10000  :  0%
10000  - 30000  :  10%
30000  - 100000 :  25%
100000 - xxxxx  :  40%
******************************************************************************************/
#include <iostream>
#include <algorithm>

// function to calculate tax - takes net income as input
std::pair<int, float> calc_tax(int i_net_income);

// function to calculate the net income - takes the overall tax rate as input
std::pair<int, bool> calc_income(float i_taxation_rate);

int main()
{
    int net_income;

    std::cout << "Enter the income for tax calculation (0 - 1000000000)" << std::endl;
    std::cin >> net_income;

    // do input validation here

    std::pair<int, float> net_tax = calc_tax(net_income);
    std::cout << "net_tax = " << net_tax.first << std::endl << "overall taxation = " << net_tax.second << std::endl;

    float taxation_rate;
    
    std::cout << "Enter the overall tax rate - upto 3 decimal places(0.0 - 0.399)" << std::endl;
    std::cin >> taxation_rate;
        
    std::pair<int, bool> comp_income = calc_income(taxation_rate);
    
    comp_income.second ? std::cout << "net_income = " << comp_income.first << std::endl : std::cout << "Invalid taxation rate" << std::endl;

    return 0;
}

const std::pair<int, float> TS_0_10K        = {0,      0.0};
const std::pair<int, float> TS_10_30K       = {10000,  0.10};
const std::pair<int, float> TS_30_100K      = {30000,  0.25};
const std::pair<int, float> TS_100K_above   = {100000, 0.40};

const int tax_magic_value_UPTO30K   = 1000;
const int tax_magic_value_UPTO100K  = 5500;
const int tax_magic_value_OVER100K  = 20500;

std::pair<int, float> calc_tax(int i_net_income)
{
    int calc_tax = 0;

    i_net_income > TS_100K_above.first   ?    calc_tax   += (i_net_income - TS_100K_above.first) * TS_100K_above.second : calc_tax;
    
    i_net_income > TS_30_100K.first      ?    calc_tax   += std::min(i_net_income - TS_30_100K.first, TS_100K_above.first - TS_30_100K.first) * TS_30_100K.second : calc_tax;
    
    i_net_income > TS_10_30K.first       ?    calc_tax   += std::min(i_net_income - TS_10_30K.first, TS_30_100K.first - TS_10_30K.first) * TS_10_30K.second : calc_tax;

    return std::make_pair(calc_tax, (float)calc_tax/i_net_income);
}

std::pair<int, bool> calc_income(float i_taxation_rate)
{
    std::pair<int, bool> net_income = {0, true};

    i_taxation_rate > 0.0 && i_taxation_rate < 0.066667 ? net_income.first += tax_magic_value_UPTO30K / (TS_10_30K.second - i_taxation_rate) : net_income.first;

    i_taxation_rate > 0.066667 && i_taxation_rate < 0.195000 ? net_income.first +=  tax_magic_value_UPTO100K / (TS_30_100K.second - i_taxation_rate) : net_income.first;

    i_taxation_rate > 0.195000 && i_taxation_rate < 0.399795 ? net_income.first += tax_magic_value_OVER100K / (TS_100K_above.second - i_taxation_rate) : net_income.first;
    
    i_taxation_rate < 0.0 || i_taxation_rate > 0.399795 ? net_income.second = false : net_income.second;

    return net_income;
}