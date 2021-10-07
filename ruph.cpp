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
bool check(int arr[9][9],int row,int col,int val){
   for(int i=0;i<9;i++){
       if(arr[i][col]==val){
           return false;
       }
   }  
   for(int i=0;i<9;i++){
       if(arr[row][i]==val){
           return false;
       }
   } 
   int r = row-(row%3);
   int c = col-(col%3);
   for(int i=0;i<3;i++){
       for(int j=0;j<3;j++){
           if(arr[i+r][j+c]==val){
               return false;
           }
       }
   } 
   return true;
}
bool isblank(int arr[9][9],int &row,int &col){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(arr[i][j]==0){
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}
bool get(int arr[9][9]){
    int row,col;
    if(!isblank(arr,row,col)){
        return true;
    }
    for(int i=1;i<=9;i++){
        if(check(arr,row,col,i)){
            arr[row][col]=i;
            if(get(arr)){
                return true;
            }
            arr[row][col]=0;
        }

    }
    return false;
}
int main(){
#ifndef ONLINE_JUDGE
freopen("ipt.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif
    int arr[9][9];
    for(int i=0;i<9;i++){
        cin>>s;
        for(int j=0;j<9;j++){
            arr[i][j]=s[j]-'0';
        }
    }
    get(arr);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
return 0;
}