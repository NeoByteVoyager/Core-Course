#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("D:\\Core Course\\The design and annlysis of algorithm\\Homework\\The forth work\\input4_9.txt");
    ofstream fout("D:\\Core Course\\The design and annlysis of algorithm\\Homework\\The forth work\\output4_9.txt");
    if(!fin){
        cerr << "无法打开 input.txt\n";
        return 0;
    }

    int n, k;
    fin >> n >> k;
    vector<int> d(k + 1);
    for(int i = 0; i <= k; ++i) fin >> d[i];

    int fuel = n;      // 当前油量最大可行驶距离
    int cnt = 0;       // 加油次数

    for(int i = 0; i <= k; ++i) {
        // 若某段距离超过最大续航，则永远无法到达
        if(d[i] > n) {
            fout << "NoSolution";
            return 0;
        }
        // 检查油量够不够到下一个加油站 / 目的地
        if(d[i] > fuel) {
            // 需要在前一站加油
            cnt++;
            fuel = n;      // 加满油
        }
        fuel -= d[i];      // 开往下一个位置
    }

    fout << cnt;
    return 0;
}

