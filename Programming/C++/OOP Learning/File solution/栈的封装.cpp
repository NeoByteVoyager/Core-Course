#include<bits/stdc++.h>
using namespace std;
class Stack{
	private:
		vector<int>a;
		int topIndex;
	public:
	
		Stack(){
			topIndex=-1;
		}
		void push(int x){
			a.push_back(x);
			topIndex++; 
		}
		int top(){
			return a[topIndex];
		}
		int pop(){
			return a[topIndex--];
		}
		int size(){
			return topIndex+1;
		}
		bool empty(){
			return topIndex==-1;
		}
};
int main(){
	Stack st;
	int x;
	for(int i=1;i<=5;i++){
		cin>>x;
		st.push(x); 
	}
//	cout<<st.topIndex;
	int n=st.size();
	cout<<n<<endl;
	for(int i=1;i<=n;i++){
		cout<<st.top()<<" ";
		st.pop();
	}
	return 0;
} 
