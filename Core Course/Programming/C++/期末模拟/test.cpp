#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        string t=to_string(x);
        std::reverse(t.begin(),t.end());
        return stoi(t);
    }
};
int main(){
	Solution s;
	cout<<s.reverse(12);
	return 0;
}
