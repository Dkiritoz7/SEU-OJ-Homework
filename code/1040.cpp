#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int nums;
    cin >> nums;
    for (int z = 0;z < nums;z++)
    {
        int m, n, target;
        bool flag = 0;
        cin >> m >> n >> target;
        int matr[1010][1010] = { 0 };
        for (int i = 1;i <= m;i++)
        {
            for (int j = 1;j <= n;j++)
            {
                cin >> matr[i][j];
            }
        }
        int cnt1 = 1;
        int cnt2 = n;
        while (cnt1 <= m && cnt2 >= 1)
        {
            if (matr[cnt1][cnt2] == target)
            {
                flag = 1;
                cout << "true" << endl;
                break;
            }
            if (matr[cnt1][cnt2] > target) cnt2--;
            if (matr[cnt1][cnt2] < target) cnt1++;
        }
        // int cnt1 = 1;
        // int cnt2 = 1;
        // for(int i = 1;i<=min(m,n);i++)
        // {
        //     if(target>matr[i][i]) cnt1 = i;
        //     if(target == matr[i][i])
        //     {
        //         flag = 1;
        //         break;
        //     }
        // }
        // // for(int i = 1;i<=m;i++)
        // // {
        // //     if(matr[i][cnt1] == target) 
        // //     {
        // //         flag =1;
        // //         break;
        // //     }
        // // }
        // // for(int i = 1;i<=n;i++)
        // // {
        // //     if(matr[cnt1][i] == target)
        // //     {
        // //         flag = 1;
        // //         break;
        // //     }
        // // }
        if (flag == 0)cout << "false" << endl;
    }
    return 0;
}