#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1024  // 设置为1024，刚好是2的高次幂，能极大地放大Cache冲突，拉开梯队差距！

// ==========================================
// 辅助函数：初始化与重置
// ==========================================
void init_matrices(double *A, double *B, double *C) {
    for (int i = 0; i < N * N; i++) {
        A[i] = (double)(rand() % 100) / 10.0;
        B[i] = (double)(rand() % 100) / 10.0;
        C[i] = 0.0;
    }
}

void reset_C(double *C) {
    for (int i = 0; i < N * N; i++) {
        C[i] = 0.0;
    }
}

// ==========================================
// 第一梯队：王者级别 (最内层是 j，连续访问)
// ==========================================
void gemm_ikj(double *A, double *B, double *C) {
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            double r = A[i * N + k];
            for (int j = 0; j < N; j++) {
                C[i * N + j] += r * B[k * N + j];
            }
        }
    }
}

void gemm_kij(double *A, double *B, double *C) {
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            double r = A[i * N + k];
            for (int j = 0; j < N; j++) {
                C[i * N + j] += r * B[k * N + j];
            }
        }
    }
}

// ==========================================
// 第二梯队：平庸级别 (最内层是 k，B矩阵跳跃)
// ==========================================
void gemm_ijk(double *A, double *B, double *C) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double sum = 0.0;
            for (int k = 0; k < N; k++) {
                sum += A[i * N + k] * B[k * N + j];
            }
            C[i * N + j] += sum;
        }
    }
}

void gemm_jik(double *A, double *B, double *C) {
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            double sum = 0.0;
            for (int k = 0; k < N; k++) {
                sum += A[i * N + k] * B[k * N + j];
            }
            C[i * N + j] += sum;
        }
    }
}

// ==========================================
// 第三梯队：灾难级别 (最内层是 i，A和C都跳跃)
// ==========================================
void gemm_jki(double *A, double *B, double *C) {
    for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
            double r = B[k * N + j];
            for (int i = 0; i < N; i++) {
                C[i * N + j] += A[i * N + k] * r;
            }
        }
    }
}

void gemm_kji(double *A, double *B, double *C) {
    for (int k = 0; k < N; k++) {
        for (int j = 0; j < N; j++) {
            double r = B[k * N + j];
            for (int i = 0; i < N; i++) {
                C[i * N + j] += A[i * N + k] * r;
            }
        }
    }
}

// ==========================================
// 主函数：测试引擎
// ==========================================
int main() {
    printf("开始分配内存 (矩阵大小: %d x %d)...\n", N, N);
    double *A = (double *)malloc(N * N * sizeof(double));
    double *B = (double *)malloc(N * N * sizeof(double));
    double *C = (double *)malloc(N * N * sizeof(double));

    if (A == NULL || B == NULL || C == NULL) {
        printf("内存分配失败！\n");
        return -1;
    }

    printf("初始化矩阵数据...\n\n");
    srand(time(NULL));
    init_matrices(A, B, C);

    clock_t start, end;
    double cpu_time_used;

    // 定义函数指针数组方便遍历测试
    void (*gemm_funcs[])(double*, double*, double*) = {gemm_ikj, gemm_kij, gemm_ijk, gemm_jik, gemm_jki, gemm_kji};
    const char *func_names[] = {"ikj (王者 - 极佳)", "kij (王者 - 极佳)", "ijk (平庸 - 一般)", "jik (平庸 - 一般)", "jki (灾难 - 极差)", "kji (灾难 - 极差)"};

    printf("--- 开始 6 种循环顺序的性能角斗场 ---\n");
    for (int i = 0; i < 6; i++) {
        reset_C(C); // 每次计算前清空结果矩阵
        
        start = clock();
        gemm_funcs[i](A, B, C);
        end = clock();
        
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("循环顺序 %s \t 耗时: %f 秒\n", func_names[i], cpu_time_used);
    }

    free(A);
    free(B);
    free(C);
    printf("\n测试完成！内存已释放。\n");

    return 0;
}
