#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<list>
#include<stack>
#include<queue> // priority_queue 포함
#include<set>
#include<deque>
#include<unordered_set>
#include<map>
#include<unordered_map>

#include<algorithm>
#include<math.h>
#include<climits> // 자료형 limit포함

using namespace std;

typedef long long int lld;
typedef unsigned long long int uld;
typedef unsigned int ui;

const int MY_INT_MAX = 2000000000;

int dp[1000001] = {0};

void solution()
{
    int n, m;
    cin >> n >> m;
    dp[0] = 3, dp[1] = 3;
    for(int i=2; i<=m; i++)
    {
        if(dp[i] == 0)
        {
            int now_d = 2;
            while(i*now_d <= m)
            {
                dp[i*now_d]++;
                now_d++;
            }
        }
    }
    for(int i=n; i<=m; i++)
    {
        if(dp[i] == 0)
            cout << i << "\n";
    }
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}