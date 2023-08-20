#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    int M;
    cin>>M;
    for(int i = 0;i < M;i++)
    {
        char str[100];
        int N,K;
        cin>>N;
        cin>>K;
        cin>>str;
        int s[100],myIntString[100][100]={0},final_string[100][100]={0};
        for(int i = 1;i<=N;i++)
        {
            s[i] = str[i-1] - '0';
            myIntString[i][i] = s[i];
        }
        for(int i = 1;i<=N;i++)
        {
            for(int j = i;j <= N ;j++)
            {
                myIntString[i][j] = myIntString[i][j-1] * 10 + s[j];
                //cout<<myIntString[i][j]<<" ";
            }
            //cout<<endl;
        }
        for(int i = 1;i<=N;i++)
        {
            final_string[i][0] = myIntString[1][i];
        }
        for(int i = 1;i<=N;i++)
            for(int j = 1;j<=K;j++)
                for(int l = j;l<i;l++)
                    final_string[i][j] = max(final_string[i][j],final_string[l][j-1] * myIntString[l+1][i]);
        cout<<final_string[N][K]<<endl;
    }
    return 0;
}