#include<bits/stdc++.h>
using namespace std;
bool WilCardMatching(string text,string pattern,int i,int j){
    if(i>=text.length() && j>=pattern.length())
       return true;
    if(i>=text.length() || j>=pattern.length())
       return false;
    if(text[i]==pattern[j])
       return WilCardMatching(text,pattern,i+1,j+1);
    else if(pattern[i]=='?')
       return WilCardMatching(text,pattern,i+1,j+1);
    else if(pattern[i]=='*')
        return WilCardMatching(text,pattern,i,j+1) || WilCardMatching(text,pattern,i+1,j);
    return false;
       
}
int main(){
    string text,pattern;
    cin>>text>>pattern;
    cout<<WilCardMatching(text,pattern,0,0)<<endl;
}