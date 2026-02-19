#include <bits/stdc++.h>
using namespace std;

// 计算组合数 C(n,k)
long long C(int n, int k){
    long long res = 1;
    for(int i=1;i<=k;i++){
        res = res*(n-i+1)/i;
    }
    return res;
}

long long bellNumber(int n){
    vector<long long> B(n+1,0);
    B[0] = 1;  // B0 = 1
    for(int i=1;i<=n;i++){
        B[i] = 0;
        for(int k=0;k<i;k++){
            B[i] += C(i-1,k)*B[k];
        }
    }
    return B[n];
}

int main(){
    ifstream fin("input.txt");
    int n;
    fin >> n;
    fin.close();

    long long result = bellNumber(n);

    ofstream fout("output.txt");
    fout << result << endl;
    fout.close();

    return 0;
}

