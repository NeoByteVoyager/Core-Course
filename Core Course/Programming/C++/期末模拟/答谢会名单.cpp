#include<bits/stdc++.h>
using namespace std;
struct Person{
	string name;
	float y;
	string date;
}; 
int main(){
	vector<Person>a;
	string n;
	while(cin>>n){
		if(n=="end") break;
		float y;
		string date;
		cin>>y>>date;
		a.push_back({n,y,date});
	}
	sort(a.begin(),a.end(),[](Person &x,Person&z){
		if(x.y!=z.y) return x.y>z.y;
		else if(x.date!=z.date) return x.date<z.date;
		return x.name<z.name;
	});
	for(Person p:a){
		cout<<p.name<<endl;
	}
	return 0;
} 
