#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
/*主要思路：因为是树形结构所以肯定要递归实现，并且着色问题肯定和节点的父子节点相关，要去存父子节点
   实现思路用DP，dp[i][1]表示根节点黑色时这颗树的最多黑色节点情况，dp[i][0]表示根节点为白。
   因为黑色不能连续着色，dp[i][1] = 1 + 子节点构成子树的最多黑色节点情况相加，此时子树的这些根节点必为白。
   dp[i][0] = 子节点构成子树的最多黑色节点情况相加，此时子树的这些根节点可为白可为黑，需要进行比较。
*/
vector<int>* child;
int hasPar[50010] = { 0 }; //有父节点
int dp[50010][2] = { 0 };
void solve(int root)
{
    dp[root][0] = 1;
    dp[root][1] = 0;
    for (int i = 0;i < child[root].size();i++)
    {
        solve(child[root][i]);

        dp[root][0] += dp[child[root][i]][1];
        dp[root][1] += max(dp[child[root][i]][1], dp[child[root][i]][0]);
    }
}

int main()
{
    int T;
    cin >> T;
    while ((T--) > 0)
    {
        int N;
        cin >> N;

        child = new vector<int>[N + 1]; //存子节点
        memset(hasPar, 0, sizeof(hasPar));
        int u, v;
        for (int i = 0;i < N - 1;i++)
        {
            cin >> u;
            cin >> v;

            child[u].push_back(v);

            hasPar[v] = 1;
        }

        int root = 0;
        for (int Ni = 1; Ni <= N; Ni++)
        {
            if (hasPar[Ni] == 0) {
                root = Ni;
                break;
            }
        }
        memset(dp, 0, sizeof(dp));
        solve(root);
        cout << max(dp[root][0], dp[root][1]) << endl;
        delete[] child;
    }
    return 0;
}