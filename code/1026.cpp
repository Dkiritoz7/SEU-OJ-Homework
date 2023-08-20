#include<iostream>
using namespace std;
/*
其实思路和1007相类似，只是这里加了+号，但是吧，
最后最大的值肯定是加号在括号里头然后配合乘号，就是乘号乘号之间为+号
实际上也就是考虑乘号位置
*/
int main()
{
    int M;
    cin>>M;
    long long maxfinal[20][20];
    long long data[20][20];

    for(int z = 0;z<M;z++)
    {
        for(int i = 0;i<20;i++)
            for(int j =0;j<20;j++)
            {
                data[i][j] =0;
                maxfinal[i][j] =0;
            }
        int n,k;
        cin>>n>>k;
        int a[30];
        for(int i =0 ;i<n;i++) cin>>a[i];
        for(int i =0;i<n;i++)
        {
            long long temp = 0;
            for(int j = i ;j<n;j++)
            {
                temp += a[j];
                data[i][j] = temp;
            }
        }
        for(int i = 0;i<n;i++)
        {
            maxfinal[i][0] = data[0][i];//初始化 0个乘号的情况
        }
        for(int i =1;i<n;i++)
        {
            for(int w =1;w<=k&&w<=i;w++)
            {
                for(int t = 0 ;t<i;t++)
                {
                   maxfinal[i][w] = max(maxfinal[t][w-1]*data[t+1][i],maxfinal[i][w]);
                }
            }
        }
        cout << maxfinal[n - 1][k] << endl;
    }
}