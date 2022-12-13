#include <cstdlib>
#include <iostream>
const unsigned long long number_try = 10;
const unsigned long long L1_SIZE_for_int = 32*1024/sizeof(unsigned int);
const unsigned long long L2_SIZE_for_int = 256*1024/sizeof(unsigned int);
const unsigned long long L3_SIZE_for_int = 12*1024*1024/sizeof(unsigned int);
const unsigned long long first_size = (L1_SIZE_for_int + L2_SIZE_for_int + L3_SIZE_for_int)/sizeof(unsigned int);
const unsigned long long offset = 16*1024*1024/sizeof(unsigned int);
inline unsigned long long rdtsc() {
    unsigned int lo, hi;
    asm volatile ( "rdtsc\n" : "=a" (lo), "=d" (hi));
    return ((unsigned long long) hi << 32) | lo;
}
void preparation_cpu(float *a, float*b, float*result, int N){
    float sum;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            sum = 0;
            for (int k = 0; k < N; k++) {
                sum += a[i * N + k] * b[k * N + j];
            }
            result[i * N + j] = sum;
        }
    }
}

unsigned long long  runArray(unsigned int const *array, size_t N)
{
    unsigned long long i;
    unsigned long long t1, t2;
    size_t k;
    unsigned long long tmin = 1000000000;
    for(k = 0, i = 0; i < N; i++)
        k = array[k];
    if (k == 1234) std::cout << "wow!";
    for(size_t j = 0; j < number_try; j++)
    {
        t1 = rdtsc();
        for(k = 0, i = 0; i < N; i++)
            k = array[k];
        t2 = rdtsc();
        if (k == 1234) std::cout << "wow!";
        if(tmin > t2 - t1)
            tmin = t2 - t1;
    }
    return tmin;
}

void initArray(unsigned int *array, unsigned int fragments, size_t size)
{
    size_t i;
    size_t j;
    for(i = 0; i < size; ++i)
    {
        for(j = 0; j < (fragments-1);j++)
        {
            array[i+j*offset] = i+(j+1)*offset;
        }
        array[i+j*offset] = i+1;
    }
    array[offset*fragments-1] = 0;
    for(i = 0; i < size; i++)
    {
        for(j = 1; j < fragments; j++)
            array[i + (j - 1) * offset] = i + j * offset;
        array[i + (j - 1) * offset] = i + 1;
    }
    array[i - 1 + (j - 1) * offset] = 0;
}
void runArray(unsigned int fragments)
{
    unsigned int *array = new unsigned int[fragments*offset];
    initArray(array, fragments, first_size/fragments);
    printf("fragments: %u\t tacts: %llu\n", fragments, runArray(array,fragments*offset) / (fragments*offset));
    delete [] array;
}

int main()
{
    float *a = (float*)malloc(256 * 256 * sizeof(float));
    float *b = (float*)malloc(256 * 256 * sizeof(float));
    float *c = (float*)malloc(256 * 256 * sizeof(float));
    preparation_cpu(a,b,c,256);
    if (c[0] == 1234) std::cout << "wow!";
    for(int i = 1; i <= 32; i++)
    {
        runArray(i);
    }
    free(a);
    free(b);
    free(c);
    return 0;
}
