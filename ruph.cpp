#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(ll num,ll k){
    ll sum = 0;
    ll n = num;
    while(n>0){
        sum += min(n,k);
        n = n - k;
        n = n - (n/10); 
    }
    if(sum*2>=num){
        return true;
    }
    return false;
}
ll search(ll n,ll st,ll ed){
    if(st<=ed){
        ll mid = (st+ed)/2;
        if(check(n,mid)){
            ll k = min(search(n,st,mid-1),mid);
            return k;
        }
        else{
            return search(n,mid+1,ed);
        }
        
        
    }
}
int main(){
#ifndef ONLINE_JUDGE
freopen("ipt.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<search(n,1,n)<<endl;
    }
    
    return 0;
}
//402
//228
//37