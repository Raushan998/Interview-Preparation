#include<bits/stdc++.h>
using namespace std;
struct Pair{
    int x,y;
};
int main(){
    Pair p1,p2,p3;
    cin>>p1.x>>p1.y>>p2.x>>p2.y>>p3.x>>p3.y;
    int num=(((p2.y-p1.y)*(p3.x-p2.x))-((p3.y-p2.y)*(p2.x-p1.x)));
    if(num==1)
       cout<<"ClockWise"<<endl;
    else if(num<0)
       cout<<"CounterClockwise"<<endl;
    else
    {
        cout<<"Collinear"<<endl;
    }
    return 0;
    
}