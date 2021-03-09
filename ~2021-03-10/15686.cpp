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

int input_m[52][52] = {0};
int output = MY_INT_MAX;
int n,m;
vector<pair<int,int>> chicken_v;
vector<pair<int,int>> house_v;
int path[14] = {0};

int dfs(int now_idx, int now_num)
{
    if(now_num > 0)
        path[now_num] = now_idx;

    if(now_num == m)
    {
        int tmp_val = 0;
        for(int i = 0; i < house_v.size(); i++)
        {
            int tmp_min = MY_INT_MAX;
            for(int j=1; j<=m; j++)
                tmp_min = min(tmp_min, (abs(house_v[i].first - chicken_v[path[j]].first) + abs(house_v[i].second - chicken_v[path[j]].second)));
            tmp_val += tmp_min;
            if(tmp_val > output)
                return 0;
        }
        output = min(output, tmp_val);
    }

    for(int i=now_idx+1; i<chicken_v.size(); i++)
    {
        if(chicken_v.size() - i + now_num >= m)
        {
            dfs(i, now_num+1);
        }
    }

    if(now_num > 0)
        path[now_num] = 0;
    return 0;
}


void solution()
{
    // code
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            cin >> input_m[i][j];
            if(input_m[i][j] == 1)
                house_v.push_back(make_pair(i,j));
            else if(input_m[i][j] == 2)
                chicken_v.push_back(make_pair(i,j));
        }
    dfs(-1,0);
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    cout << output;
    return 0;
}