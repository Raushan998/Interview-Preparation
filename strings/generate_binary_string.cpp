#include<bits/stdc++.h>
using namespace std;
void PrintAllBinaryString(string str,int i,string res){
    if(i==str.length()){
        cout<<res<<" ";
        return;
    }
    if(str[i]=='?'){
        PrintAllBinaryString(str,i+1,res+'0');
        PrintAllBinaryString(str,i+1,res+'1');
    }
    else
      PrintAllBinaryString(str,i+1,res+str[i]);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        PrintAllBinaryString(str,0,"");
    }
}