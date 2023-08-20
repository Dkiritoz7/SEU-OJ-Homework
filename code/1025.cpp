#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int M;
    cin>>M;
    for(int i = 0;i<M;i++)
    {
        int N;
        cin>>N;
        int maxFin;
        int data[10010];
        int f[10010];
        for(int j = 1;j<=N;j++) 
        {
            cin>>data[j];
            f[j] = 1;
        }
        for(int j = 2;j<=N;j++)
        {
            for(int k = j-1;k>=1;k--)
            {
                if(data[j]>=data[k]) f[j] = max(f[j],f[k]+1);
            }
        }
        for(int j = 1;j<=N;j++)
        {
            maxFin=max(maxFin,f[j]);
        }
        cout<<maxFin<<endl;
    }
    return 0;
}