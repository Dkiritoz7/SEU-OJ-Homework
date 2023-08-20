#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int main()
{
    int M;
    cin>>M;
    for(int i = 0;i<M;i++)
    {
        int LCS[510][510] = {-1};
        char c1[501];
        char c2[501];
        cin>>c1;
        cin>>c2;
        for(int i = 0;i<=509;i++) LCS[i][0] = 0;
        for(int j = 1;j<=509;j++) LCS[0][j] = 0;
        for(int j = 1; j<= strlen(c1);j++)
        {
            for(int z = 1;z<= strlen(c2);z++)
            {
                if(c1[j-1] == c2[z-1]) LCS[j][z] = LCS[j-1][z-1] + 1;
                else 
                {
                    if(LCS[j-1][z]>=LCS[j][z-1])  LCS[j][z] = LCS[j-1][z];
                    else LCS[j][z] = LCS[j][z-1];
                }
            }
        }
        cout<<LCS[strlen(c1)][strlen(c2)]<<endl;
    }
    
    return 0;
}

