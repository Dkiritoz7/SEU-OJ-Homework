#include<iostream>
#include<cmath>
using namespace std;
//DP
int main()
{
    int M;
    cin>>M;
    for(int K = 0;K<M;K++)
    {
        int N;
        int finalNumber[100]={0};
        int maxNumber = 0;

        cin>>N;
        int height[200]={0};
        for(int i = 1;i<=N;i++)
        {
            cin>>height[i];
        }
        for(int i = 1;i<=N;i++)
        {
            finalNumber[i] = 1;
            for(int j = 1;j<i;j++)
                if(height[i]<=height[j]) 
                {
                    finalNumber[i]=max(finalNumber[i],finalNumber[j] + 1);
                }
        }
        for(int i = 1;i<=N;i++)
        {
            if(finalNumber[i]>=maxNumber) maxNumber = finalNumber[i];
        }
        cout<<maxNumber<<endl;
    }
    return 0;
}