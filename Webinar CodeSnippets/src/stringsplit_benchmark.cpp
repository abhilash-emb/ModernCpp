#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string_view>

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

std::vector<std::string> split_sv(std::string_view str, std::string_view delims = " ")
{
    std::vector<std::string> output;
    auto first = begin(str);

    while (first != end(str))
    {
        const auto second = std::find_first_of(first, end(str), 
                  begin(delims), end(delims));

        if (first != second)
            output.emplace_back(first, second);

        if (second == end(str))
            break;

        first = std::next(second);
    }

    return output;
}

std::vector<std::string> split(const std::string& str, const std::string& delims = " ")
{
    std::vector<std::string> output;
    auto first = begin(str);

    while (first != end(str))
    {
        const auto second = std::find_first_of(first, end(str), 
                  begin(delims), end(delims));

        if (first != second)
            output.emplace_back(first, second);

        if (second == end(str))
            break;

        first = std::next(second);
    }

    return output;
}

// static void string_split(benchmark::State& state) {
//   std::string str { HamletSoliloquy };
//   for (auto _ : state) {
//     auto v = split(str);
//     benchmark::DoNotOptimize(v);
//   }
// }
// // Register the function as a benchmark
// BENCHMARK(string_split);

// static void string_split_sv(benchmark::State& state) {
//   for (auto _ : state) {
//     auto v = split_sv(HamletSoliloquy);
//     benchmark::DoNotOptimize(v);
//   }
// }
// BENCHMARK(string_split_sv);

int main()
{
    auto string_list = split(HamletSoliloquy);
    for(const auto &word : string_list) std::cout << word<< "\n";
    auto string_list1 = split_sv(HamletSoliloquy);
    for(const auto &word : string_list1) std::cout << word<< "\n";
    return 0;
}