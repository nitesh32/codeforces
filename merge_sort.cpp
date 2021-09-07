#include<bits/stdc++.h>
using namespace std;
long long n,i;
string s;
typedef long long ll;
#define nit( i, n) for(i=0;i<n;i++)
/*--------------------------------------------------------------------------------*/
int gcd(int a,int b){ if(b==0) return a; else return gcd(b,a%b);}
bool iseven(int n){return ((n&1)==0)?true:false;}
int pov(int n,int m){ int c=1;  while(m>0){  if(!iseven(m)){ c=c*n; } n=n*n; m=m>>1;  }  return c; }
unsigned int intlen(unsigned int n){return n ? intlen(n/10)+1 : 0;}
bool isprime(int x) { for (int d = 2; d * d <= x; d++) { if (x % d == 0) return false; }return true; }
/*-------------------------------------------------------------------------------*/
void printarr(ll arr[],ll n){nit(i,n)cout<<arr[i]<<" ";cout<<endl; }
void printmap(map<ll,ll> mp){for(auto val:mp)cout<<val.first<<" "<<val.second<<endl;}
void printvec(vector<ll> vec){for(auto val:vec)cout<<val<<" ";cout<<endl;}
void printset(set<ll> st){for(auto val:st)cout<<val<<" ";cout<<endl;}
/*-------------------------------------------------------------------------------*/
int arr[] = {38,27,43,3,9,82,10};
void mergesort(int l,int r,int mid){
    int l_sz = mid - l + 1;
    int L[l_sz+1];
    int r_sz = r - mid;
    int R[r_sz+1];
    for(int i=0;i<l_sz;i++){
        L[i] = arr[i+l];
    }
    for(int i=0;i<r_sz;i++){
        R[i] = arr[i+mid+1];
    }
    L[l_sz]=R[r_sz]=INT_MAX;
    int l_i=0,r_i=0;
    for(int i=l;i<=r;i++){
       if(L[l_i]<=R[r_i]){
           arr[i]=L[l_i];
           l_i++;
       }
       else{
           arr[i] = R[r_i];
           r_i++;
       }
    }
}
void merge(int st,int end){
    if(st==end) return ;
    int mid = (st+end)/2;
    merge(st,mid);
    merge(mid+1,end);
    mergesort(st,end,mid);
    
}

int main(){
#ifndef ONLINE_JUDGE
freopen("ipt.txt","r",stdin);
freopen("out.txt","w",stdout);
   merge(0,6);
   for(int i=0;i<7;i++){
       cout<<arr[i]<<" ";
   }
#endif
return 0;
}