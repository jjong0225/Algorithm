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
int input_map[18][18] = {0};
int dp[16][65536] = {0};
int all_visited_bit = 0;

/*
[k][visited]에서 현재 k점에 visited상태 일 때, 그로 부터 모든 도시를 도는데 필요한 최소 dist
그럼 1은 맨 마지막에 어떻게 생각하지?
모든 점에 대해서 all visited 상태일 때 1로 갈 때 최소 거리
*/
int n;

int TSP(int now_pos, int visited)
{
    if(dp[now_pos][visited] != 0)
        return dp[now_pos][visited];

    int output = MY_INT_MAX;
    for(int i=1; i<n; i++)
    {
        if(input_map[now_pos][i] != 0)
        {
            int is_visited = (visited >> i) % 2;
            if(is_visited == 0)
            {
                int next_visited = visited + (1 << i);
                if(next_visited == all_visited_bit)
                {
                    if(input_map[now_pos][i] != 0 && input_map[i][0] != 0)
                        output = min(output, input_map[now_pos][i] + input_map[i][0]);
                }
                else
                    output = min(output, TSP(i,next_visited) + input_map[now_pos][i]);
            }
        }
    }
    dp[now_pos][visited] = output;
    return output;
}

void solution()
{
    // code
    cin >> n;
    for(int i=0; i<n; i++) 
        for(int j=0; j<n; j++)
            cin >> input_map[i][j];

    all_visited_bit = 1;
    for(int i=1; i<n; i++) 
        all_visited_bit += (1 << i);
    cout <<TSP(0,1);
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}