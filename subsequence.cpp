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
ll solve(string s,string arr[]){
    if(s.empty()){
        arr[0] = "";
        return 1;
    }
    string choti = s.substr(1);
    ll kize = solve(choti,arr);
    for(int i=0;i<kize;i++){
        arr[i+kize] = s[0] + arr[i];
    }
    return 2*kize;
}
int main(){
#ifndef ONLINE_JUDGE
freopen("ipt.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif
    cin>>s;
    n = s.size();
    string arr[pov(2,n)+1];
    ll subsize = solve(s,arr);
    for(int i =0 ;i<subsize;i++){
        cout<<arr[i]<<endl;
    }
return 0;
}