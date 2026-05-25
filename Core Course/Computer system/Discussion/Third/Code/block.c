#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1024
// 定义块大小 (Block Size)。
// 假设 L1 Cache 为 32KB。3个 32x32 的 int 矩阵块占用 32*32*4*3 = 12KB，完美塞进 L1 Cache。
#define b 32

// 终极优化版：分块矩阵乘法 (6 层循环)
void blocked_gemm(int *A, int *B_mat, int *C)
{
    // ---------------- 外三层：移动块 ----------------
    for (int i = 0; i < N; i += b)
    {
        for (int j = 0; j < N; j += b)
        {
            for (int k = 0; k < N; k += b)
            {

                // ---------------- 内三层：块内运算 (结合 i-k-j 优化) ----------------
                for (int i1 = i; i1 < i + b; i1++)
                {
                    for (int k1 = k; k1 < k + b; k1++)
                    {
                        // 提取常数到寄存器
                        int r = A[i1 * N + k1];
                        for (int j1 = j; j1 < j + b; j1++)
                        {
                            // 完美的步长为 1 的连续访问，且绝不发生容量不命中
                            C[i1 * N + j1] += r * B_mat[k1 * N + j1];
                        }
                    }
                }
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

    printf("开始计算 %d x %d 整数矩阵乘法 (分块矩阵)...\n", N, N);

    // 3. 核心计时逻辑
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    blocked_gemm(A, B, C);

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