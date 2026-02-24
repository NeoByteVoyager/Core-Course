#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> price(n);
    for(int i = 0; i < n; i++) cin >> price[i];

    int min_diff = INT_MAX;
    for(int i = 1; i < n; i++){
        int diff = abs(price[i] - price[i-1]);
        if(diff < min_diff) min_diff = diff;
    }

    cout << min_diff << endl;
    return 0;
}

