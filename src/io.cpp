#include "io.hpp"

#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

namespace il {
mmap_file::mmap_file(const char* path)
{
    m_fd = open(path, O_RDONLY);
    if (m_fd < 0) {
        return;
    }

    struct stat statbuf;
    int error = fstat(m_fd, &statbuf);
    if (error < 0) {
        return;
    }

    m_size = statbuf.st_size;

    void* mapped_ptr = mmap(nullptr, m_size, PROT_READ, MAP_SHARED, m_fd, 0);
    if (mapped_ptr == MAP_FAILED) {
        return;
    }

    m_data = reinterpret_cast<char*>(mapped_ptr);
}

mmap_file::~mmap_file()
{
    if (ok()) {
        close(m_fd);
    }
}
}
