#include <bits/stdc++.h>
using namespace std;

const int N = 1000000; // 英文小说词汇量大
int tr[N][26], cnt[N], idx;

struct Item
{
    string s;
    int count;
};
vector<Item> v;

// 插入字典树
void insert(const string &s)
{
    int p = 0;
    for (char ch : s)
    {
        int c = ch - 'a';
        if (!tr[p][c])
            tr[p][c] = ++idx;
        p = tr[p][c];
    }
    cnt[p]++;
}

void dfs(int p, string t)
{
    if (cnt[p])
    {
        v.push_back({t, cnt[p]});
    }
    for (int i = 0; i < 26; i++)
    {
        if (tr[p][i])
        {
            dfs(tr[p][i], t + (char)(i + 'a'));
        }
    }
}

int main()
{
    // 1. 处理文件输入
    ifstream fin("in.txt");
    if (!fin)
        return 0;

    string word = "";
    char ch;
    while (fin.get(ch))
    { // 逐字符读取，处理非字母分隔符
        if (isalpha(ch))
        {
            word += tolower(ch); // 转换为小写
        }
        else
        {
            if (!word.empty())
            {
                insert(word);
                word = "";
            }
        }
    }
    if (!word.empty())
        insert(word); // 处理最后一个单词

    // 2. 提取数据
    dfs(0, "");

    // 3. 排序
    sort(v.begin(), v.end(), [](const Item &a, const Item &b)
         {
        if (a.count != b.count) return a.count > b.count;
        return a.s < b.s; });

    // 4. 输出前100个
    int limit = min((int)v.size(), 100);
    for (int i = 0; i < limit; i++)
    {
        cout << v[i].s << " " << v[i].count << endl;
    }

    return 0;
}