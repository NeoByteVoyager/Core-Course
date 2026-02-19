#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
int a[MAXN], b[MAXN];

void merge_sort(int l, int m, int r){
    int k = l, i = l, j = m + 1;
    while(i <= m && j <= r){
        if(a[i] <= a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
    }
    while(i <= m) b[k++] = a[i++];
    while(j <= r) b[k++] = a[j++];
    for(int p = l; p <= r; ++p) a[p] = b[p];
}

void mergesort(int l, int r){
    if(l >= r) return;
    int m = l + (r - l) / 2;
    mergesort(l, m);
    mergesort(m + 1, r);
    merge_sort(l, m, r);
}

int main(){
    freopen("data3.txt","r",stdin);
    freopen("myres.txt","w",stdout);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    clock_t start = clock();
    mergesort(0, n - 1);
    clock_t end = clock();

    for(int i = 0; i < n; i++) cout << a[i] << " ";
    fclose(stdout);
    fclose(stdin);

    freopen("CON", "w", stdout); // 恢复控制台输出
    cout << "排序已结束\n";
    cout<<"data size:"<<n<<endl; 
    cout << fixed << setprecision(12)
         << "运行时间: " << double(end - start) / CLOCKS_PER_SEC << " 秒" << endl;

    return 0;
}

