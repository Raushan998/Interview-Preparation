#include <iostream>
#include <climits>
using namespace std;
int main()
{
    long t;
    cin >> t;
    while (t--)
    {
        long n, k;
        cin >> n >> k;

        //concatenate the array if k>1
        long size = n;
        if (k > 1)
            size = 2 * n;
        long *a = new long[size];
        for (long i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (size == 2 * n)
        {
            for (long i = n; i < 2 * n; i++)
            {
                a[i] = a[i - n];
            }
        }

        //kadanes algorithm on concatenated array to find maximum contiguous array sum
        long curr_sum = 0, max_sum = LONG_MIN;
        ;
        for (long i = 0; i < size; i++)
        {
            curr_sum += a[i];
            if (curr_sum > max_sum)
            {
                max_sum = curr_sum;
            }
            if (curr_sum < 0)
            {
                curr_sum = 0;
            }
        }

        //if array sum is greater than 0 then add (k-2)*arr_sum to our answer
        long arr_sum = 0;
        for (long i = 0; i < n; i++)
        {
            arr_sum += a[i];
        }
        long ans;
        if (arr_sum > 0 && k > 1)
            ans = max_sum + (k - 2) * arr_sum;
        else
            ans = max_sum;
        cout << ans << endl;
    }
}
