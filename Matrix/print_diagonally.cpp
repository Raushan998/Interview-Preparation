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
        int **matrix = new int *[n];
        for (int i = 0; i < n; i++)
        {
            matrix[i] = new int[n];
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        }
        for (int k = 0; k < n; k++)
        {
            int i = 0, j = k;
            while (i < n && j >= 0)
            {
                cout << matrix[i][j] << " ";
                i++, j--;
            }
        }
        for (int k = 1; k < n; k++)
        {
            int i = k, j = n - 1;
            while (j >= 0 && i < n)
            {
                cout << matrix[i][j] << " ";
                j--;
                i++;
            }
        }
        cout << endl;
    }
}