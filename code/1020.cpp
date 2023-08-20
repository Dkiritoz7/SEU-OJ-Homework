#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int M;
    cin>>M;
    for(int i = 0;i<M;i++)
    {
        int m[500][500] = {1000};
        int s[500][500] = {1000};
        int N;
        cin>>N;
        int col[510] = {-1};
        int row[510] = {-1};
        for(int j = 1;j<=N;j++)
        {
            cin>>row[j];
            cin>>col[j];
            m[j][j] = 0;
        }
        for(int r = 2;r<=N;r++)
        {
            for(int i = 1; i<=N - r +1;i++)
            {
                int j = i + r - 1 ;
                m[i][j] = m[i][i]+m[i+1][j]+row[i]*row[i+1]*col[j];
                s[i][j] = i;
                for(int k = i+1;k<j;k++)
                {
                    int t = m[i][k]+m[k+1][j]+row[i]*row[k+1]*col[j];
                    if(t < m[i][j])
                    {
                        m[i][j] = t;
                        s[i][j] = k;
                    }
                }
            }
        }
        cout<<m[1][N]<<endl;
        // for(int k = 1;k<=N;k++)
        // {
        //     for (int z = k+1;k<=N;z++)
        //     {
        //             for(int l=k;l<=z;l++)
        //             {
        //                 m[k][z] = min(m[k][z],m[k][l] + m[l+1][z] +row[k]*row[l+1]*col[z] );
        //             }
        //     }
        // }
        // cout<<m[1][N]<<endl;
    }
    return 0;
}
