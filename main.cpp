//
// Created by User on 13.11.2022.
//
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <cblas.h>

const int N = 2048;
const int M =  10;

float **createMatrix() {
    auto **A = new float *[N];
    for (int i = 0; i < N; ++i) {
        A[i] = new float[N];
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            A[i][j] = 0;
        }
    }
    return A;
}

float **createI() {
    float **A = createMatrix();
    for (int i = 0; i < N; ++i) {
        A[i][i] = 1;
    }
    return A;
}

float maxRow(float **A) {
    float max = 0;
    float sum;
    for (int i = 0; i < N; ++i) {
        sum = 0;
        for (int j = 0; j < N; ++j) {
            sum += fabs(A[i][j]);
        }
        max = (sum > max) ? sum : max;
    }
    return max;
}

float maxCol(float **A) {
    float max = 0;
    float sum;
    for (int j = 0; j < N; ++j) {
        sum = 0;
        for (int i = 0; i < N; ++i) {
            sum += fabs(A[i][j]);
        }
        max = (sum > max) ? sum : max;
    }
    return max;
}

float **createB(float *A[], float colMax, float rowMax) {
    float **B = createMatrix();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            B[i][j] = A[j][i] / (colMax * rowMax);
        }
    }
    return B;
}

float **createR(float *I [], float *A[], float *B[]) {
    float **C = cblas_sgemm(CblasRowMajor,CblasNoTrans,CblasNoTrans,N,N,N,1.0,&B[0][0],N,&A[0][0],N,0.0,&I[0][0],N);
    float **R = cblas_sgemm(CblasRowMajor,CblasNoTrans,CblasNoTrans,N,N,N,1.0,&I[0][0],N,&I[0][0],N,-1.0,&C[0][0],N);
    return R;
}

float **createRevMatrix(float *R[], float *B[]) {
    float **revA = createMatrix();
    float **buffer = createI();
    for (int i = 0; i < M; ++i) {
        cblas_sgemm(CblasRowMajor,CblasNoTrans,CblasNoTrans,N,N,N,1.0,&revA[0][0],N,&I[0][0],N,1.0,&buffer[0][0],N);
        cblas_sgemm(CblasRowMajor,CblasNoTrans,CblasNoTrans,N,N,N,1.0,&buffer[0][0],N,&I[0][0],N,1.0,&R[0][0],N);
    }
    cblas_sgemm(CblasRowMajor,CblasNoTrans,CblasNoTrans,N,N,N,1.0,&revA[0][0],N,&B[0][0],N,0.0,&I[0][0],N);
    return revA;
}

void printMatrix(float *A[]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << A[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    float **A = createMatrix();
    A[0][0] = 1.0;
    A[0][1] = -1.0;
    A[1][0] = -1.0;
    A[1][1] = 2.0;
    float **Btest = createMatrix();
    Btest[0][0] = 2.0;
    Btest[0][1] = 1.0;
    Btest[1][0] = 1.0;
    Btest[1][1] = 1.0;
    float colMax = maxCol(A);
    float rowMax = maxRow(A);
    float **B = createB(A, colMax, rowMax);
    float **I = createI();
    float **R = createR(I, A, B);
    float **revA = createRevMatrix(R, B);
    //printMatrix(revA);
}
