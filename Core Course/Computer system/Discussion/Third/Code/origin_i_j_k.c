#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1024

// 朴素的 i-j-k 三层循环矩阵乘法 (整型版本)
void naive_gemm(int *A, int *B, int *C)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int sum = 0;
            for (int k = 0; k < N; k++)
            {
                // 痛点依旧：B[k*N + j] 是按列跳跃访问的
                sum += A[i * N + k] * B[k * N + j];
            }
            C[i * N + j] = sum;
        }
    }
}

// 矩阵初始化（填充 0~99 的随机整数，防止累加溢出）
void init_matrix(int *mat)
{
    for (int i = 0; i < N * N; i++)
    {
        mat[i] = rand() % 100;
    }
}

int main()
{
    // 1. 在堆区分配内存
    int *A = (int *)malloc(N * N * sizeof(int));
    int *B = (int *)malloc(N * N * sizeof(int));
    int *C = (int *)malloc(N * N * sizeof(int));

    if (A == NULL || B == NULL || C == NULL)
    {
        printf("内存分配失败！\n");
        return -1;
    }

    // 2. 初始化矩阵
    srand(time(NULL));
    init_matrix(A);
    init_matrix(B);

    for (int i = 0; i < N * N; i++)
        C[i] = 0;

    printf("开始计算 %d x %d 整数矩阵乘法 (朴素 i-j-k 版本)...\n", N, N);

    // 3. 核心计时逻辑
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    naive_gemm(A, B, C);

    clock_gettime(CLOCK_MONOTONIC, &end);

    // 计算耗时 (秒)
    double time_taken = (end.tv_sec - start.tv_sec) * 1e9;
    time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;

    printf("计算完成！耗时: %f 秒\n", time_taken);

    // 4. 释放内存
    free(A);
    free(B);
    free(C);

    return 0;
}