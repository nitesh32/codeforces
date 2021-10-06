#include<bits/stdc++.h>
using namespace std;

void get(int arr[][20],int n,int **sol,int row,int col){
    
     if(row==n-1&&col==n-1){
        sol[row][col]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<sol[i][j]<<" ";
            }
        }
        cout<<endl;
        return;
    }
    
    if(row<0||col<0||row>=n||col>=n||arr[row][col]==0||sol[row][col]==1){
        return;
    }
   
    sol[row][col]=1;
    get(arr,n,sol,row-1,col);
    get(arr,n,sol,row+1,col);
    get(arr,n,sol,row,col-1);
    get(arr,n,sol,row,col+1);
    sol[row][col]=0;

}
void code(int arr[][20],int n){
    int **sol = new int*[n];
    for(int i=0;i<n;i++){
        sol[i] = new int[n];
    }
    for(int i=0; i<n; i++){
    memset(sol[i], 0, n*sizeof(int));
    }

    get(arr,n,sol,0,0);
}
int main(){

    int n;
    cin>>n;
    int arr[20][20];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    code(arr,n);
}