#include <chrono>
#include <functional>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

std::mutex mutex;

auto worker(int& n) -> void {
    mutex.lock();
    n++;
    mutex.unlock();
}

auto main() -> int {
    int n_ = 0;
    std::vector<std::thread> threads;

    // spawn 10k threads
    for (std::size_t i = 0; i < 10000; i++) {
        threads.push_back(std::thread(worker, std::ref(n_)));
    }

    auto start = std::chrono::high_resolution_clock::now();
    for (auto& th : threads) th.join();
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> exec_duration(end - start);

    std::cout << n_ << std::endl;
    std::cout << "Finished in: " << exec_duration.count() << "s" << std::endl;

    return EXIT_SUCCESS;
}