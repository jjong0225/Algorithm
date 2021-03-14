#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<stack>
#include<queue> // priority_queue 포함
#include<set>
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
int dp[1000000] = {0};
int dp_2[1000000] = {0};

void solution()
{
    // code
    int n;
    cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    int now_idx = 2;
    while(dp[now_idx] <= n)
    {
        ++now_idx;
        dp[now_idx] = dp[now_idx-1] + dp[now_idx-2];
    }
    int min_output = 0;
    int max_output = 0;
    int tmp_c = n;
    if(tmp_c % 2 == 1)
    {
        tmp_c -= 3;
        min_output += 2;
    }
    min_output += tmp_c/2;
    tmp_c = n;
    dp_2[2] = 1;
    dp_2[3] = 2;
    dp_2[4] = 2;
    dp_2[5] = 3;
    dp_2[6] = 4;

    for(int i=7; i<=n; i++)
    {
        int now_max = -1;
        int tmp_idx = 2;
        while(dp[tmp_idx] <= i)
        {
            now_max = max(now_max, dp_2[dp[tmp_idx]] + dp_2[i - dp[tmp_idx]]);
            tmp_idx++;
        }
        dp_2[i] = now_max;
    }
    cout << min_output << " " << dp_2[n];
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}