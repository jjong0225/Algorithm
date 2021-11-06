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

void solution()
{
    // code
    vector<array<int,4>> dp;
    int n;
    cin >> n;
    vector<int> input_v;
    int max_idx = 0;
    for(int i=0; i<n; i++)
    {
        int tmp_input = 0;
        cin >> tmp_input;
        max_idx = max(max_idx, tmp_input);
        input_v.push_back(tmp_input);
    }
    for(int i=0; i<=max_idx; i++)
    {
        array<int,4> tmp_arr = {0};
        dp.push_back(tmp_arr);
    }
    dp[1][0] = 1, dp[1][1] = 1, dp[1][2] = 1, dp[1][3] = 1;
    dp[2][0] = 2, dp[2][1] = 1, dp[2][2] = 2, dp[2][3] = 5; 
    for(int i=3; i<=max_idx; i++)
    {
        dp[i][0] = dp[i-1][3] + dp[i-1][2];
        dp[i][1] = dp[i-1][3] + dp[i-2][1];
        dp[i][2] = dp[i-1][3] + dp[i-1][0];
        dp[i][3] = dp[i-2][3] + dp[i-1][3] + dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
    }
    for(int i=0; i<input_v.size(); i++)
    {
        cout << dp[input_v[i]][3] << endl;
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