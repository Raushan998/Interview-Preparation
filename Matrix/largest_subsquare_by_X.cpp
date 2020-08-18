#include<bits/stdc++.h>
using namespace std;
int MaxSquare(char** matrix,int n){
    int** ver=new int*[n];
    int** hor=new int*[n];
    for(int i=0;i<n;i++){
        ver[i]=new int[n];
        hor[i]=new int[n];
    }
    hor[0][0] = ver[0][0] = (matrix[0][0] == 'X'); 
    for (int i=0; i<n; i++) 
    { 
        for (int j=0; j<n; j++) 
        { 
            if (matrix[i][j] == 'O') 
                ver[i][j] = hor[i][j] = 0; 
            else
            { 
                hor[i][j] = (j==0)? 1: hor[i][j-1] + 1; 
                ver[i][j] = (i==0)? 1: ver[i-1][j] + 1; 
            } 
        } 
    } 
    int max_=0;
    for(int i=n-1;i>=1;i--){
        for(int j=n-1;j>=1;j--){
            int small=min(ver[i][j],hor[i][j]);
            while(small>max_){
                if(ver[i][j-small+1]>=small && hor[i-small+1][j]>=small)
                   max_=small;
                small--;
            }
        }
    }
    return max_;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char** matrix=new char*[n];
        for(int i=0;i<n;i++){
            matrix[i]=new char[n];
            for(int j=0;j<n;j++)
               cin>>matrix[i][j];
        }
        cout<<MaxSquare(matrix,n)<<endl;
    }
}