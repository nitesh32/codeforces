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
void merge(ll *arr,ll st,ll end){
   
    ll mid = (((st+end)/2)+1);
     ll i = st,j = mid;
     ll output[end-st+1];
     ll k=0;
    while(i<mid&&j<=end){
        if(arr[i]<=arr[j]){
            output[k++] = arr[i++];
        }
        else{
            output[k++] = arr[j++];
        }
    }
    while(i<mid){
        output[k++] = arr[i++];
    }
    while(j<=end){
        output[k++] = arr[j++];
    }
    k=0;
    for(int i=st;i<=end;i++){
       arr[i]=output[k++];
    }
    

}
void merge_sort(ll arr[],ll st,ll end){
    if(st>=end) return ;
    ll mid = (st+end)/2;
    merge_sort(arr,st,mid);
    merge_sort(arr,mid+1,end);
    merge(arr,st,end);
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
    merge_sort(arr,0,n);
    printarr(arr,n);
return 0;
}