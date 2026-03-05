#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 最小总费用 k 元 Huffman
ll solveMinCost(vector<ll> a, int n, int k) {
    // 补虚节点使 (n-1) % (k-1) == 0
    int padding = (k - 1 - (n - 1) % (k - 1)) % (k - 1);
    for (int i = 0; i < padding; i++) a.push_back(0);

    priority_queue<ll, vector<ll>, greater<ll>> pq(a.begin(), a.end());
    ll cost = 0;
    while (pq.size() > 1) {
        ll sum = 0;
        for (int i = 0; i < k; i++) {
            if (pq.empty()) break;
            sum += pq.top();
            pq.pop();
        }
        cost += sum;
        pq.push(sum);
    }
    return cost;
}

// 最大总费用，每次合并两堆
ll solveMaxCost(vector<ll> a) {
    priority_queue<ll> pq(a.begin(), a.end());
    ll cost = 0;
    while (pq.size() > 1) {
        ll x = pq.top(); pq.pop();
        ll y = pq.top(); pq.pop();
        ll sum = x + y;
        cost += sum;
        pq.push(sum);
    }
    return cost;
}

int main() {
     ifstream fin("D:\\Core Course\\The design and annlysis of algorithm\\Homework\\The forth work\\input4-14.txt");
    ofstream fout("D:\\Core Course\\The design and annlysis of algorithm\\Homework\\The forth work\\output4-14.txt");
    int n, k;
    fin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) fin >> a[i];

    ll minCost = solveMinCost(a, n, k);
    ll maxCost = solveMaxCost(a);

    fout << minCost << " " << maxCost << "\n";

    return 0;
}

