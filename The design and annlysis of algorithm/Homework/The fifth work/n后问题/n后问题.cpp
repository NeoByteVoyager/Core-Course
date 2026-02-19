#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int level;     // 已放置的皇后数量（对应处理到第level行）
  vector<int> x; // 解向量：x[i]表示第i行皇后的列位置（1~n）
};

// 判断第level行放置第i列是否合法
bool ok(int level, int i, vector<int> x)
{
  for (int j = 1; j < level; j++)
  {
    if (x[j] == i)
      return false;                // 同列冲突
    int row_diff = abs(j - level); // 行差绝对值
    int col_diff = abs(x[j] - i);  // 列差绝对值
    if (row_diff == col_diff)
      return false; // 对角线冲突
  }
  return true;
}

// BFS求解n皇后，返回第一个合法解（无解返回空向量）
vector<int> solve(int n)
{
  Node node;
  node.level = 0;
  node.x.push_back(0); // x[0]占位，x[1~n]为有效解
  queue<Node> q;
  q.push(node);

  while (!q.empty())
  {
    Node u = q.front();
    q.pop();

    if (u.level == n)
    { // 找到完整可行解
      return u.x;
    }

    // 尝试在第u.level+1行放置第i列
    for (int i = 1; i <= n; i++)
    {
      if (ok(u.level + 1, i, u.x))
      {
        Node v = u;
        v.x.push_back(i);
        v.level++;
        q.push(v);
      }
    }
  }
  return {}; // 无合法解返回空
}

int main()
{
  int n;
  cin >> n;
  vector<int> res = solve(n);

  if (res.empty())
  {
    cout << "该n值不存在n皇后合法解" << endl;
  }
  else
  {
    cout << "n皇后合法解（第i行对应第res[i]列）：" << endl;
    for (int i = 1; i <= n; i++)
    {
      cout << res[i] << " ";
    }
  }
  return 0;
}
