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


int dp[5][101][101] = {0};
int input_map[101][101] = {0};

int max_int = 1000000000;
void solution()
{
    // code
    int n, m, start_row, end_row, start_col, end_col, start_dir, end_dir;
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> input_map[i][j];
        }
    }
    cin >> start_row >> start_col >> start_dir;
    cin >> end_row >> end_col >> end_dir;
    start_row--, start_col--,  end_row--, end_col--;

    queue<array<int,4>> q;
    q.push({start_row, start_col, start_dir,0});
    const int idx_pair[5][2] = {{0,0}, {0,1}, {0,-1}, {1, 0}, {-1,0}}; // 0
    while(!q.empty())
    {
        array<int,4> now_stat = q.front();
        q.pop();
        int now_row = now_stat[0];
        int now_col = now_stat[1];
        int now_dir = now_stat[2];
        int now_dis = now_stat[3];
        if(dp[now_dir][now_row][now_col] != 0)
            continue;
        if(now_row == end_row && now_col == end_col && now_dir == end_dir)
        {
            dp[now_dir][now_row][now_col] = now_dis;
            break;
        }
        else
            dp[now_dir][now_row][now_col] = now_dis;


        int move_row = idx_pair[now_dir][0];
        int move_col = idx_pair[now_dir][1];

        for(int i=1; i<=3; i++)
        {
            int next_row = now_row+move_row*i;
            int next_col = now_col+move_col*i;
            if(next_row >= 0 && next_row < n && next_col >= 0 && next_col < m && input_map[next_row][next_col] == 0 && dp[now_dir][next_row][next_col] == 0)
                q.push({next_row, next_col, now_dir, now_dis+1});
            else
                break;
        }


        for(int i=1; i<=4; i++)
        {
            int next_dir = i;
            if(next_dir != now_dir && dp[next_dir][now_row][now_col] == 0)
            {
                if((now_dir ==1 && next_dir == 2) || (now_dir ==2 && next_dir == 1) || (now_dir==3 && next_dir == 4) || (now_dir==4 && next_dir == 3))
                    q.push({now_row, now_col, next_dir, now_dis+2});
                else
                    q.push({now_row, now_col, next_dir, now_dis+1});
            }
        }


    }
    cout << dp[end_dir][end_row][end_col];
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}