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

vector<vector<int>> input_map;
int checker[4][101][101] = {0};
int my_max = 1000000000;
void solution()
{
    // code
    int W, H;
    cin >> W >> H;
    pair<int,int> pos[2] = {{0,0},{0,0}};
    int pos_count = 0;
    for(int i=0; i<H; i++)
    {
        vector<int> tmp_v;
        for(int j=0; j<W; j++)
        {
            char input_c;
            cin >> input_c;
            if(input_c == '.')
                tmp_v.push_back(0);
            else if(input_c == '*')
                tmp_v.push_back(1);
            else if(input_c == 'C')
            {
                pos[pos_count++] = make_pair(i,j);
                tmp_v.push_back(0);
            }
            checker[0][i][j] = my_max;
            checker[1][i][j] = my_max;
            checker[2][i][j] = my_max;
            checker[3][i][j] = my_max;
        }
        input_map.push_back(tmp_v);
    }

    // 4개 방향으로 움직일 수 있다.
    const int idx[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    queue<array<int,4>> q;
    q.push({pos[0].first,pos[0].second,0,0}), q.push({pos[0].first,pos[0].second,1,0}), q.push({pos[0].first,pos[0].second,2,0}),q.push({pos[0].first,pos[0].second,3,0});
    while(!q.empty())
    {
        array<int,4> top_arr = q.front();
        q.pop();
        int now_row = top_arr[0];
        int now_col = top_arr[1];
        int now_dir = top_arr[2];
        int now_dis = top_arr[3];
        int i=1;
        while(1)
        {
            int next_row = now_row + i*idx[now_dir][0];
            int next_col = now_col + i*idx[now_dir][1];
            if(next_row >= 0 && next_row < H && next_col >= 0 && next_col < W && input_map[next_row][next_col] == 0)
            {
                if(checker[now_dir][next_row][next_col] > now_dis)
                {
                    q.push({next_row,next_col,now_dir,now_dis});
                    checker[now_dir][next_row][next_col] = now_dis;
                }
            }
            else
                break;
            i++;
        }
        if(checker[(now_dir+1)%4][now_row][now_col] > now_dis+1)
        {
            q.push({now_row,now_col,(now_dir+1)%4, now_dis+1});
            checker[(now_dir+1)%4][now_row][now_col] = now_dis+1;
        }
        if(checker[(now_dir+3)%4][now_row][now_col] > now_dis+1)
        {
            q.push({now_row,now_col,(now_dir+3)%4, now_dis+1});
            checker[(now_dir+3)%4][now_row][now_col] = now_dis+1;
        }
    }
    int output = 1000000000;
    for(int i=0; i<4; i++)
        output = min(output,checker[i][pos[1].first][pos[1].second]);
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