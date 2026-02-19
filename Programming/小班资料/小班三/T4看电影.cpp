#include <bits/stdc++.h>
using namespace std;

struct Movie {
    int id;
    int audio;
    int subtitle;
    int happy;
    int satisfied;
};

int main() {
    int n;
    cin >> n;
    vector<int> cnt(1001, 0);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cnt[x]++;
    }

    int m;
    cin >> m;
    vector<Movie> a(m + 1);
    for(int i = 1; i <= m; i++){
        a[i].id = i;
        cin >> a[i].audio;
    }
    for(int i = 1; i <= m; i++){
        cin >> a[i].subtitle;
    }

    for(int i = 1; i <= m; i++){
        a[i].happy = cnt[a[i].audio];
        a[i].satisfied = cnt[a[i].subtitle];
    }

    int maxHappy = 0;
    for(int i = 1; i <= m; i++){
        if(a[i].happy > maxHappy)
            maxHappy = a[i].happy;
    }

    int maxSatisfied = 0;
    for(int i = 1; i <= m; i++){
        if(a[i].happy == maxHappy && a[i].satisfied > maxSatisfied)
            maxSatisfied = a[i].satisfied;
    }

    if(maxHappy == 0 && maxSatisfied == 0){
        cout << "unsatisfied";
        return 0;
    }

    for(int i = 1; i <= m; i++){
        if(a[i].happy == maxHappy && a[i].satisfied == maxSatisfied)
            cout << a[i].id << " ";
    }
    return 0;
}

