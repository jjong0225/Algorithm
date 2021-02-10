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
const int offset[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
int N,M;
int output = 1;
char input_map[22][22] = {0};

void dfs (int param_row, int param_col, int dist, int prev_set[27])
{
    output = max(output, dist);
    for(int i=0; i<4; i++)
    {
        int next_row = param_row + offset[i][0];
        int next_col = param_col + offset[i][1];
        if(next_row >= 0 && next_row < N && next_col >= 0 && next_col < M)
        {
            char tmp_c = input_map[next_row][next_col] - 'A';
            if(prev_set[tmp_c] == 0)
            {
                int next_set[27]= {0};
                for(int j=0; j<27; j++)
                    next_set[j] = prev_set[j];
                next_set[tmp_c] = 1;
                dfs(next_row, next_col, dist+1, next_set);
            }
        }
    }
}


void solution()
{
    // code
    cin >> N >> M;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> input_map[i][j];

    int init_set[27] = {0};
    int init_idx = input_map[0][0]-'A';
    init_set[init_idx] = 1;
    dfs(0,0,1,init_set);
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