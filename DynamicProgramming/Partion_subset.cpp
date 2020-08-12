#include<bits/stdc++.h>
#define mod 100000007
using namespace std;
int dp[1000][1000];
int PartitionSubsets(int n,int k){
    if(k==1 || k==n)
        return 1;
    if(k==0 || k>n || n==0)
        return 0;
    if(dp[n][k]!=-1)
       return dp[n][k];
    int val=((k*PartitionSubsets(n-1,k))%mod+(PartitionSubsets(n-1,k-1)%mod))%mod;
    dp[n][k]=(val%mod);
    return val;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++)
               dp[i][j]=-1;
        }
        cout<<PartitionSubsets(n,k)<<endl;
    }
}