#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int>a,pair<int,int>b){
    return a.second<b.second;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>vect;
    for(int i=0;i<n;i++){
        int num1,num2;
        cin>>num1>>num2;
        vect.push_back({num1,num2});
    }
    sort(vect.begin(),vect.end(),compare);
    for(int i=0;i<n;i++)
       cout<<vect[i].first<<" "<<vect[i].second<<endl;
    int* dp=new int[n];
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
           if(vect[i].first>vect[j].first && dp[i]<dp[j]+1)
               dp[i]=dp[j]+1;
        }
    }
    int best=0;
    for(int i=0;i<n;i++)
        best=max(best,dp[i]);
    cout<<best<<endl;
}