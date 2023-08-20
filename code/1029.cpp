#include <iostream>

using namespace std;

int Edge[510][510];
bool s[510];    //是否已经选入集合
 

void Prim(int n)
{
    bool flag = false;
    int distance[510]; //最短距离集合
    int ans = 0;
    for (int i = 1;i <= n;i++)
    {
        s[i] = false;
        distance[i] = Edge[1][i];
    }
    s[1] = true; //选s0入更新distance

    for (int i = 1;i <= n - 1;i++)  //更新n-1次
    {
        int tempMin = 0x3f3f3f3f;
        int key = 0;
        for (int j = 1;j <= n;j++)  //找最小入s
        {
            if (s[j] == false && distance[j] < tempMin)
            {
                tempMin = distance[j];
                key = j;
            }
        }
        if (tempMin == 0x3f3f3f3f) break;

        s[key] = true;
        ans += tempMin;

        for (int k = 1; k <= n; k++)  //更新distance
        {
            if (key != k && Edge[key][k] < distance[k]) distance[k] = Edge[key][k];
        }
        if (i == n-1) flag = true;
    }
    if (flag) cout << ans<<endl;
    else cout << -1 << endl;
}

int main() {
    int T;
    cin >> T;
    for (int z = 0;z < T;z++)
    {
        int n, m;
        cin >> n >> m;   //顶点，边数。
        for (int i = 1; i <= 509; i++)
        {
            for (int j = 1;j <= 509;j++)
            {
                Edge[i][j] = 0x3f3f3f3f;
            }
        }
        for (int i = 1; i <= m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            if (w <= Edge[u][v])  //重边处理
            {
                Edge[u][v] = w;
                Edge[v][u] = w;
            }
        }
        Prim(n);
    }
    return 0;
}