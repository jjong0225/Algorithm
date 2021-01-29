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


// 2 ≤ M ≤ 100, 2 ≤ N ≤ 100, 1 ≤ H ≤ 100 
int input_map[102][102][102] = {0};

void solution()
{
    // code
    int M, N, H; // h : 높이, n : 세로, m : 가로
    cin >> M >> N >> H;
    queue<array<int,4>> q;
    for(int i=0; i<H; i++)
    {
        for(int j=0; j<N; j++)
        {
            for(int k=0; k<M; k++)
            {
                cin >> input_map[i][j][k];
                if(input_map[i][j][k] == 1)
                    q.push({i,j,k,1});
            }
        }
    }
    const int offset_idx[6][3] = {{1,0,0}, {-1,0,0}, {0,1,0}, {0,-1,0}, {0,0,1}, {0,0,-1}};
    while(!q.empty())
    {
        array<int,4> now_tomato = q.front();
        q.pop();
        for(int i=0; i<6; i++)
        {
            int now_height = now_tomato[0] + offset_idx[i][0];
            int now_row = now_tomato[1] + offset_idx[i][1];
            int now_col = now_tomato[2] + offset_idx[i][2];
            if(now_height >= 0 && now_height < H && now_row >= 0 && now_row < N && now_col >= 0 && now_col < M && input_map[now_height][now_row][now_col] == 0)
            {
                input_map[now_height][now_row][now_col] = now_tomato[3]+1;
                q.push({now_height, now_row, now_col, now_tomato[3]+1});
            }
        }
    }
    int output_max = 0;
    for(int i=0; i<H; i++)
    {
        for(int j=0; j<N; j++)
        {
            for(int k=0; k<M; k++)
            {
                if(input_map[i][j][k] == 0)
                {
                    cout << "-1";
                    return;
                }
                else if(input_map[i][j][k] != -1)
                    output_max = max(output_max, input_map[i][j][k]);
            }
        }
    }
    if(output_max == 1)
        cout << "0";
    else
        cout << output_max-1;
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}