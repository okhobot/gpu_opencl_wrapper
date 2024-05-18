__kernel void test_kernel(
    int data_size
)
{
    int i = get_global_id(0);
    if(i>=data_size)return;

    printf("%d: ok \n", i);

}
