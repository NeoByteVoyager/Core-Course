#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int k;
    if (!(fin >> k)) return 0;

    vector<pair<int, int>> events;   // first: 时间，second: +1 或 -1
    events.reserve(2 * k);
    for (int i = 0; i < k; ++i) {
        int s, e;
        fin >> s >> e;
        events.emplace_back(s, +1);
        events.emplace_back(e, -1);
    }

    // 排序规则：时间相同则结束事件优先处理（-1 排在 +1 前面）
    sort(events.begin(), events.end(), [](const auto &a, const auto &b) {
        return a.first < b.first || (a.first == b.first && a.second < b.second);
    });

    int cur = 0, max_halls = 0;
    for (auto &[time, type] : events) {
        cur += type;
        max_halls = max(max_halls, cur);
    }

    fout << max_halls << '\n';
    return 0;
}
