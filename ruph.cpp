#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    ll arr[] = {7, 1, 4, 12, 67, 33, 45};
    ll n = 7;
    ll count =0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if (arr[j] > arr[j+1]){
                count++;
            swap(arr[j], arr[j+1]); 
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"number of swaps required : "<<count;
return 0;
}