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

ll binery_s(ll arr[],ll st,ll ed,ll num){
    if(st<=ed){
        ll mid = (st+ed)/2;
        if(arr[mid]==num) return mid+1;
        else if(arr[mid]<num) binery_s(arr,mid+1,ed,num);
        else if(arr[mid]>num) binery_s(arr,st,mid-1,num);
    }
    else return -1;
}
int main(){
#ifndef ONLINE_JUDGE
freopen("ipt.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif
    cin>>n;
    ll arr[n];
    nit(i,n) cin>>arr[i];
    ll num ;cin>>num;
    ll k=binery_s(arr,0,n-1,num);
    cout<<k;
return 0;
}