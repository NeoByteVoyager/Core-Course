#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("D:\\Core Course\\The design and annlysis of algorithm\\Homework\\The forth work\\input4_1.txt");
    ofstream fout("D:\\Core Course\\The design and annlysis of algorithm\\Homework\\The forth work\\output4_1.txt");
    if (!fin) {
        cerr << "无法打开 input.txt\n";
        return 1;
    }

    int k;
    fin >> k;
    vector<pair<long long,long long>> intervals;
    intervals.reserve(k);
    for (int i = 0; i < k; ++i) {
        long long s, e;
        fin >> s >> e;
        intervals.emplace_back(s, e);
    }

    sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b){
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    });

    // min-heap 保存当前占用会场的结束时间（最早结束在堆顶）
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    int maxRooms = 0;

    for (auto &it : intervals) {
        long long s = it.first, e = it.second;
        // 如果最早结束的会场在或早于 s，则可以复用
        if (!pq.empty() && pq.top() <= s) {
            pq.pop();
        }
        pq.push(e);                 // 为当前活动占用/保留一个会场
        if ((int)pq.size() > maxRooms) maxRooms = (int)pq.size();
    }

    fout << maxRooms << '\n';
    fin.close();
    fout.close();
    return 0;
}

