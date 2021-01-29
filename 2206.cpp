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

/*
1 <= n,m <=1,000(10^3)
*/
vector<vector<bool>> input_map;
vector<vector<int>> DP[2];
int N, M;
int max_int = 1000000000;


void solution()
{
    // code
    cin >> N >> M;
    for(int i=0; i<N; i++)
    {
        vector<bool> tmp_v;
        vector<int> tmp_dp;
        for(int j=0; j<M; j++)
        {
            char a;
            cin >> a;
            if(a == '1')
                tmp_v.push_back(false);
            else if(a == '0')
                tmp_v.push_back(true);
            tmp_dp.push_back(max_int);
        }
        input_map.push_back(tmp_v);
        DP[0].push_back(tmp_dp);
        DP[1].push_back(tmp_dp);
    }

    queue<std::array<int,4>> pq;
    std::array<int,4> init_arr = {1,0,0,0};
    pq.push(init_arr);
    while(!pq.empty())
    {
        std::array<int,4> tmp_arr = pq.front();
        pq.pop();
        bool now_flag = tmp_arr[3];
        int now_row = tmp_arr[1];
        int now_col = tmp_arr[2];
        int now_val = tmp_arr[0];

        
        if((DP[now_flag][now_row][now_col] <= now_val) || now_row < 0 || now_row > N-1 || now_col < 0 || now_col > M)
            continue;
        else
            DP[now_flag][now_row][now_col] = now_val;

        if(now_row+1 < N)
        {
            if(input_map[now_row+1][now_col]==1 && DP[now_flag][now_row+1][now_col] > now_val+1)
                pq.push({now_val+1, now_row+1,now_col,now_flag});
            else if(input_map[now_row+1][now_col]==0 && now_flag == 0 && DP[1][now_row+1][now_col] > now_val+1)
                pq.push({now_val+1, now_row+1,now_col,1});
        }
        if(now_row-1 >= 0)
        {
            if(input_map[now_row-1][now_col]==1 && DP[now_flag][now_row-1][now_col] > now_val+1)
                pq.push({now_val+1, now_row-1, now_col, now_flag});
            else if(input_map[now_row-1][now_col]==0 && now_flag == 0 && DP[1][now_row-1][now_col] > now_val+1)
                pq.push({now_val+1, now_row-1, now_col, 1});
        }
        if(now_col+1 < M)
        {
            if(input_map[now_row][now_col+1]==1 && DP[now_flag][now_row][now_col+1] > now_val+1)
                pq.push({now_val+1, now_row, now_col+1, now_flag});
            else if(input_map[now_row][now_col+1] == 0 && now_flag == 0 && DP[1][now_row][now_col+1] > now_val+1)
                pq.push({now_val+1, now_row, now_col+1, 1});
        }
        if(now_col-1 >= 0)
        {
            if(input_map[now_row][now_col-1]==1 && DP[now_flag][now_row][now_col-1] > now_val+1)
                pq.push({now_val+1, now_row, now_col-1, now_flag});
            else if(input_map[now_row][now_col-1]==0 && now_flag == 0 && DP[1][now_row][now_col-1] > now_val+1)
                pq.push({now_val+1, now_row, now_col-1, 1});
        }
    }
    int output = min(DP[0][N-1][M-1],DP[1][N-1][M-1]);
    if(output == max_int)
        cout << "-1";
    else
        cout << output;
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}