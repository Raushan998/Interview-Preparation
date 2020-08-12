#include<bits/stdc++.h>
using namespace std;
int MinCost(int* arr,int i,int k,int n,int cost){
    
}
int main(){
    int n;
    cin>>n;
    int* arr=new int[n];
    for(int i=0;i<n;i++)
       cin>>arr[i];
    int k,cost;
    cin>>k>>cost;
    cout<<MinCost(arr,0,k,n,cost)<<endl;
}