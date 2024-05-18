#include <iostream>
#include <my_gpu.hpp>

int main()
{
    GPU gpu;
    gpu.init_gpu({"test_kernel"});
    gpu.process_gpu("test_kernel",{},{},{10},10);
    return 0;
}
