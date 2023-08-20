#include <iostream> 
#include <iomanip>
using namespace std; 
int main() 
{
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) 
    {
        int MaxVal = 9999;
        int data[510] = {0};
        double p[510] = {0};
        double q[510] = {0};
        double w[501][501] = {0};  // 子树概率总和
        double e[501][501] = {0};  // 子树期望代价
        int N;
        cin >> N;
        p[0] = -1;
        for (int j = 1; j <= N; j++)
            cin >> data[j];
        for (int j = 1; j <= N; j++)
            cin >> p[j];
        for (int j = 0; j <= N ; j++)
            cin >> q[j];
        for (int j = 1; j <= N + 1; ++j) 
        {
            w[j][j - 1] = q[j - 1];
            e[j][j - 1] = q[j - 1];
        }
        //由下到上，由左到右逐步计算
        for (int len = 1; len <= N; ++len) 
        {
            for (int l = 1; l <= N - len + 1; ++l) 
            {
                int j = l + len - 1;
                e[l][j] = MaxVal;
                w[l][j] = w[l][j - 1] + p[j] + q[j];
               for (int k = l; k <= j; ++k) 
               {
                double temp = w[l][j];
                if(k-1>=l) temp += e[l][k-1];
                if(k+1<=j) temp += e[k+1][j];
                if(temp<e[l][j]) 
                {
                    e[l][j] =temp;
                }
               }
            }
        }
        cout <<fixed << setprecision(6)<< e[1][N] << endl;
    }
    return 0;
}