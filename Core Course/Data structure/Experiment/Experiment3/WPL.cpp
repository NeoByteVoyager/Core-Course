#include <bits/stdc++.h>
using namespace std;
int n;
const int MAXN = 1e4 + 10;
int a[MAXN];
long long WPL()
{
    long long cost = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
        pq.push(a[i]);
    for (int i = 0; i < n - 1; i++)
    {
        int u = pq.top();
        pq.pop();
        int v = pq.top();
        pq.pop();
        int sum = u + v;
        cost += sum;
        pq.push(sum);
    }
    return cost;
}
int main()
{

    while (cin >> n)
    {
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << WPL() << endl;
    }

    return 0;
}