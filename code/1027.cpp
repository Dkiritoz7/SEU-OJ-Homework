#include<iostream>
#include<algorithm>
using namespace std;
/*
    大体思想如下：首先肯定是要尽量选最多的活动去进行，并且越早结束对整体活动影响越小。
    所以首先以活动结束时间排序，类似于贪心求解时候思路。但是这个题加了权值，所以用DP。
    dp[i] = max(dp[i - 1],dp[j] + act[i].vi);
    因为这个式子是已经排好序的，所以第一个活动到第i个活动最大权值就是前面的遍历一遍，
    如果这个时候前面这个活动能插到现在第i个活动前，那么就直接在它的dp值上加i的权值。
    此时dp[j]已经是最优，所以这样推下来每个dp都为最优。
*/
typedef struct activity{
 int si;  //活动开始时间 
 int fi;
 int vi;
}activity; 

bool comp(const activity x,const activity y)
{
 return x.fi < y.fi;
}
int main()
{
    int M;
    cin>>M;
    for(int z = 0;z<M;z++)
    {
        activity act[10010];
        int N;
        cin>>N;
        int dp[10001]={0};
        for(int i = 1;i<=N;i++)
        {
            cin >> act[i].si;
            cin >> act[i].fi;
            cin >> act[i].vi; 
        }
        dp[0] = 0;
        act[0].si = act[0].fi =act[0].vi = 0;
		sort(act+1,act + N + 1,comp);
		for (int i = 1; i <= N; i++) 
        {
            for(int j = i -1 ; j>=0;j--)
            {
                if(act[j].fi <= act[i].si)
                {
                    dp[i] = max(dp[i - 1],dp[j] + act[i].vi);
                    break;
                }
            }
        }
		cout << dp[N] << endl;
	}
	return 0;
}