#include <bits/stdc++.h>
using namespace std;
class Job
{
public:
    int id;
    int deadline;
    int profit;
};
bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Job current[n];
        for (int i = 0; i < n; i++)
        {
            int id, deadline, profit;
            cin >> id >> deadline >> profit;
            current[i].id = id;
            current[i].deadline = deadline;
            current[i].profit = profit;
        }
        sort(current, current + n, compare);
        int result[n];
        for (int i = 0; i < n; i++)
            result[i] = -1;
        bool slot[n] = {false};
        for (int i = 0; i < n; i++)
        {
            for (int j = min(n, current[i].deadline) - 1; j >= 0; j--)
            {
                if (slot[j] == false)
                {
                    result[j] = i;
                    slot[j] = true;
                    break;
                }
            }
        }
        //for(int i=0;i<n;i++)
        // cout<<current[i].id<<" "<<current[i].deadline<<" "<<current[i].profit<<endl;
        int total_sum = 0, count = 0;
        for (int i = 0; i < n; i++)
        {
            cout << result[i] << " ";
            if (result[i] != -1)
            {
                total_sum += current[result[i]].profit;
                count++;
            }
        }
        cout << count << " " << total_sum << endl;
    }
}