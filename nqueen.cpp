#include<bits/stdc++.h>
using namespace std;
int arr[11][11];
bool isposs(int n,int row,int col){
    for(int i = row-1,j=col;i>=0;i--){
        if(arr[i][j]==1){
            return false;
        }
    }
    for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
        if(arr[i][j]==1){
            return false;
        }
    }
    for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
        if(arr[i][j]==1){
            return false;
        }
    }
    return true;
}
void queenhelper(int n,int row){
    if(row == n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
        }
        cout<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(isposs(n,row,i)){
            arr[row][i]=1;
            queenhelper(n,row+1);
            arr[row][i]=0;
        }
    }
    return;
}
void nqueen(int n){
    queenhelper(n,0);
    return;
}
int main(){
    int n;
    cin>>n;
    nqueen(n);
    return 0;
}