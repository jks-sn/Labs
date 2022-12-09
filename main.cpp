#include <cstdio>
#include <cstdlib>
#include <cmath>

inline unsigned long long rdtsc() {
    unsigned int lo, hi;
    asm volatile ( "rdtsc\n" : "=a" (lo), "=d" (hi));
    return ((unsigned long long) hi << 32) | lo;
}

void preparation_cpu(float *a, float *b, float *result, int N) {
    float sum;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum = 0;
            for (int k = 0; k < N; k++) {
                sum += a[i * N + k] * b[k * N + j];
            }
            result[i * N + j] = sum;
        }
    }
}

void fillArray(long long int *vec, long long int N) {
    long long int tmp;
    for (long long int i = 0; i < N; i++) {
        vec[i] = i;
    }
    for (int i = N - 1; i > 0; i--) {
        int j = rand() % i;
        tmp = vec[j];
        vec[j] = vec[i];
        vec[i] = tmp;
    }

}

int main(int argc, char *argv[]) {
    int N_Min = 10;
    int N_cpu = 256;
    long long int N_Max = 5000000;
    int k, i;
    unsigned long long int min;
    float *a = (float *) malloc(N_cpu * N_cpu * sizeof(float));
    float *b = (float *) malloc(N_cpu * N_cpu * sizeof(float));
    float *c = (float *) malloc(N_cpu * N_cpu * sizeof(float));
    unsigned long long begin_time, end_time;
    preparation_cpu(a, b, c, N_cpu);
    long long int *vec = (long long int *) malloc(N_Min * sizeof(long long int));
    fillArray(vec, N_Min);
    if (c[0] == 12345)
        printf("Wow!");
    for (k = 0, i = 0; i < N_Min; i++) {
        k = vec[k];
    }//preparation cash
    if (k == 12345)
        printf("Wow!");
    min = 10000000;
    begin_time = rdtsc();
    for (k = 0, i = 0; i < N_Min; i++) {
        k = vec[k];
        printf("%lld\n", k);
    }
    end_time = rdtsc();
    if (k == 12345) printf("Wow!");
    free(vec);
    free(a);
    free(b);
    free(c);
    return 0;
}
