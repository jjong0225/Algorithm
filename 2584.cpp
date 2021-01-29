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


int input_map[102][102] = {0};

void solution()
{
    // code
    int N,M,K;
    cin >> N >> M >> K;
    vector<array<int,4>> input_k;
    for(int i=0; i<K; i++)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        for(int tmp_row = b; tmp_row < d; tmp_row++)
            for(int tmp_col = a; tmp_col < c; tmp_col++)
                input_map[tmp_row][tmp_col] = 1;
    }
    const pair<int,int> offset[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    vector<int> output_v;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(input_map[i][j] == 0)
            {
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                int output = 0;
                while(!q.empty())
                {
                    pair<int,int> tmp_pair = q.front();
                    q.pop();
                    if(input_map[tmp_pair.first][tmp_pair.second] != 0)
                        continue;
                    input_map[tmp_pair.first][tmp_pair.second] = -1;
                    output++;
                    for(int tmp_off = 0; tmp_off < 4; tmp_off++)
                    {
                        int now_row = tmp_pair.first + offset[tmp_off].first;
                        int now_col = tmp_pair.second + offset[tmp_off].second;
                        if(now_row < 0 || now_col < 0 || now_row >= N || now_col >= M || input_map[now_row][now_col] != 0)
                            continue;
                        q.push(make_pair(now_row,now_col));
                    }
                }
                output_v.push_back(output);
            }
        }
    }
    sort(output_v.begin(), output_v.end(), less<int>());
    cout << output_v.size() << endl;
    for(int i=0; i<output_v.size(); i++)
        cout << output_v[i] << " ";
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}