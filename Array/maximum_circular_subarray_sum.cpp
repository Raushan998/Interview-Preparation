#include<bits/stdc++.h>
using namespace std;
int max_kadane(int* arr,int n){
    int max_val=INT_MIN,current_val=0;
    for(int i=0;i<n;i++){
        current_val=max(current_val+arr[i],arr[i]);
        max_val=max(current_val,max_val);
    }
    return max_val;
}
int min_kadane(int* arr,int n){
    int min_val=INT_MAX,current_val=0;
    for(int i=0;i<n;i++){
        current_val=min(current_val+arr[i],arr[i]);
        min_val=min(current_val,min_val);
    }
    return min_val;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int* arr=new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int max_so=max_kadane(arr,n);
        int min_so=min_kadane(arr,n);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
    //    cout<<max_so<<" "<<sum<<" "<<min_so<<endl;
        if(sum==min_so)
            cout<<max_so<<endl;
        else
           cout<<max(max_so,sum-min_so)<<endl;
    }
    return 0;
}