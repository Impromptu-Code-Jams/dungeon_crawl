#include <benchmark/benchmark.h>

#include "SpikeTrapRoom.h"

static void myBenchmarkFunction()
{
    class MyType
    {
    public:
        MyType() {}
        MyType(const MyType& other) { i = other.i; }
        MyType(MyType&& other) noexcept {
            i = std::move(other.i);
        }
    private:
        int i = 0;
    };
    std::vector<MyType> vec;
    for (unsigned int i = 0; i < 100000; i++) {
        vec.emplace_back();
    }
}

static void BM_SpikeTrapRoom(benchmark::State& state) {
    for (auto _ : state)
        myBenchmarkFunction();
}
// Register the function as a benchmark
BENCHMARK(BM_SpikeTrapRoom);
TEST(MyTest, THing) {

}
BENCHMARK_MAIN();