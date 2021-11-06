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
vector<vector<pair<int,int>>> input_v;
int start_idx, end_idx;

bool is_possible(int parma_length)
{
    queue<int> q;
    q.push(start_idx);
    bool check_arr[10001] = {0};
    check_arr[start_idx] = 1;
    while(!q.empty())
    {
        int now_idx = q.front();
        q.pop();
        if(now_idx == end_idx)
            return true;
        for(int i=0; i<input_v[now_idx].size(); i++)
        {
            if(check_arr[input_v[now_idx][i].first] == 0 && input_v[now_idx][i].second >= parma_length)
            {
                check_arr[input_v[now_idx][i].first] = 1;
                q.push(input_v[now_idx][i].first);
            }
        }
    }
    return false;
}


void solution()
{
    // code
    int n,m;
    cin >> n >> m;
    for(int i=0; i<=n; i++)
    {
        vector<pair<int,int>> tmp_v;
        input_v.push_back(tmp_v);
    }
    for(int i=0; i<m; i++)
    {
        int a,b,c;
        cin >> a >> b >> c; 
        input_v[a].push_back(make_pair(b,c));
        input_v[b].push_back(make_pair(a,c));
    }
    cin >> start_idx >> end_idx;
    int low = 0, high = 1000000001;
    int output = 0;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(is_possible(mid))
        {
            output = max(output, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
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