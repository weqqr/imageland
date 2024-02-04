#include "io.hpp"
#include <stdio.h>

namespace il {
class safetensors {
public:
    safetensors() = default;

    void load_file(const char* path);

private:
};

void safetensors::load_file(const char* path)
{
    mmap_file file(path);

    printf("size=%ld bytes\n", file.size());
}
}

int main(int argc, char** argv)
{
    if (argc < 2) {
        fprintf(stderr, "usage: imageland <path/to/checkpoint>\n");
    }

    il::safetensors checkpoint;
    checkpoint.load_file(argv[1]);

    printf("Hello, world!\n");

    return 0;
}
