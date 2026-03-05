#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

// 网格坐标结构体
struct Grid {
    int x;
    int y;
};

// 全局变量
int m, n;
std::vector<std::vector<Grid>> link;
std::vector<Grid> b66;
std::vector<Grid> b68;
std::vector<Grid> b86;
std::vector<Grid> b88;
std::vector<Grid> b810;
std::vector<Grid> b108;
std::vector<Grid> b1010;
std::vector<Grid> b1012;
std::vector<Grid> b1210;

// 函数声明
void knight(int mm, int nn);
void out();
void change(int m, int n, const std::vector<std::vector<int>>& a, std::vector<Grid>& b);
bool comb(int mm, int nn, int offx, int offy);
bool odd(int x);
void base_answer(int mm, int nn, int offx, int offy);
void build(int m, int n, int offx, int offy, int col, const std::vector<Grid>& b);
int pos(int x, int y, int col);

// 主函数
int main() {
    std::ifstream fin("input.txt");
    if (!fin.is_open()) {
        std::cerr << "无法打开input.txt文件" << std::endl;
        return 1;
    }
    fin >> m >> n;
    fin.close();

    knight(m, n);
    out();

    return 0;
}

// 初始化基础解并构建棋盘
void knight(int mm, int nn) {
    int i, j;
    m = mm;
    n = nn;

    // 初始化基础解向量
    b66.resize(36);
    b68.resize(48);
    b86.resize(48);
    b88.resize(64);
    b810.resize(80);
    b108.resize(80);
    b1010.resize(100);
    b1012.resize(120);
    b1210.resize(120);

    // 初始化link二维数组
    link.resize(m);
    for (i = 0; i < m; i++) {
        link[i].resize(n);
    }

    // 临时数组用于读取基础解
    std::vector<std::vector<int>> a(12, std::vector<int>(14, 0));

    // 6x6 基础解
    const std::vector<std::vector<int>> a66 = {
        {1, 30, 33, 16, 3, 24},
        {32, 17, 2, 23, 34, 15},
        {29, 36, 31, 14, 25, 4},
        {18, 9, 6, 35, 22, 13},
        {7, 28, 11, 20, 5, 26},
        {10, 19, 8, 27, 12, 21}
    };
    for (i = 0; i < 6; i++)
        for (j = 0; j < 6; j++)
            a[i][j] = a66[i][j];
    change(6, 6, a, b66);

    // 6x8 基础解
    const std::vector<std::vector<int>> a68 = {
        {1, 10, 31, 40, 21, 14, 29, 38},
        {32, 41, 2, 11, 30, 39, 22, 13},
        {9, 48, 33, 20, 15, 12, 37, 28},
        {42, 3, 44, 47, 6, 25, 18, 23},
        {45, 8, 5, 34, 19, 16, 27, 36},
        {4, 43, 46, 7, 26, 35, 24, 17}
    };
    for (i = 0; i < 6; i++)
        for (j = 0; j < 8; j++)
            a[i][j] = a68[i][j];
    change(6, 8, a, b68);
    change(8, 6, a, b86); // 转置得到8x6

    // 8x8 基础解
    const std::vector<std::vector<int>> a88 = {
        {1, 46, 17, 50, 3, 6, 31, 52},
        {18, 49, 2, 7, 30, 51, 56, 5},
        {45, 64, 47, 16, 27, 4, 53, 32},
        {48, 19, 8, 29, 10, 55, 26, 57},
        {63, 44, 11, 22, 15, 28, 33, 54},
        {12, 41, 20, 9, 36, 23, 58, 25},
        {43, 62, 39, 14, 21, 60, 37, 34},
        {40, 13, 42, 61, 38, 35, 24, 59}
    };
    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++)
            a[i][j] = a88[i][j];
    change(8, 8, a, b88);

    // 8x10 基础解
    const std::vector<std::vector<int>> a810 = {
        {1, 46, 37, 66, 3, 48, 35, 68, 5, 8},
        {38, 65, 2, 47, 36, 67, 4, 7, 34, 69},
        {45, 80, 39, 24, 49, 18, 31, 52, 9, 6},
        {64, 23, 44, 21, 30, 15, 50, 19, 70, 33},
        {79, 40, 25, 14, 17, 20, 53, 32, 51, 10},
        {26, 63, 22, 43, 54, 29, 16, 73, 58, 71},
        {41, 78, 61, 28, 13, 76, 59, 56, 11, 74},
        {62, 27, 42, 77, 60, 55, 12, 75, 72, 57}
    };
    for (i = 0; i < 8; i++)
        for (j = 0; j < 10; j++)
            a[i][j] = a810[i][j];
    change(8, 10, a, b810);
    change(10, 8, a, b108); // 转置得到10x8

    // 10x10 基础解
    const std::vector<std::vector<int>> a1010 = {
        {1, 54, 69, 66, 3, 56, 39, 64, 5, 8},
        {68, 71, 2, 55, 38, 65, 4, 7, 88, 63},
        {53, 100, 67, 70, 57, 26, 35, 40, 9, 6},
        {72, 75, 52, 27, 42, 37, 58, 87, 62, 89},
        {99, 30, 73, 44, 25, 34, 41, 36, 59, 10},
        {74, 51, 76, 31, 28, 43, 86, 81, 90, 61},
        {77, 98, 29, 24, 45, 80, 33, 60, 11, 92},
        {50, 23, 48, 79, 32, 85, 82, 91, 14, 17},
        {97, 78, 21, 84, 95, 46, 19, 16, 93, 12},
        {22, 49, 96, 47, 20, 83, 94, 13, 18, 15}
    };
    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
            a[i][j] = a1010[i][j];
    change(10, 10, a, b1010);

    // 10x12 基础解
    const std::vector<std::vector<int>> a1012 = {
        {1, 4, 119, 100, 65, 6, 69, 102, 71, 8, 75, 104},
        {118, 99, 2, 5, 68, 101, 42, 7, 28, 103, 72, 9},
        {3, 120, 97, 64, 41, 66, 25, 70, 39, 74, 105, 76},
        {98, 117, 48, 67, 62, 43, 40, 27, 60, 29, 10, 73},
        {93, 96, 63, 44, 47, 26, 61, 24, 33, 38, 77, 106},
        {116, 51, 94, 49, 20, 23, 46, 37, 30, 59, 34, 11},
        {95, 92, 115, 52, 45, 54, 21, 32, 35, 80, 107, 78},
        {114, 89, 50, 19, 22, 85, 36, 55, 58, 31, 12, 81},
        {91, 18, 87, 112, 53, 16, 57, 110, 83, 14, 79, 108},
        {88, 113, 90, 17, 86, 111, 84, 15, 56, 109, 82, 13}
    };
    for (i = 0; i < 10; i++)
        for (j = 0; j < 12; j++)
            a[i][j] = a1012[i][j];
    change(10, 12, a, b1012);
    change(12, 10, a, b1210); // 转置得到12x10
}

// 将基础解转换为网格坐标
void change(int m, int n, const std::vector<std::vector<int>>& a, std::vector<Grid>& b) {
    int i, j, total = m * n;
    if (m < n) {
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++) {
                int p = a[i][j] - 1;
                if (p >= 0 && p < total) {
                    b[p].x = i;
                    b[p].y = j;
                }
            }
    } else {
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++) {
                int p = a[i][j] - 1;
                if (p >= 0 && p < total) {
                    b[p].x = j;
                    b[p].y = i;
                }
            }
    }
}

// 分治算法主体
bool comb(int mm, int nn, int offx, int offy) {
    int mm1, mm2, nn1, nn2;
    int x[8], y[8], p[8];
    
    // 验证输入有效性
    if (odd(mm) || odd(nn) || std::abs(mm - nn) > 2 || mm < 6 || nn < 6)
        return true;
    
    // 基础解情况
    if (mm < 12 || nn < 12) {
        base_answer(mm, nn, offx, offy);
        return false;
    }
    
    // 分割棋盘
    mm1 = mm / 2;
    if (mm % 4 > 0) mm1--;
    mm2 = mm - mm1;
    
    nn1 = nn / 2;
    if (nn % 4 > 0) nn1--;
    nn2 = nn - nn1;
    
    // 递归求解四个子棋盘
    comb(mm1, nn1, offx, offy);
    comb(mm1, nn2, offx, offy + nn1);
    comb(mm2, nn1, offx + mm1, offy);
    comb(mm2, nn2, offx + mm1, offy + nn1);
    
    // 合并四个子回路
    x[0] = offx + mm1 - 1;
    y[0] = offy + nn1 - 3;
    x[1] = x[0] - 1;
    y[1] = y[0] + 2;
    x[2] = x[1] - 1;
    y[2] = y[1] + 2;
    x[3] = x[2] + 2;
    y[3] = y[2] - 1;
    x[4] = x[3] + 1;
    y[4] = y[3] + 2;
    x[5] = x[4] + 1;
    y[5] = y[4] - 2;
    x[6] = x[5] + 1;
    y[6] = y[5] - 2;
    x[7] = x[6] - 2;
    y[7] = y[6] + 1;
    
    for (int i = 0; i < 8; i++)
        p[i] = pos(x[i], y[i], n);
    
    // 重新连接边以合并回路
    for (int i = 1; i < 8; i += 2) {
        int j1 = (i + 1) % 8;
        int j2 = (i + 2) % 8;
        
        if (link[x[i]][y[i]].x == p[i - 1])
            link[x[i]][y[i]].x = p[j1];
        else
            link[x[i]][y[i]].y = p[j1];
            
        if (link[x[j1]][y[j1]].x == p[j2])
            link[x[j1]][y[j1]].x = p[i];
        else
            link[x[j1]][y[j1]].y = p[i];
    }
    
    return false;
}

// 判断奇数
bool odd(int x) {
    return (x % 2 != 0);
}

// 根据尺寸选择基础解
void base_answer(int mm, int nn, int offx, int offy) {
    if (mm == 6 && nn == 6) build(mm, nn, offx, offy, n, b66);
    else if (mm == 6 && nn == 8) build(mm, nn, offx, offy, n, b68);
    else if (mm == 8 && nn == 6) build(mm, nn, offx, offy, n, b86);
    else if (mm == 8 && nn == 8) build(mm, nn, offx, offy, n, b88);
    else if (mm == 8 && nn == 10) build(mm, nn, offx, offy, n, b810);
    else if (mm == 10 && nn == 8) build(mm, nn, offx, offy, n, b108);
    else if (mm == 10 && nn == 10) build(mm, nn, offx, offy, n, b1010);
    else if (mm == 10 && nn == 12) build(mm, nn, offx, offy, n, b1012);
    else if (mm == 12 && nn == 10) build(mm, nn, offx, offy, n, b1210);
}

// 构建子棋盘回路
void build(int m, int n, int offx, int offy, int col, const std::vector<Grid>& b) {
    int i, p, q, k = m * n;
    for (i = 0; i < k; i++) {
        int x1 = offx + b[i].x;
        int y1 = offy + b[i].y;
        int x2 = offx + b[(i + 1) % k].x;
        int y2 = offy + b[(i + 1) % k].y;
        
        // 安全检查
        if (x1 >= 0 && x1 < link.size() && y1 >= 0 && y1 < link[0].size() &&
            x2 >= 0 && x2 < link.size() && y2 >= 0 && y2 < link[0].size()) {
            p = pos(x1, y1, col);
            q = pos(x2, y2, col);
            link[x1][y1].x = q;
            link[x2][y2].y = p;
        }
    }
}

// 计算棋盘方格编号
int pos(int x, int y, int col) {
    return col * x + y;
}

// 输出结果
void out() {
    int i, j, k, x, y;
    std::vector<std::vector<int>> a(m, std::vector<int>(n, 0));
    
    // 尝试构建解
    if (comb(m, n, 0, 0)) {
        std::ofstream fout("output.txt");
        fout << "无法构建Hamilton回路" << std::endl;
        fout.close();
        return;
    }
    
    // 遍历生成的回路
    i = 0; j = 0; k = 2;
    a[0][0] = 1;
    
    std::ofstream fout("output.txt");
    
    // 第一种输出：坐标序列
    fout << "(0,0) ";
    for (int p = 1; p < m * n; p++) {
        x = link[i][j].x;
        y = link[i][j].y;
        i = x / n;
        j = x % n;
        if (a[i][j] > 0) {
            i = y / n;
            j = y % n;
        }
        a[i][j] = k++;
        fout << "(" << i << "," << j << ") ";
        if ((k - 1) % n == 0) fout << std::endl;
    }
    fout << std::endl << std::endl;
    
    // 第二种输出：步数矩阵
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++)
            fout << std::setw(4) << a[i][j];
        fout << std::endl;
    }
    
    fout.close();
}
