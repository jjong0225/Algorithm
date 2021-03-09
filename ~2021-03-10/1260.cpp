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

void solution()
{
    // code
    int N, M, V;
    cin >> N >> M >> V;
    vector<vector<int>> e_v;
    vector<int> check_v;
    for(int i=0; i<=N; i++)
    {
        vector<int> tmp_v;
        e_v.push_back(tmp_v);
        check_v.push_back(0);
    }
    for(int i=0; i<M; i++)
    {
        int a,b;
        cin >> a >> b;
        e_v[a].push_back(b);
        e_v[b].push_back(a);
    }
    for(int i=0; i<=N; i++)
        sort(e_v[i].begin(),e_v[i].end(), less<int>());
    queue<int> q;
    stack<int> s;
    q.push(V);

    vector<int> bfs_v;
    vector<int> dfs_v;

    //bfs
    while(!q.empty())
    {
        int now_v = q.front();
        q.pop();
        if(check_v[now_v] == 1)
            continue;
        check_v[now_v] = 1;
        bfs_v.push_back(now_v);
        for(int i=0; i<e_v[now_v].size(); i++)
        {
            if(check_v[e_v[now_v][i]] == 0)
                q.push(e_v[now_v][i]);
        }
    }


    // dfs
    fill(check_v.begin(), check_v.end(),0);
    s.push(V);
    while(!s.empty())
    {
        int now_v = s.top();
        s.pop();
        if(check_v[now_v] == 1)
            continue;
        check_v[now_v] = 1;
        dfs_v.push_back(now_v);
        for(int i=e_v[now_v].size()-1; i>=0; i--)
        {
            if(check_v[e_v[now_v][i]] == 0)
                s.push(e_v[now_v][i]);
        }
    }


    for(int i=0;i<dfs_v.size();i++)
        cout << dfs_v[i] << " ";
    cout << "\n";
    for(int i=0;i<bfs_v.size();i++)
        cout << bfs_v[i] << " ";
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}