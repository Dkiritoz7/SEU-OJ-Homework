#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int k = 0;k<T;k++)
    {
        long long n,E,s,t;
        long long u,v,w;
        cin>>n>>E>>s>>t;
        long long distance[510];
        long long Edge[510][510];
        bool hasArr[510] = {false};
        for(int i = 0 ;i<510;i++)
        {
            for(int j = 0;j<510;j++) Edge[i][j] = 0x3f3f3f3f;
        }
        for(int i = 1;i<=E;i++)
        {
            cin>>u>>v>>w;
            if(w<=Edge[u][v])
            {
                Edge[u][v] = w;
                Edge[v][u] = w;
            }
		}
        for(int i = 1;i<=n;i++)
        {
            distance[i] = Edge[s][i];
        }
        distance[s] = 0;
        hasArr[s] = true;
        for(int i = 1;i<=n-1;i++)
        {
            int selectPoint = s;
            long long minNumber = 0x3f3f3f3f;
            for(int j = 1;j<=n;j++)
            {
                if(hasArr[j] == false&&distance[j] < minNumber)
                {
                    selectPoint = j;
                    minNumber = distance[j];
                }
            }
            hasArr[selectPoint] = true;
            for(int k = 1;k<=n;k++)
            {
                if(hasArr[k] == false&&Edge[selectPoint][k] + distance[selectPoint]<=distance[k])
                {
                        distance[k] = Edge[selectPoint][k] + distance[selectPoint];
                }
            }
        }
        if(distance[t] !=0x3f3f3f3f) cout<<distance[t]<<endl;
        else cout << -1 << endl;
    }
    return 0;
}