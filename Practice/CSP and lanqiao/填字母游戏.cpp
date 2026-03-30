#include <iostream>
using namespace std;

int is_end(string s,int flag);
int MAX(string s);
int MIN(string s);
int getbest(string s);


int main()
{
    // 请在此输入您的代码
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        cout<<getbest(s)<<endl;
    }
    return 0;
}

int is_end(string s,int flag){
    cout<<s<<endl;
    if(s.find("LOL")!=string::npos){
        if(flag==1) return 1; //小明胜利
        else return -1; //大师胜利
    }
    for(char c:s){
        if(c=='*') return -2; //没有结束
    }
    return 0; //平局
}
int MAX(string s){
    int res=is_end(s,1);
    if(res!=-2){  //结束
        return res; 
    }
    int v=-2;
    for(int i=0;i<s.size();i++){
        if(s[i]!='*') continue;
        string ss=s;
        ss[i]='L';
        v=max(v,MIN(ss));
        ss[i]='O';
        v=max(v,MIN(ss));
    }
    return v;
}
int MIN(string s){
    int res=is_end(s,-1);
    if(res!=-2){  //结束
        return res; 
    }
    int v=2;
    for(int i=0;i<s.size();i++){
        if(s[i]!='*') continue;
        string ss=s;
        ss[i]='L';
        v=min(v,MAX(ss));
        ss[i]='O';
        v=min(v,MAX(ss));
    }
    return v;
}
int getbest(string s){
    return MAX(s);
}
