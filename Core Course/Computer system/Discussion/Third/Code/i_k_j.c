#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1024

// 优化版：i-k-j 三层循环矩阵乘法
void optimized_gemm(int *A, int *B, int *C)
{
    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < N; k++)
        {
            // 小技巧：把外层循环中不变的 A[i*N + k] 提取到一个局部变量寄存器里
            int r = A[i * N + k];
            for (int j = 0; j < N; j++)
            {
                // 现在的 B[k*N + j] 和 C[i*N + j] 全部是顺着内存连续读取的！
                C[i * N + j] += r * B[k * N + j];
            }
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

    printf("开始计算 %d x %d 整数矩阵乘法 (朴素 i-k-j 版本)...\n", N, N);

    // 3. 核心计时逻辑
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    optimized_gemm(A, B, C);

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