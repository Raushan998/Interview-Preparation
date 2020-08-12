#include<bits/stdc++.h>
using namespace std;
int floor(int* arr,int n,int x){
    int start=0,end=n-1,element=INT_MIN;
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]<=x){
            element=max(element,arr[mid]);
            start=mid+1;
        }
        else
           end=mid-1;
    }
    return element;
}
int Ceil(int* arr,int n,int x){
    int start=0,end=n-1,element=INT_MAX;
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]>=x){
           element=min(element,arr[mid]);
           end=mid-1;
        }
        else
           start=mid+1;
    }
    return element;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        int* arr=new int[n];
        for(int i=0;i<n;i++)
           cin>>arr[i];
        cout<<Ceil(arr,n,x)<<" "<<floor(arr,n,x)<<endl;
    }
}