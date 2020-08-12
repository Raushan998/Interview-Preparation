#include<bits/stdc++.h>
using namespace std;
vector<vector<string>>vect;
bool isPalindrome(string str){
    int start=0,end=str.length()-1;
    while(start<end){
        if(str[start]!=str[end])
           return false;
        start++;
        end--;
    }
    return true;
}
void PrintPalindromicString(string str,int i,vector<string>&temp){
    string res="";
    vector<string>current=temp;
    for(int index=i;index<str.length();index++){
        res=res+str[index];
        if(isPalindrome(res)){
            temp.push_back(res);
            if(i+1<str.length()){
                PrintPalindromicString(str,index+1,temp);
            }
            else
               vect.push_back(temp);
            temp=current;
        }  
    }
}
int main(){
    string str;
    cin>>str;
    vector<string>temp;
    PrintPalindromicString(str,0,temp);
    for(auto it:vect){
        for(auto x:it)
           cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}