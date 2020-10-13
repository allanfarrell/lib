// #ifndef ARRAY_MGR
// #define ARRAY_MGR
#include <cstdlib>
#include <cstdio>

// Put in the header
struct arr { int count; int byte_size; void* ptr; };

arr create(int count, int byte_size)
{
    arr output;
    output.ptr = malloc(count * byte_size);
    if(output.ptr == nullptr)
    {
        return output;              // Should throw error
    }

    output.count = count;
    output.byte_size = byte_size;
    return output;
}

void push(arr &input, void* new_obj)
{
    void* new_ptr = realloc(input.ptr, input.byte_size + sizeof(new_obj));
    if(new_ptr != nullptr)
    {
        return;         // Should throw error
    }

    // Memory is available, update data
    input.count++;
    input.byte_size += sizeof(new_obj);
    input.ptr = new_ptr;
}

void pop(arr &input, int idx)
{
    void* new_ptr = realloc(input.ptr, input.byte_size - (input.byte_size / input.count));
    if(new_ptr != nullptr)
    {
        return;         // Should throw an error
    }

    while(idx < input.count - 2)
    {
        new_ptr[idx] = input.ptr[idx + 1];
    }

    // Memory is available, update data
    input.count--;
    input.byte_size -= (input.byte_size / input.count);
    input.ptr = new_ptr;
}

void insert_after(arr &input)
{

}

//#endif

int main()
{
    /*
    int *arr;
    arr = (int*)malloc(2*sizeof(int));
    arr[0] = 1;
    arr[1] = 2;

    int *arr_ptr = (int*)realloc(arr, 3 * sizeof(int));
    arr_ptr[2] = 9;
    */
    arr test = create(3, sizeof(int));
    arr.ptr[0] = 1;
    arr.ptr[1] = 2;
    arr.ptr[2] = 3;

    for(int i = 0; i < 3; i++)
    {
        printf("Test");
        printf("%d\n", arr.ptr[i]);
    }
}