#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<string>
#include<list>
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
int offset[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

int input_map[32][32] = {0};
int input_map2[32][32] = {0};
int n,m;
vector<vector<pair<int,int>>> input_v;
vector<int> val_v;

void dfs(int y_idx, int x_idx,  int val, int vector_idx)
{
    input_v[vector_idx].push_back(make_pair(y_idx, x_idx));
    input_map[y_idx][x_idx] = 0;

    for(int i=0; i<4; i++)
    {
        int new_y = y_idx + offset[i][0];
        int new_x = x_idx + offset[i][1];
        if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && input_map[new_y][new_x] == val)
        {
            dfs(new_y, new_x, val, vector_idx);
        }
    }
}

void solution()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> input_map[i][j];

    int vector_count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(input_map[i][j] > 0)
            {
                vector<pair<int,int>> tmp_v;
                input_v.push_back(tmp_v);
                val_v.push_back(input_map[i][j]);
                dfs(i,j,input_map[i][j], vector_count);
                vector_count++;
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> input_map2[i][j];
    

    int dif_count = 0;

    for(int i=0; i<input_v.size(); i++)
    {
        int now_val = val_v[i];
        for(int j=0; j<input_v[i].size(); j++)
        {
            int now_y = input_v[i][j].first;
            int now_x = input_v[i][j].second;
            if(input_map2[now_y][now_x] != now_val)
            {
                if(j == 0)
                {
                    now_val = input_map2[now_y][now_x];
                    dif_count++;
                }
                else
                {
                    cout << "NO";
                    return;
                }
            }
        }
    }
    if(dif_count > 1)
        cout << "NO";
    else
        cout << "YES";
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}