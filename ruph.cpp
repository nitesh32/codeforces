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
void printvec(vector<ll> vec){for(auto val:vec)cout<<val<<endl;cout<<endl;}
void printset(set<ll> st){for(auto val:st)cout<<val<<" ";cout<<endl;}
/*-------------------------------------------------------------------------------*/

vector<ll> vec;
void printArray(vector<ll> arr, ll n,ll num)
{   ll sum =0;
    const unsigned int M = 1000000007;
    for (ll i = 0; i < n; i++)
        sum = (sum + pov(num,arr[i]))%M;
    vec.push_back(sum);
}
 
void printSubsequences(vector<ll> arr, ll index,
                       vector<ll> subarr,ll num)
{
   
    if (index == arr.size())
    {
        ll l = subarr.size();
 
        if (l != 0)
            printArray(subarr, l,num);
    }
    else
    {
        
        printSubsequences(arr, index + 1, subarr,num);
 
        subarr.push_back(arr[index]);
 
        printSubsequences(arr, index + 1, subarr,num);
    }
    return;
}

int main(){
#ifndef ONLINE_JUDGE
freopen("ipt.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif
   ll t;
   cin>>t;
   while(t--){
       ll k;
       cin>>n>>k;
       ll num;
       for(int i=1;i<k;i++){
           if(pov(2,i)-1>=k){
               num =i;
               break;
           }
       }
       vector<ll> arr,brr;
       for(int i=0;i<num;i++){
           arr.push_back(i);
       }
       printSubsequences(arr,0,brr,n);
       sort(vec.begin(),vec.end());
       printvec(vec);

   }
return 0;
}