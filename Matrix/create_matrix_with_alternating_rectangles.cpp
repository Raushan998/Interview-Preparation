#include<bits/stdc++.h>
using namespace std;
void PrintMatrix(char** matrix,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
           cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}
void Matrix_with_alternating_rectangles(char** matrix,int m,int n){
    int start_row,end_row,start_col,end_col;
    start_row=0,end_row=m-1,start_col=0,end_col=n-1;
    char val='X';
    bool flag=true;
    while(start_row<=end_row && start_col<=end_col){
        int i=start_col;
        while(i<=end_col){
            matrix[start_row][i++]=val;
        }
        start_row++;
        i=start_row;
        while(i<=end_row){
            matrix[i++][end_col]=val;
        }
        end_col--;
        i=end_col;
        if(end_row>=start_row){
            while(i>=start_col){
               matrix[end_row][i--]=val;
           }
        }
        end_row--;
        i=end_row;
        if(end_col>=start_col){
            while(i>=start_row){
                matrix[i--][start_col]=val;
            }
        }
        start_col++;
        if(flag){
            val='O';
            flag=false;
        }
        else{
            val='X';
            flag=true;
        }
    }
}
int main(){
    int m,n;
    cin>>m>>n;
    char** matrix=new char*[m];
    for(int i=0;i<n;i++){
        matrix[i]=new char[n];
        for(int j=0;j<n;j++){
           matrix[i][j]='1';
        }
    }
    Matrix_with_alternating_rectangles(matrix,m,n);
    PrintMatrix(matrix,m,n);
}