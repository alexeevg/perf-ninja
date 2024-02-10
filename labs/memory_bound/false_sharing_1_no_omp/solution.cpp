#include "solution.hpp"
#include <atomic>
#include <cstring>
#include <vector>
#include <thread>

  // Using std::atomic counters to disallow compiler to promote `target`
  // memory location into a register. This way we ensure that the store
  // to `target` stays inside the loop.
  struct alignas(64) Accumulator {
    std::atomic<uint32_t> value = 0;
    // char padding[64 - sizeof(value)]; may be used instead of alignas(64)
  };
  

void worker(const std::vector<uint32_t> &data, size_t start, size_t end, Accumulator& target) {
  for (size_t i = start; i < end; i++) {
    // Perform computation on each input
    auto item = data[i];
    item += 1000;
    item ^= 0xADEDAE;
    item |= (item >> 24);

    // Write result to accumulator
    target.value += item % 13;
  }
}

std::size_t solution(const std::vector<uint32_t> &data, int thread_count) {
  std::vector<Accumulator> accumulators(thread_count);
  std::vector<std::thread> threads;

  size_t chunk_size = data.size() / thread_count;
  for (int i = 0; i < thread_count; i++) {
    size_t start = i * chunk_size;
    size_t end = (i + 1) * chunk_size;
    if (i == thread_count - 1) {
      end = data.size();
    }
    threads.emplace_back(worker, std::ref(data), start, end, std::ref(accumulators[i]));
  }
  for (auto &thread : threads) {
    thread.join();
  }

  std::size_t result = 0;
  for (const auto &accumulator : accumulators) {
    result += accumulator.value;
  }
  return result;
}
