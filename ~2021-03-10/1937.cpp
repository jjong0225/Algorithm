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
vector<vector<int>> input_map;
vector<vector<int>> dp;
const int offset[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
int n;

int dfs(int param_row, int param_col)
{
    int output = 0;
    int prev_val = input_map[param_row][param_col];
    for(int i=0; i<4; i++)
    {
        int next_row = param_row + offset[i][0];
        int next_col = param_col + offset[i][1];
        if(next_row >= 0 && next_row < n && next_col >= 0 && next_row < n)
        {
            if(prev_val < input_map[next_row][next_col])
            {
                if(dp[next_row][next_col] != 0) 
                    output=max(output, dp[next_row][next_col]+1);
                else
                    output=max(output, dfs(next_row, next_col)+1);
            }
        }
    }
    dp[param_row][param_col] = output;
    return output;
}

void solution()
{
    // code
    cin >> n;
    for(int i=0; i<n; i++)
    {
        vector<int> tmp_v;
        vector<int> tmp_v_2;
        for(int j=0; j<n; j++)
        {
            int tmp_in;
            cin >> tmp_in;
            tmp_v.push_back(tmp_in);
            tmp_v_2.push_back(0);
        }
        input_map.push_back(tmp_v);
        dp.push_back(tmp_v_2);
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            dfs(i,j);

    int output = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            output = max(output, dp[i][j]);

    cout << output+1;
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}