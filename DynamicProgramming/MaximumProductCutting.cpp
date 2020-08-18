#include<bits/stdc++.h>
using namespace std;
int dp[100001];
int MaxProductCutting(int n){
    if(n==1 || n==0)
       return 0;
    if(dp[n]!=-1)
       return dp[n];
    int val=0;
    for(int i=1;i<n;i++){
        val=max(val,max(i*(n-i),MaxProductCutting(n-i)*i));
    }
    dp[n]=val;
    return val;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<=n;i++)
       dp[i]=-1;
    cout<<MaxProductCutting(n)<<endl;
}