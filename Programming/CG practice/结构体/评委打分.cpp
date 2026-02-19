#include<bits/stdc++.h>
using namespace std;
class Player{
	private:
		string name;
		vector<int>score;//类内不能直接初始化成员 
	public:
		Player(){
			score.resize(8);
		}
		void input(){
			cin>>name;
			for(int i=1;i<=7;i++) cin>>score[i]; 
		}	
		int getScore() const{
			int sum=0,mi=101,ma=-1;
			for(int i=1;i<=7;i++){
				sum+=score[i];
				mi=min(mi,score[i]);
				ma=max(ma,score[i]);
			}
			return sum-mi-ma;
		}
		void output(){
			cout<<name<<" "<<getScore()<<endl;
			
		}
		bool operator<(const Player &other) const {
			return getScore()>other.getScore();
		}
}; 
int main() {
	int n;
	cin>>n; 
	vector<Player>p(n);
	for(int i=0;i<n;i++) p[i].input();
	sort(p.begin(),p.end());
	for(int i=0;i<n;i++) p[i].output();
	return 0;
}
