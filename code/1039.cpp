#include<iostream>
using namespace std;
bool hasDelete[301];
int chosenPoint[301];
bool edge[301][301];
int n;
bool BeChosen(int x)
{
    if (hasDelete[x] == true) return false;
    for (int i = 1;i <= n;i++)
    {
        if (edge[i][x] == true && hasDelete[i] == false) return false;
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    for (int z = 0;z < t;z++)
    {
        int m;
        cin >> n >> m;
        int x, y;
        for (int i = 0;i < 301;i++)
        {
            hasDelete[i] = false;
            chosenPoint[i] = 0;
            for (int j = 0;j < 301;j++)
            {
                edge[i][j] = false;
            }
        }
        for (int i = 0;i < m;i++)
        {
            cin >> x >> y;
            edge[x][y] = true;
        }
        int k = 0, flag;
        for (int i = 0;i < n;i++)
        {
            flag = k;
            for (int j = 1;j <= n;j++)
            {
                if (BeChosen(j))
                {
                    hasDelete[j] = true;
                    chosenPoint[k++] = j;
                    break;
                }
            }
            if (flag == k)
            {
                cout << 0 << endl;
                break;
            }
        }
        if (k != flag)
        {
            for (int j = 0;j < n;j++)
            {
                if (j != 0) cout << " ";
                cout << chosenPoint[j];
            }
            cout << endl;
        }
    }
    return 0;
}