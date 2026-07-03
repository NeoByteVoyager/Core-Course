#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000007 // 故意设为奇数，以严格测试“余数处理”的开销

// ================= [1] 初始基础版本 (第一问) =================
int compute_basic(int *array1, int *array2, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array1[i] * array2[i];
    }
    return sum;
}

// ================= [2] 普通 8 路循环展开版本 (第二问) =================
int compute_unroll8(int *array1, int *array2, int size)
{
    int sum = 0;
    int i = 0;

    // 主循环：每次步进 8，利用汇编隐式偏移寻址，不需要中途自增 i
    int limit = size - 7;
    for (; i < limit; i += 8)
    {
        sum += array1[i] * array2[i];
        sum += array1[i + 1] * array2[i + 1];
        sum += array1[i + 2] * array2[i + 2];
        sum += array1[i + 3] * array2[i + 3];
        sum += array1[i + 4] * array2[i + 4];
        sum += array1[i + 5] * array2[i + 5];
        sum += array1[i + 6] * array2[i + 6];
        sum += array1[i + 7] * array2[i + 7];
    }

    // 尾部清理循环 ：处理不够 8 次的余数
    for (; i < size; i++)
    {
        sum += array1[i] * array2[i];
    }

    return sum;
}

// ================= [3] Duff's Device 版本 (第三问) =================
int compute_duff(int *array1, int *array2, int size)
{
    int sum = 0;
    int i = 0;
    int n = (size + 7) / 8;

    // 利用 switch-case 的 fall-through 特性，强行交织控制流
    switch (size % 8)
    {
    case 0:
        do
        {
            sum += array1[i] * array2[i];
            i++;
        case 7:
            sum += array1[i] * array2[i];
            i++;
        case 6:
            sum += array1[i] * array2[i];
            i++;
        case 5:
            sum += array1[i] * array2[i];
            i++;
        case 4:
            sum += array1[i] * array2[i];
            i++;
        case 3:
            sum += array1[i] * array2[i];
            i++;
        case 2:
            sum += array1[i] * array2[i];
            i++;
        case 1:
            sum += array1[i] * array2[i];
            i++;
        } while (--n > 0);
    }
    return sum;
}

int main()
{
    // 动态分配内存
    int *array1 = (int *)malloc(sizeof(int) * ARRAY_SIZE);
    int *array2 = (int *)malloc(sizeof(int) * ARRAY_SIZE);

    if (array1 == NULL || array2 == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // 初始化数据
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        array1[i] = 2;
        array2[i] = 3;
    }

    struct timespec start, end;
    double time_used;

    // ================= 1. 测试初始基础版本 =================
    clock_gettime(CLOCK_MONOTONIC, &start);
    int res_basic = compute_basic(array1, array2, ARRAY_SIZE);
    clock_gettime(CLOCK_MONOTONIC, &end);
    time_used = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("--- [1] Basic Version ---\n");
    printf("Result: %d | Time: %f seconds\n\n", res_basic, time_used);

    // ================= 2. 测试普通 8 路展开 =================
    clock_gettime(CLOCK_MONOTONIC, &start);
    int res_unroll = compute_unroll8(array1, array2, ARRAY_SIZE);
    clock_gettime(CLOCK_MONOTONIC, &end);
    time_used = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("--- [2] Standard Unroll (8-way) ---\n");
    printf("Result: %d | Time: %f seconds\n\n", res_unroll, time_used);

    // ================= 3. 测试 Duff's Device =================
    clock_gettime(CLOCK_MONOTONIC, &start);
    int res_duff = compute_duff(array1, array2, ARRAY_SIZE);
    clock_gettime(CLOCK_MONOTONIC, &end);
    time_used = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("--- [3] Duff's Device ---\n");
    printf("Result: %d | Time: %f seconds\n\n", res_duff, time_used);

    free(array1);
    free(array2);
    return 0;
}