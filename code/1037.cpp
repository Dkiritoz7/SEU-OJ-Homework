#include<iostream>
using namespace std;
bool match[51][51];
bool used[51];
int girl[51];
int m;
bool find(int x);
int main()
{
    int T;
    cin>>T;
    for(int z = 0;z<T;z++)
    {   
        for(int i = 1;i<=51;i++)
        {
            for(int j = 1 ;j<=51;j++) match[i][j] = false;
        }
        for(int i = 1;i<=51;i++)
        {
            girl[i] = 0;
        }
        int k;
        int n;
        cin>>n>>m;
        int success = 0,x;
        for(int i = 1;i<=n;i++)
        {
            cin>>k;
            for(int j = 0;j<k;j++)
            {
                cin>>x;
                match[i][x] = true;
            }
        }
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                used[j] = false;
            }
           if(find(i)) success++;
        }
        cout<<success<<endl;
    }
    return 0;
}
bool find(int x)
{
    for(int i = 1;i<=m;i++)
    {
        if(match[x][i] == true&&used[i] == false)
        {
            used[i] = true;
            if(girl[i] == 0 ||find(girl[i]))
            {
                girl[i] = x;
                return true;
            }
        }
    }
    return false;
}