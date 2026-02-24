#include<bits/stdc++.h>
using namespace std;
template <typename T>
class Stack{
	private:
		T *a;
		int cap;
		int topIndex=-1;
		void expand(){
			T*newarr=new T[cap*2];
			for(int i=0;i<topIndex;i++){
				newarr[i]=a[i];
			}
			delete[] a;
			a=newarr;
		}
	public:
		Stack():cap(10),topIndex(-1){
			a=new T[cap];
		}
		void push(T x){
			if (topIndex + 1 == cap) expand();
			
			a[++topIndex]=x; 
		}
		T top(){
			return a[topIndex];
		}
		T pop(){
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
	Stack<string>st;
	string x;
	for(int i=1;i<=3;i++){
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
