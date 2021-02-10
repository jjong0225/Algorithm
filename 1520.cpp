/*
dfs로 travle하고 
dp[y][x] = (y, x) 지점일 때 존재하는 경로의 갯수

왜 dfs? bfs는 왜 안되지?
bfs는 모든 경로를 다 탐색하기 때문에?
bfs로 checker를 이용해 이미 탐색한 곳을 탐색하지 않는다면?
    -> 그럼 값에 대한 업데이트가 제대로 이루어지지 않음

dfs는 뭐가 달라?
    travle -> travle -> travle -> 끝
                        연산
                연산
        연산

    -> 이렇게 하므로 자신을 통해 갔다온 path에 대해 업데이트가 가능하다

하지만 bfs는?
    travle -> travle -> travle -> 끝
    연산
                연산
                        연산
    -> 이전 path에 대해 현재 상태에서 업데이트르 진행함
    -> 따라서 같은 노드를 다른 타이밍에 만나게 된 다면 dp를 사용할 수 없다는것

+ bfs의 경우 queue를 통해 idx를 저장해 travle하므로 메모리 소비가 크다 -> breath만큼 메모리 필요
(반면 dfs의 경우 dfs를 이용하므로 메모리 소비가 적다 -> depth만큼 메모리가 필요)

흔치 않은 dfs문제
*/



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

const int offset[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int input_map[502][502] = {0};
int dp[502][502] = {0};
int N,M;

int dfs(int param_row, int param_col)
{
    int output = 0;
    int prev_val = input_map[param_row][param_col];
    for(int i=0; i<4; i++)
    {
        int next_row = param_row + offset[i][0];
        int next_col = param_col + offset[i][1];
        if(next_row >= 0 && next_row < N && next_col >=0 && next_col < M)
        {
            int next_val = input_map[next_row][next_col];
            if(prev_val > next_val)
            {
                if(dp[next_row][next_col] == 0)
                    output += dfs(next_row, next_col);
                else if(dp[next_row][next_col] != -1)
                    output += dp[next_row][next_col];
            }
        }
    }
    if(output == 0)
        dp[param_row][param_col] = -1;
    else
        dp[param_row][param_col] = output;
    return output;
}


int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.

    cin >> N >> M;  
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            int tmp_d;
            cin >> tmp_d;
            input_map[i][j] = tmp_d;
        }
    }
    memset(dp,0,sizeof(dp));
    dp[N-1][M-1] = 1;
    dfs(0,0);
    if(dp[0][0] == -1)
        cout << 0;
    else
        cout << dp[0][0];

    return 0;
}