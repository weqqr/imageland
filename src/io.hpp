#pragma once

#include <unistd.h>

namespace il {
class mmap_file {
public:
    mmap_file(const char* path);
    ~mmap_file();

    bool ok() const { return m_data != nullptr; }
    char* data() const { return m_data; }
    size_t size() const { return m_size; }

private:
    int m_fd = -1;
    char* m_data = nullptr;
    size_t m_size = 0;
};
}
