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
int input_map[16][16] = {0};
int n;
int min_gan = 0;
int init_visited = 0;
int dp[65536] = {0};

int bitdp(int visited)
{
    if(dp[visited] != 0)
        return dp[visited];
    vector<int> visited_v;
    vector<int> unvisited_v;

    for(int i=0; i<n; i++)
    {
        if((visited >> i)%2 == 1)
            visited_v.push_back(i);
        else
            unvisited_v.push_back(i);
    }

    int output = MY_INT_MAX;

    for(int j=0; j<unvisited_v.size(); j++) // 모든 unvisited에 대하여
    {
        int prev_idx = -1;
        for(int i=0; i<visited_v.size(); i++) // 어떤 노드가 unvisited node로의 간선이 최소인지 찾는다
        {
            if(input_map[visited_v[i]][unvisited_v[j]] != 0)
            {
                if(prev_idx == -1 || input_map[visited_v[prev_idx]][unvisited_v[j]] > input_map[visited_v[i]][unvisited_v[j]])
                    prev_idx = i;
            }
        }

        if(prev_idx != -1)
        {
            if(visited_v.size() + 1 == min_gan)
                output = min(output, input_map[visited_v[prev_idx]][unvisited_v[j]]);
            else
            {
                int next_bit = visited | 1 << unvisited_v[j];
                output = min(output, bitdp(next_bit) + input_map[visited_v[prev_idx]][unvisited_v[j]]);
            }
        }
    }
    dp[visited] = output;
    return output;
}

void solution()
{
    // code
    cin >> n;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> input_map[i][j];
    string input_str;
    cin >> input_str;
    for(int i=0; i<input_str.size(); i++)
    {
        if(input_str.at(i) == 'Y')
            init_visited += (1 << i);
    }
    cin >> min_gan;
    if(n == 1)
    {
        if(input_str.at(0) == 'Y')
            cout << 0;
        else
            cout << -1;
        return;
    }

    int output = bitdp(init_visited);
    if(output >= MY_INT_MAX)
        cout << -1;
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