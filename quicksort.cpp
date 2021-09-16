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
ll partiation(ll *arr,ll l,ll h){
    ll k = arr[l];
    ll i=l,j=h;
    while(i<=j){
        while(arr[i]<=k) i++;
        while(arr[j]>k) j--;
        if(i<j) {swap(arr[i],arr[j]);}
    }
    swap(arr[j],arr[l]);
    return j;
}
void quick(ll *arr,ll l,ll h){
    if(l<h){
        ll pivot = partiation(arr,l,h);
        quick(arr,l,pivot-1);
        quick(arr,pivot+1,h);
    }
}
int main(){
#ifndef ONLINE_JUDGE
freopen("ipt.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif
    cin>>n;
    ll arr[n];
    nit(i,n){
        cin>>arr[i];
    }
    quick(arr,0,n-1);
    printarr(arr,n);
  
return 0;
}