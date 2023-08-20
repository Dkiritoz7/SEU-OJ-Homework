#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
struct country
{
    int v,w;
}
vector<country> world[505];
struct vertex
{
    int money,distance,v;
}
struct comp
{
    bool operator()(vertex v1,vertex v2)
    {
        return v1.distance < v2.distance;
    }
};
priority_queue<vertex,vector<vertex>,comp> arr;

int main()
{
    int T;
    cin >> T;
    for(int z = 0;z<T;z++)
    {
        int n,E,s,t,M;
        cin>>n;
        cin>>E;
        cin>>s;
        cin>>t;
        cin>>M;
        int distance[510][510];
        int flag[510][510];
        int cost[510];
        for(int i = 1;i <= n;i++) cin>>cost[i];
        for(int i = 1;i <= E;i++)
        {
            int u,v,w;
            cin >> u >>v >>w;
            country temp;
            temp.v = v;
            temp.w = w;
            world[u].push_back(temp);
            temp.v = u;
            world[v].push_back(temp);
        }
        vertex temp2;
        temp2.money = M;
        temp2.distance = 0;
        temp2.v = s;
        distacne[temp2.start][M] =  0;
        arr.push(temp2);
        while(!arr.empty())
        {
            temp2 = arr.top();
            arr.pop();
            int start = temp2.v;
            
            flag[start][temp2.money] = false;
            int p = 
            for(int i = 0 ;i<world[])
        }
    }
    return 0;
}