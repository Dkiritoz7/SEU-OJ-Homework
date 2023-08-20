#include<iostream>
#include<algorithm>
using namespace std;
/*大体思路如下：因为题目给出仓库容量无限且存一个月成本为1
  那么我们可以这样想，先举个例子：第二个月生产成本为999，但第一个月生产成本为2
  那么在这种情况下，第二个月的最低生产成本其实为第一个月的2+存储的1=3
  所以贪心的话应该是贪每个月的生产成本最低*/
int main()
{
    int T;
    cin >> T;
    for (int z = 0;z < T;z++)
    {
        int N;
        cin >> N;
        long long c_i[100010] = { 0 };
        long long y_i[100010] = { 0 };
        long long w_i[100010] = { 0 };
        long long minMoney = 0;
        for (int i = 1;i <= N;i++)
        {
            cin >> c_i[i];
            w_i[i] = c_i[i];
        }
        for (int i = 1;i <= N;i++)
        {
            cin >> y_i[i];
        }
        minMoney += c_i[1] * y_i[1];
        for (int i = 2;i <= N;i++)
        {
            w_i[i] = min(w_i[i], w_i[i - 1] + 1);
            minMoney += w_i[i] * y_i[i];
        }
        cout << minMoney << endl;
    }
    return 0;
}