#include<bits/stdc++.h>
using namespace std;
void WordBreak(string str,set<string>&s,string res){
    for(int i=1;i<=str.size();i++){
        string prefix=str.substr(0,i);
        if(s.find(prefix)!=s.end()){
            if(i==str.size()){
                res+=prefix;
                cout<<res<<endl;
                return;
            }
            WordBreak(str.substr(i,str.size()-i),s,res+prefix+" ");
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        set<string>s;
        for(int i=0;i<n;i++){
            string str;
            cin>>str;
            s.insert(str);
        }
        string str;
        cin>>str;
        WordBreak(str,s,"");
    }
}