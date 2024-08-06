#ifndef ASYNC_H
#define ASYNC_H

#include "async/ThreadPool.h"
#include <thread>

namespace async {
    inline unsigned get_cpu_core_count() {
        return std::thread::hardware_concurrency();
    }
}

#endif //ASYNC_H
