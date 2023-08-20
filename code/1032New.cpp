#include<iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    for (int z = 0;z < T;z++)
    {
        int N;
        cin >> N;
        double final = 0;
        double pi[1100] = { 0 };
        double finalPi[1100][1100] = { 0 };
        for (int i = 1;i < N;i++)
        {
            double temp;
            cin >> temp;
            pi[i] = temp / 100;
        }
        finalPi[0][0] = 1;
        for (int i = 1;i < N;i++)
        {
            finalPi[i][0] = finalPi[i - 1][0] * (1-pi[i]);
        }
        for (int i = 1;i < N;i++)
        {
            for (int j = 1;j <= i;j++)
            {
                finalPi[i][j] = finalPi[i - 1][j] * (1 - pi[i]) + finalPi[i - 1][j - 1] * pi[i];
            }
        }
        for (int i = 1;i < N;i++)
        {
            //cout << finalPi[N-1][i] << " ";
            final += finalPi[N-1][i] * (i + 1);
        }
        cout << final << endl;
    }
    return 0;
}