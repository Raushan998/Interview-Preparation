#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int longestPalindromic(string str,string res,int m,int n){
    if(m==str.length() || n==str.length())
        return 0;
    if(dp[m][n]!=-1)
        return dp[m][n];
    int ans=0;
    if(str[m]==res[n])
       ans=1+longestPalindromic(str,res,m+1,n+1);
    else
        ans=max(longestPalindromic(str,res,m+1,n),longestPalindromic(str,res,m,n+1));
    dp[m][n]=ans;
    return ans;
}
int main(){
    string str;
    cin>>str;
    string res=str;
    reverse(res.begin(),res.end());
    for(int i=0;i<res.length();i++){
        for(int j=0;j<str.length();j++)
           dp[i][j]=-1;
    }
   // cout<<res<<" "<<str<<endl;
    cout<<longestPalindromic(str,res,0,0)<<endl;
}