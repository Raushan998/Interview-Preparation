#include<bits/stdc++.h>
using namespace std;
void printMatrix(string str){
    reverse(str.begin(),str.end());
    for(int i=0;i<str.size();i++)
       cout<<str[i];
    return;
}
bool isRatInMaze(int** matrix,int i,int j,int n,string str){
    if(i==n-1 && j==n-1 && matrix[i][j]==1){
        cout<<str<<" ";
        return true;
    }
    if(i<0 || j<0 || i>=n || j>=n || matrix[i][j]==0)
        return false;
    int val=matrix[i][j];
    matrix[i][j]=0;
    if(isRatInMaze(matrix,i+1,j,n,str+'D') || isRatInMaze(matrix,i-1,j,n,str+'U') 
                        || isRatInMaze(matrix,i,j-1,n,str+'L') || isRatInMaze(matrix,i,j+1,n,str+'R'))
                        return true;
    matrix[i][j]=val;
    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int** matrix=new int*[n];
        for(int i=0;i<n;i++){
            matrix[i]=new int[n];
            for(int j=0;j<n;j++)
               cin>>matrix[i][j];
        }
        string str="";
        if(! isRatInMaze(matrix,0,0,n,str))
           cout<<"-1"<<endl;
         
    }
    return 0;
}