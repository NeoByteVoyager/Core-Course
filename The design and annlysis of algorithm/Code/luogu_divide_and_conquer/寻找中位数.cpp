#include<bits/stdc++.h>
using namespace std;
int f(vector<int>&nums1,vector<int>&nums2,int t){
        int l1=nums1.size(),l2=nums2.size();
        int l=0,r=l1-1;
        while(l<=r){
            int mid=(l+r)/2;
            auto a=lower_bound(nums2.begin(),nums2.end(),nums1[mid]);
            auto b=upper_bound(nums2.begin(),nums2.end(),nums1[mid]);
            int t1=a-nums2.begin(),t2=b-nums2.begin();
            int e1=t1+mid+2,e2=t2-1+mid+2;
            if(t>=e1&&t<=e2) return nums1[mid];
            else if(t<e1){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        swap(nums1,nums2);
        l1=nums1.size(),l2=nums2.size();
        l=0,r=l1-1;
        while(l<=r){
            int mid=(l+r)/2;
            auto a=lower_bound(nums2.begin(),nums2.end(),nums1[mid]);
            auto b=upper_bound(nums2.begin(),nums2.end(),nums1[mid]);
            int t1=a-nums2.begin(),t2=b-nums2.begin();
            int e1=t1+mid+2,e2=t2-1+mid+2;
            if(t>=e1&&t<=e2) return nums1[mid];
            else if(t<e1){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return 0;
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1=nums1.size(),l2=nums2.size();
        int t1,t2;
        if((l1+l2)%2){
            t2=t1=(l1+l2+1)/2;
        }
        else {
            t1=(l1+l2)/2;
            t2=t1+1;
        }
        int res1=f(nums1,nums2,t1);
        cout<<res1;
        int res2=f(nums1,nums2,t2);
        cout<<res2; 
        int res=(double)(res1+res2)/2.0;
        return res;
    }
int main(){
	vector<int>a={0,1};
	vector<int>b={2,3};
	double res=findMedianSortedArrays(a,b);
	return 0;
} 
