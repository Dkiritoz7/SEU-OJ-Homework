#include <iostream>
using namespace std;
int main() {
    int nums, N, K;
    cin >> nums;
    for (int i = 0; i < nums; i++) {
        cin >> K >> N;
        int m = 0;
        int dp[101][10001] = {0};
        while (dp[K][m] < N) {
            m++;
            for (int k = 1; k <= K; k++)
                dp[k][m] = 1 + dp[k - 1][m - 1] + dp[k][m - 1];
        }
        cout << m << endl;
    }
    return 0;
}