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
int n, m, k, s, t;
lld DP[11][100010] = {0};
vector<vector<pair<int,lld>>> input_v(100010);

lld dfs(int start_idx, int chance_num)
{
    if(DP[chance_num][start_idx] != 0)
        return DP[chance_num][start_idx];
    if(start_idx == t && chance_num == 0)
        return 0;
    lld output = -1 * MY_INT_MAX;
    for(int i=0; i<input_v[start_idx].size(); i++)
    {
        int s_i = input_v[start_idx][i].first;
        lld d_j = input_v[start_idx][i].second;
        if(start_idx < s_i) // down slope
            output = max(output, dfs(s_i, chance_num) + d_j);
        else // up slope
        {
            if(chance_num > 0)
                output = max(output, dfs(s_i, chance_num-1));
        }
    }
    DP[chance_num][start_idx] = output;
    return output;
}

void solution()
{
    cin >> n >> m >> k >> s >> t;
    for(int i=0; i<m; i++)
    {
        int a, b;
        lld c;
        cin >> a >> b >> c;
        input_v[a].push_back(make_pair(b,c));
        input_v[b].push_back(make_pair(a,c));
    }
    lld output = dfs(s,k);
    if(output < 0)
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