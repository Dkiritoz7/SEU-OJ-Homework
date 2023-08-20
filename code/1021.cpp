#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int m;
    cin>>m;
    for(int i = 0;i<m;i++)
    {
        int n,k;
        cin>>n;
        cin>>k;
        int lengthTable[10001] = {0};
        int priceTable[10001] = {0};
        int dp[10001] = {0};
        int minlen = 100000;
        for(int j = 1;j<=k;j++)
        {
            cin>>lengthTable[j];
            cin>>priceTable[j];
            if(lengthTable[j]<minlen) minlen = lengthTable[j];
        }
        // for(int j = 1;j<=k;j++)
        // {
        //     if(lengthTable[j]<minlen) minlen = lengthTable[j];
        // }
        for(int li = minlen;li<=n;li++)
        {
            int temp = 0;
            for(int l = 1;l<=k;l++)
            {
                if(lengthTable[l]<=li) temp = max(temp,priceTable[l] + dp[li-lengthTable[l]]);
            }
            dp[li] = temp;
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}