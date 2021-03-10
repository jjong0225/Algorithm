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
int input_map[101][101] = {0};
int cheese_number_map[101][101] = {0};
int visited_map[101][101] = {0};
int offset_line[8][2] = {{0,1}, {0,-1}, {1,1}, {1,0}, {1,-1}, {-1,1}, {-1,0}, {-1,-1}};
int offset[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
int N,M;

void bfs_boundary(int param_i, int param_j)
{
    int cheese_num = 1;
    cheese_number_map[param_i][param_j] = cheese_num;
    queue<pair<int,int>> q;
    q.push(make_pair(param_i, param_j));
    while(!q.empty())
    {
        int current_i = q.front().first;
        int current_j = q.front().second;
        q.pop();
        for(int i=0; i<4; i++)
        {
            int next_i = current_i + offset[i][0];
            int next_j = current_j + offset[i][1];
            if(next_i >= 0 && next_i < N && next_j >=0 && next_j < M && input_map[next_i][next_j] == 0 && visited_map[next_i][next_j] == 0)
            {
                visited_map[next_i][next_j] = 1;
                bfs_boundary(next_i, next_j);
            }
        }
    }
}

void bfs(int param_i, int param_j)
{
    int counter = 0;
    for(int i=0; i<4; i++)
    {
        int next_i = param_i + offset[i][0];
        int next_j = param_j + offset[i][1];
        if(next_i >= 0 && next_i < N && next_j >=0 && next_j < M && cheese_number_map[next_i][next_j] == 1)
            counter++;
    }
    if(counter >= 1)
        cheese_number_map[param_i][param_j] = -1;

    queue<pair<int,int>> q;
    q.push(make_pair(param_i, param_j));
    while(!q.empty())
    {
        int current_i = q.front().first;
        int current_j = q.front().second;
        q.pop();
        for(int i=0; i<8; i++)
        {
            int next_i = current_i + offset_line[i][0];
            int next_j = current_j + offset_line[i][1];
            if(next_i >= 0 && next_i < N && next_j >=0 && next_j < M && cheese_number_map[next_i][next_j] == 0 && visited_map[next_i][next_j] == 0)
            {
                visited_map[next_i][next_j] = 1;
                bfs(next_i, next_j);
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

    int output = 0;
    int prev_count = -1;
    while(1)
    {
        output++;
        int tmp_count = 0;
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cheese_number_map[i][j] = 0, visited_map[i][j] = 0;

        bfs_boundary(0,0);

        int flag = 0 ;

        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                visited_map[i][j] = 0;


        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(cheese_number_map[i][j] == 0 && visited_map[i][j] == 0)
                {
                    visited_map[i][j] = 1;
                    bfs(i,j);
                }
            }
        }

        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                if(cheese_number_map[i][j] == -1)
                {
                    input_map[i][j] = 0;
                    tmp_count++;
                }

        if(tmp_count != 0)
            prev_count = tmp_count;
        else
            break;
    }
    cout << output-1 << endl;
    cout << prev_count << endl;
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}