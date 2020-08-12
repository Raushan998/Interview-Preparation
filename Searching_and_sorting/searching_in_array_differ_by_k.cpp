#include<bits/stdc++.h>
using namespace std;
int search(int* arr,int k,int x,int n){
    int i=0;
    while(i<n){
        if(arr[i]==x)
           return i;
        i=i+max(1,abs(arr[i]-x)/k);
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int* arr=new int[n];
    for(int i=0;i<n;i++)
       cin>>arr[i];
    int x,k;
    cin>>x>>k;
    cout<<search(arr,k,x,n)<<endl;
    return 0;
}