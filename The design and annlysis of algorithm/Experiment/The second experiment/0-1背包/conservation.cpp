#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("knapPI_1_500_1000_1_items.csv");
	ofstream fout("input.txt"); 
    string line;
    getline(fin, line);  // 跳过表头

    vector<int> w, v;

    while (getline(fin, line)) {
        stringstream ss(line);
        string item, price, weight, sol;

        getline(ss, item, ',');
        getline(ss, price, ',');
        getline(ss, weight, ',');
        getline(ss, sol, ',');

        v.push_back(stoi(price));
        w.push_back(stoi(weight));
    }
	
	fout<<500<<" "<<1000<<endl;
    // 测试输出
    for (int i = 0; i < v.size(); i++) {
        fout << v[i] << " " ;
    }
    cout<<endl;
     for (int i = 0; i < v.size(); i++) {
        fout << w[i] << " " ;
    }
}





