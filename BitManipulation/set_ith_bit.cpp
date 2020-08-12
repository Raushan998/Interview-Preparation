#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int x,l,r,y, count=1;
	    string res="";
	    cin>>x>>l>>r>>y;
	    while(count<l){
	        if(x&1)
	           res+=to_string(1);
	        else
	           res+=to_string(0);
	        count++;
	        x=x>>1;
	        y=y>>1;
	    }
	    while(count<=r){
	        if(x&1)
	           res+=to_string(1);
	        else if(y&1)
	            res+=to_string(1);
	        else
	            res+=to_string(0);
	       x=x>>1;
	       y=y>>1;
	       count++;
	    }
	    while(x>0){
	        if(x&1)
	           res+=to_string(1);
	        else
	            res+=to_string(0);
	       x=x>>1;
	    }
	    int k=0,num=0;
	    for(int i=0;i<res.length();i++){
	        if(res[i]=='1'){
	            num+=pow(2,k);
	        }
	        k++;
	    }
	    cout<<num<<endl;
	}
	return 0;
}