#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

// 全局变量定义
int n;
string colorStr;     // 颜色字符映射
int cubes[30][6];    // 存储输入的立方体颜色索引
int solution[30][6]; // 存储最终堆叠方案（旋转后的颜色索引）

// 记录四个侧面当前已使用的颜色情况 (列索引: 0-L, 1-R, 2-F, 3-B)
// used[side][color_index]
bool used[4][30];

// 定义面的索引：0:L, 1:R, 2:F, 3:B, 4:D, 5:T
// 预定义的24种姿态（索引排列）
// 通过基准姿态旋转生成，这里采用一种通过 Top 和 Front 决定的生成逻辑
// 简化处理：实际上只需要知道 L, R, F, B, D, T 的新索引
int perms[24][6];

// 生成所有24种旋转置换
void generate_permutations()
{
  int p[6] = {0, 1, 2, 3, 4, 5}; // 初始 L, R, F, B, D, T
  int count = 0;

  // 辅助函数：绕Z轴（上下轴）旋转90度: L->B, B->R, R->F, F->L
  auto rotZ = [](int *s)
  {
    int t = s[0];
    s[0] = s[2];
    s[2] = s[1];
    s[1] = s[3];
    s[3] = t;
  };
  // 辅助函数：绕X轴（左右轴）旋转90度: F->T, T->B, B->D, D->F
  auto rotX = [](int *s)
  {
    int t = s[2];
    s[2] = s[4];
    s[4] = s[3];
    s[3] = s[5];
    s[5] = t;
  };
  // 辅助函数：绕Y轴（前后轴）旋转90度: L->T, T->R, R->D, D->L
  auto rotY = [](int *s)
  {
    int t = s[0];
    s[0] = s[4];
    s[4] = s[1];
    s[1] = s[5];
    s[5] = t;
  };

  // 也就是把立方体6个面分别作为Top，每个Top有4种侧面转法
  // 使用暴力枚举生成所有状态去重（或者简单硬编码逻辑）
  // 这里使用简单的定面逻辑：
  // Top面可以是 0,1,2,3,4,5
  // 选定Top后，选定Front（Front必须是Top的邻居）
  // 下面通过旋转操作模拟填充 perms 数组

  // 初始状态存入
  // 这里的逻辑：先生成6个面朝上，再对每个旋转4次
  int base[6] = {0, 1, 2, 3, 4, 5};

  // 6个基本朝向操作序列 (将不同面转到Top)
  // 0: Identity (T=5)
  // 1: RotX (T=2)
  // 2: RotX*2 (T=4)
  // 3: RotX*3 (T=3)
  // 4: RotY (T=1)
  // 5: RotY*3 (T=0)

  for (int i = 0; i < 6; i++)
  {
    int temp[6];
    memcpy(temp, base, sizeof(base));

    // 将第i个面转到Top (简单的硬编码转换)
    if (i == 0)
    {
      rotY(temp);
      rotY(temp);
      rotY(temp);
    } // Top=0
    else if (i == 1)
    {
      rotY(temp);
    } // Top=1
    else if (i == 2)
    {
      rotX(temp);
    } // Top=2
    else if (i == 3)
    {
      rotX(temp);
      rotX(temp);
      rotX(temp);
    } // Top=3
    else if (i == 4)
    {
      rotX(temp);
      rotX(temp);
    } // Top=4
    else if (i == 5)
    {
    } // Top=5 (Identity)

    // 对每个Top状态，绕Z轴旋转4次
    for (int j = 0; j < 4; j++)
    {
      memcpy(perms[count++], temp, sizeof(temp));
      rotZ(temp);
    }
  }
}

// 递归回溯函数
bool dfs(int layer)
{
  if (layer == n)
  {
    return true; // 找到解
  }

  // 尝试当前立方体的24种姿态
  for (int k = 0; k < 24; ++k)
  {
    // 获取当前姿态下的颜色索引
    // solution存储的是颜色ID，不是面索引
    int current_colors[6];
    for (int face = 0; face < 6; face++)
    {
      // perms[k][face] 是在该姿态下，该位置显示的是原始立方体的哪个面
      // cubes[layer][...] 获取该面的颜色
      current_colors[face] = cubes[layer][perms[k][face]];
    }

    // 检查冲突：L(0), R(1), F(2), B(3)
    // 对应数组下标: used[0]...used[3]
    bool conflict = false;
    int sides[4] = {0, 1, 2, 3}; // L, R, F, B

    for (int i = 0; i < 4; i++)
    {
      int color = current_colors[sides[i]];
      if (used[i][color])
      {
        conflict = true;
        break;
      }
    }

    if (!conflict)
    {
      // 记录颜色使用
      for (int i = 0; i < 4; i++)
        used[i][current_colors[sides[i]]] = true;
      // 记录方案
      memcpy(solution[layer], current_colors, sizeof(current_colors));

      if (dfs(layer + 1))
        return true;

      // 回溯：撤销颜色标记
      for (int i = 0; i < 4; i++)
        used[i][current_colors[sides[i]]] = false;
    }
  }
  return false;
}

int main()
{
  // 设置文件输入输出（按照题目要求）
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  cin >> n;
  cin >> colorStr;

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < 6; ++j)
    {
      cin >> cubes[i][j];
    }
  }

  // 初始化
  generate_permutations();
  memset(used, 0, sizeof(used));

  if (dfs(0))
  {
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < 6; ++j)
      {
        // 输出颜色字符
        // solution中存的是颜色索引
        // 输出格式要求：每行6个字符
        // 题目示例输出是字符，不是数字
        int colorIndex = solution[i][j];
        // 找到对应的字符
        // 注意：题目输入第2行是字符集，0对应第1个字符
        cout << colorStr[colorIndex];
      }
      cout << endl;
    }
  }
  else
  {
    cout << "No Solution!" << endl;
  }

  return 0;
}
