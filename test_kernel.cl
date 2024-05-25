__kernel void test_kernel(
    __global int *data,
    int data_size
)
{
    int i = get_global_id(0);
    if(i>=data_size)return;

    printf("%d: %d ok \n", i,data[i]);

}
