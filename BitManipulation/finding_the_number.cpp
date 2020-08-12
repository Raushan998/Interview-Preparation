#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *arr = new int[2 * n + 2];
        for (int i = 0; i < (2 * n + 2); i++)
        {
            cin >> arr[i];
        }
        int num = 0, current_num = 0;
        for (int i = 0; i < (2 * n + 2); i++)
        {
            num = num ^ arr[i];
        }
        current_num = num;
        int i = 0;
        while (num > 0)
        {
            if (num & 1)
                break;
            num = num >> 1;
            i++;
        }
        int mask = 1 << i;
        int firstNo = 0;
        for (int i = 0; i < (2 * n + 2); i++)
        {
            if (mask & arr[i])
            {
                firstNo = firstNo ^ arr[i];
            }
        }

        if (firstNo < (current_num ^ firstNo))
            cout << firstNo << " " << (current_num ^ firstNo) << endl;
        else
        {
            cout << (current_num ^ firstNo) << " " << firstNo << endl;
        }
    }
    return 0;
}