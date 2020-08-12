#include<bits/stdc++.h>
using namespace std;
int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};
bool isSafe(int x,int y,int** sol,int N){
    return (x >= 0 && x < N && y >= 0 &&
            y < N && sol[x][y] == -1);
}
int KnightTour(int** matrix,int x,int y,int num,int n){
    if(n*n==num)
       return 1;
    for(int i=0;i<8;i++){
       int next_x=xMove[i]+x;
       int next_y=yMove[i]+y;
       if(isSafe(next_x,next_y,matrix,n)){
          matrix[next_x][next_y]=num;
          if(KnightTour(matrix,next_x,next_y,num+1,n)==1)
              return 1;
          else
              matrix[next_x][next_y]=-1;
       }
    }
    return 0;
}
int main(){
    int n;
    cin>>n;
    int** matrix=new int*[n];
    for(int i=0;i<n;i++){
        matrix[i]=new int[n];
        for(int j=0;j<n;j++)
           matrix[i][j]=-1;
    }
    matrix[0][0]=0;
    if(KnightTour(matrix,0,0,1,n)){
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++)
              cout<<matrix[i][j]<<" ";
           cout<<endl;
       }
    }
    else
    {
        cout<<"Solution doesn't exist"<<endl;
    }
    return 0;
}