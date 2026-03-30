#include <bits/stdc++.h>
using namespace std;
deque<char>A,B;
vector<char>st;
void init(string sA,string sB){
    for(char c:sA) A.push_back(c);
    for(char c:sB) B.push_back(c);
}

bool win(int flag){
    int n=st.size();
    char c=st[n-1];
    int i=0;
    while(i<n-1) {
        if(st[i]==c) break;
        i++;
    }
    if(i==n-1) return false;//没有赢
    while(st.size()>=i+1){
        char c=st[st.size()-1];
        st.pop_back();
        if(flag==1) A.push_back(c);
        else B.push_back(c); 
    }
    return true;
}



void run(){
    int flag=1;
    while(!A.empty()&&!B.empty()){
        if(flag==1){ //a出牌
            char c=A.front();
            A.pop_front();
            st.push_back(c);
            if(win(flag)) continue;
            else flag=-flag;
        }
        else{ //b出牌
            char c=B.front();
            B.pop_front();
            st.push_back(c);
            if(win(flag)) continue;
            else flag=-flag;
        }
    }
}

void out(){
    if(A.empty()){
        while(!B.empty()){
            cout<<B.front();
            B.pop_front();
        }
    }
    else{
        while(!A.empty()){
            cout<<A.front();
            A.pop_front();
        }
    }
}
int main()
{
    // 请在此输入您的代码
//    string As,Bs;
//    cin>>As>>Bs;
//    init(As,Bs);
//    run();
//    out();
    string s="01";
	cout<<stoi(s); 
	return 0;
}
