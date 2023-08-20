#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
/*
DP
最大连续子数组和问题我认为可以抽象为这样的问题(+代表这个数为正，-代表这个数为负)
++ +- -+ -- 这四种情况，而因为是连续子数组，所以我们只需要存以下几个数据即可：
maxnumber[i-1] + a[i](之后加的数为+的情况会有这种例子) a[i](之前为- 加个正数肯定取正数最大) 之前数组已经得到的最大值 
再进行比较即可求得这个数组到0-i的最大连续子数组和
*/
int max_subArraySum(int a[],int number)
{
    int result = a[0];
    int maxnumber[50100];
    for(int i=1;i<=number;i++)
    {
        maxnumber[i] = max(maxnumber[i-1]+a[i],a[i]);
        result =max(maxnumber[i],result);
    }
    return result;
}
int main()
{
    int M;
    cin>>M;
    for(int i=0;i<M;i++)
    {
        int result = 0;
        int a[50100] = {-1000};
        int N;
        cin>>N;
        for(int j = 1;j<=N;j++)
        {
            cin>>a[j];
        }
        result = max_subArraySum(a,N);
        cout<<result<<endl;
    }
    return 0;
}