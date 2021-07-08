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
int n,m,p;
queue<array<int,3>> q;
int input_map[1001][1001] = {0};
int offset[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
lld s_k[10] = {0};

void bfs()
{
    queue<array<int,3>> tmp_q;
    int now_p = q.front()[2];
    while(!q.empty())
    {
        array<int,3> insert_arr = q.front();
        if(insert_arr[2] != now_p)
            break;
        q.pop();
        insert_arr[2] = s_k[now_p];
        tmp_q.push(insert_arr);
    }
    while(!tmp_q.empty())
    {
        array<int,3> tmp_arr = tmp_q.front();
        tmp_q.pop();
        if(tmp_arr[2] == 0)
        {
            tmp_arr[2] = now_p;
            q.push(tmp_arr);
            continue;
        }
        for(int i=0; i<4; i++)
        {
            int next_y = tmp_arr[0]+offset[i][0];
            int next_x = tmp_arr[1]+offset[i][1];
            if( next_y >= 0 && next_y < n && next_x >= 0 && next_x < m && input_map[next_y][next_x] == 0)
            {
                input_map[next_y][next_x] = now_p;
                array<int,3> insert_arr = {next_y, next_x, tmp_arr[2]-1};
                tmp_q.push(insert_arr);
            }
        }
    }
}


void solution()
{
    // code
    vector<vector<pair<int,int>>> input_v;
    queue<array<int,3>> input_q;
    cin >> n >> m >> p;
    for(int i=1; i<=p; i++)
    {
        cin >> s_k[i];
        vector<pair<int,int>> tmp_v;
        input_v.push_back(tmp_v);
    }
    vector<pair<int,int>> tmp_v;
    input_v.push_back(tmp_v);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            char tmp_c;
            cin >> tmp_c;
            if(tmp_c >= '0' && tmp_c <= '9')
            {
                input_map[i][j] = tmp_c - '0';
                input_v[tmp_c-'0'].push_back(make_pair(i,j));
            }
            else if(tmp_c == '.')
                input_map[i][j] = 0;
            else if(tmp_c == '#')
                input_map[i][j] = -1;
        }
    }
    for(int i=1; i<=p; i++)
    {
        for(int j=0; j<input_v[i].size(); j++)
        {
            array<int,3> tmp_arr = {input_v[i][j].first, input_v[i][j].second,i};
            q.push(tmp_arr);
        }
    }

    while(!q.empty())
    {
        array<int,3> tmp_arr = q.front();
        bfs();
    }

    int result[10] = {0};
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(input_map[i][j] > 0)
                result[input_map[i][j]]++;
        }
    }
    for(int i=1; i<=p; i++)
        cout << result[i] << " ";
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}