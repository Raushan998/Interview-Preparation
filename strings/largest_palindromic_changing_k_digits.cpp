#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    string str;
    cin>>str;
    cin>>k;
    string palin=str;
    int left=0,right=str.length()-1;
    while(left<right){
        if(palin[left]!=palin[right]){
            palin[left]=palin[right]=max(palin[left],palin[right]);
            k--;
        }
        left++;
        right--;
    }
    left=0,right=str.length()-1;
    if(k<0)
       cout<<"Not Possible";
    else{
        while(left<=right){
            if(k>1 && (palin[left]==str[left]) && palin[right]==palin[right]){
                palin[left]=palin[right]='9';
                k-=2;
            }
            else if(k>=1 && (palin[left]!=str[left] || palin[right]!=str[right])){
                k--;
                palin[left]=palin[right]='9';
            }
            left++;
            right--;
       }
       cout<<palin<<endl;
    }
}