#include <iostream>
#include <chrono>
#include <vector>
#include <future>
#include <utility>

#include "async.h"
#include "cli.h"
#include "fs.h"
#include "util.h"

double work(int x) {
    auto ans = util::rand_range_f(0.0, 5.0);
    std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(1000 * ans)));
    return ans;
}

int main() {
    async::ThreadPool pool(async::get_cpu_core_count());

    std::cout << "Current CPU core count : " << async::get_cpu_core_count() << std::endl;
    auto start = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    std::vector<std::future<double>> futures;
    for (int i = 0; i < async::get_cpu_core_count(); i++) {
        auto f = pool.enqueue([i]() {
            const double result = work(i);
            std::cout << i << "th thread terminated" << std::endl;
            return result;
        });
        futures.push_back(std::move(f));
    }

    double sum = 0;
    double max = 0;
    for (auto& f : futures) {
        double r = f.get();
        sum += r;
        if (r > max) max = r;
    }

    auto end = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    std::cout << "Estimated time : " << sum << std::endl;
    std::cout << "Took " << static_cast<double>(end - start) / 1000 << " seconds" << std::endl;
    std::cout << "Max random : " << max << std::endl;
}
