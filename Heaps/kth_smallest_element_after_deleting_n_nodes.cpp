#include<bits/stdc++.h>
#define MAX 1000000;
using namespace std;
int main(){
    int n;
    cin>>n;
    int* arr=new int[n];
    for(int i=0;i<n;i++)
       cin>>n;
    int k;
    int b[MAX]={0};
    cin>>k;
    int i=0;
    for(i=0;i<MAX;i++){
        if(b[arr[i]]==1)
           k--;
        if(k==0){
          cout<<i<<endl;
        }   
    }
    return 0;
}