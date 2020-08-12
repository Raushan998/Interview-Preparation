#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            pq.push(num);
        }
        while (k--)
        {
            cout << pq.top() << " ";
            pq.pop();
        }
    }
    return 0;
}