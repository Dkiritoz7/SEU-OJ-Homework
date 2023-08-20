#include <iostream>
#include <algorithm>
using namespace std;

struct work {   
    long long ddl;   
    long long value;      
};

long long compareWork(work a, work b) {
    return (a.value > b.value);
}

int main()
{
    long long T;
    cin >> T;
    while ((T--) > 0)
    {
        long long N;
        cin >> N;

        long long maxValue = 0;
        work* ops = new work[N];
        long long maxDDL = 0;
        for (long long ni = 0; ni < N; ++ni) 
        {
            work temp;
            cin >> temp.ddl >> temp.value;
            ops[ni] = temp;
            if (temp.ddl > maxDDL) 
            {
                maxDDL = temp.ddl;
            }
        }

        if (maxDDL == 0) {
            cout << 0 << endl;
            continue;
        }

        long long* busyTime = new long long[maxDDL + 1];

        for (int ti = 0; ti <= maxDDL; ++ti) 
        {
            busyTime[ti] = 0;
        }

        sort(ops, ops + N, compareWork);


        //for(int i = 0;i < N;i++) cout<<ops[i].ddl<<" "<<ops[i].value<<" ";

        for (int i = 0;i < N;i++)
        {
            int flag = 0;
            long long occupyTime = 0;
            if (ops[i].ddl <= maxDDL)
            {
                for (long long t = ops[i].ddl; t >= 1; t--)
                {
                    if (busyTime[t] == 0)
                    {
                        flag = 1;
                        occupyTime = t;
                        break;
                    }
                }
            }
            if (flag == 1)
            {
                maxValue += ops[i].value;
                busyTime[occupyTime] = 1;
            }
        }
        
        cout << maxValue << endl;
    }
    return 0;
}
