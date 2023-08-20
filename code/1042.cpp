#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int nums;
    cin >> nums;
    for (int z = 0;z < nums;z++)
    {
        int m;
        cin >> m;
        int days[370] = { 0 };
        int costs[3] = { 0 };
        int f[400] = { 0 };
        int cnt = 1;
        for (int i = 1;i <= m;i++)
        {
            cin >> days[i];
        }
        for (int i = 0;i < 3;i++)
        {
            cin >> costs[i];
        }
        for (int i = 31;i <= days[m]+30;i++)
        {
            if (i == days[cnt] + 30)
            {
                f[i] = min(min(f[i - 1] + costs[0], f[i - 7] + costs[1]), f[i - 30] + costs[2]);
                cnt++;
            }
            else
            {
                f[i] = f[i - 1];
            }
        }
        cout << f[days[m]+30] << endl;
    }
    return 0;
}