#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    struct node{
        int data;
        struct node *next;
    };
    struct node *head,*temp,*newnode,*zemp;
    head = 0 ;
    int k=1;
    map<ll,ll> mp;
    while(k){
        newnode = (struct node*)new int[sizeof(struct node)];
        cout<<"enter data : ";
        cin>>newnode->data;
        mp[newnode->data]++;
        newnode->next=0;
        if(head ==0){
            head = newnode;
            temp = newnode;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }
        cout<<"enter 1 to continue or 0 to break :  ";
        cin>>k;
    }
    cout<<"item"<<" "<<"occurance"<<endl;
    for(auto val : mp){
        cout<<val.first<<" "<<val.second<<endl;
    }
return 0;
}