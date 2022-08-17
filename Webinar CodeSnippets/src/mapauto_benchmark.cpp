static void StringCreation(benchmark::State& state) {
  // Code inside this loop is measured repeatedly
  std::map<std::string, int> my_map;
  for(auto i = 0; i < 1000; i++) {
    my_map.insert({std::to_string(i),i});
  }
  for (auto _ : state) {
    auto count1 = 0;
    for(const auto &p: my_map) {
        if(p.second > 10) {
            ++count1;
        }
    }
    // Make sure the variable is not optimized away by compiler
    benchmark::DoNotOptimize(my_map);
  }
}
// Register the function as a benchmark
BENCHMARK(StringCreation);

static void StringCopy(benchmark::State& state) {
  // Code before the loop is not measured
  std::map<std::string, int> my_map;
  for(auto i = 0; i < 1000; i++) {
    my_map.insert({std::to_string(i),i});
  }
  for (auto _ : state) {
    auto count2 = 0;
    for(const std::pair<std::string, int> &p: my_map) {
        if(p.second > 10) {
            ++count2;
        }
    }
    // Make sure the variable is not optimized away by compiler
    benchmark::DoNotOptimize(my_map);
  }
}
BENCHMARK(StringCopy);
