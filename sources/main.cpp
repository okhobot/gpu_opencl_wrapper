#include <iostream>
#include <vector>
#include <my_gpu.hpp>
#include <chrono>
int main()
{
    GPU gpu;
    gpu.init_gpu({"test_kernel"},"kernels/");

    std::vector<int> vec(100);
    for(int i=0;i<vec.size();i++)vec[i]=vec.size()-i-1;

    auto msn=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    gpu.add_variable("vec",CL_MEM_READ_WRITE,vec.size()*sizeof(int));
    gpu.write_variable("vec",vec.size()*sizeof(int),vec);
    gpu.process_gpu("test_kernel",{"vec"},{},{vec.size()},vec.size());

    std::cout<<"gpu ms spent: "<<std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()-msn<<std::endl;

    return 0;
}
