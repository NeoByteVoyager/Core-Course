# include <iostream>
using namespace std;
typedef long long int ll;
ll getMod(ll a, ll b, ll p);
int main()
{
    ll a, b, p;
    cin>>a>>b>>p;
    ll ans=getMod(a,b,p);
    ans=ans%p;
    cout<<ans<<endl;

    return 0;
}

ll getMod(ll a, ll b, ll p)
{
	if(b==1){
		return a%p;
	} 
	if(b==0)
		return 1;
	int m=b/2;
	return getMod(a,m,p)*getMod(a,b-m,p)%p;
}
