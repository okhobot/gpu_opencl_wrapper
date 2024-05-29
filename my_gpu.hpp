#ifndef MY_GPU_HPP_
#define MY_GPU_HPP_

#include <CL/cl.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#define console_logs 1
#define custom_type double

class GPU
{
private:
    std::map<std::string, cl::Buffer> variables;
    std::map<std::string,cl::Kernel> kernels;

    std::vector<cl::Device> contextDevices;

    cl::CommandQueue gpu_queue;
    cl::Context context;
    cl::Kernel kernel;
    cl::Program::Sources source;
    cl::Program program;

    std::ifstream sourceFile;
    std::string sourceCode;

    int iArg;

public:

    void init_gpu(std::vector<std::string> kernel_names);

    void operator = (GPU &_gpu);


    void add_variable(std::string key, cl_mem_flags mem_flag, size_t bufsize);
    cl::Buffer* get_variable(std::string key);
    void set_variable(std::string key,cl::Buffer* variable);


    template <typename T>
    void write_variable(std::string key, size_t bufsize, std::vector<T> &data)
    {
        gpu_queue.enqueueWriteBuffer(variables[key], CL_TRUE, 0, bufsize, data.data());
    }

    template <typename T>
    void read_variable(std::string key, size_t bufsize, std::vector<T> &data)
    {
        gpu_queue.enqueueReadBuffer(variables[key], CL_TRUE, 0, bufsize, data.data());
    }

    void process_gpu(std::string kernel_name, std::vector<std::string> variable_names, std::vector<float> floats, std::vector<int> ints, int s1, int s2=0, int s3=0);


};
#endif
