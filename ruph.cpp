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
int main(){
#ifndef ONLINE_JUDGE
freopen("ipt.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif
    ll t;
    cin>>t;
    while(t--){
        cin>>n>>s;
        ll arr[n],brr[n];
        ll ind =0;
        nit(i,n){
            if(s[i]=='1'){
            ind = i+1;
            }
            arr[i] = ind;
        }
        ind =0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                ind = i+1;
            }
            brr[i]=ind;
        }
        ll count=0;
        nit(i,n){
            ll u=i+1;
            if(s[i]=='0'){
                if(arr[i]==0&&brr[i]!=0){
                    //cout<<(brr[i]-u)<<endl;
                    count += abs(brr[i]-u);
                }
                else if(brr[i]==0&&arr[i]!=0){
                    //cout<<abs(u-arr[i])<<endl;
                    count += abs(u-arr[i]);
                }
                else if(brr[i]==arr[i]){
                      //cout<<abs(u-arr[i])<<endl;
                      count += abs(u-arr[i]);
                }
                else{
                    //count += min(abs(u-arr[i])<<" "<<abs(brr[i]-u)<<endl;
                    count += min(abs(u-arr[i]),abs(brr[i]-u));
                }
                
            }
        }
        cout<<count<<endl;
    }
return 0;
}