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
    int n;
    cin >> n;
    vector<vector<int>> friend_v;
    vector<int> output_v;
    vector<int> check_v;
    for(int i=0; i<=n; i++)
    {
        vector<int> tmp_v;
        friend_v.push_back(tmp_v);
        output_v.push_back(1000000000);
        check_v.push_back(0);
    }
    for(int i=1; i<=n; i++)
    {
        int a = -1;
        while(1)
        {
            cin >> a;
            if(a == 0)
                break;
            friend_v[i].push_back(a);
        }
    }
    int c;
    cin >> c;
    queue<pair<int,int>> q; 
    for(int i=0; i<c; i++)
    {
        int rb;
        cin >> rb;
        q.push(make_pair(rb,0));
    }
    while(!q.empty())
    {
        pair<int,int> now_r = q.front();
        q.pop();
        if (output_v[now_r.first] != 1000000000)
            continue;
        int cmp_num = -1;
        if(friend_v[now_r.first].size() % 2 == 0)
            cmp_num = friend_v[now_r.first].size() / 2;
        else
            cmp_num = friend_v[now_r.first].size() / 2 + 1;
        
        if((++check_v[now_r.first]) >= cmp_num || now_r.second == 0)
        {
            output_v[now_r.first] = now_r.second;
            for(int i=0; i<friend_v[now_r.first].size(); i++)
            {
                if(output_v[friend_v[now_r.first][i]] == 1000000000)
                    q.push(make_pair(friend_v[now_r.first][i], now_r.second+1));
            }
        }

    }
    for(int i=1; i<=n; i++)
    {
        if(output_v[i] == 1000000000)
            cout << "-1 ";
        else
            cout << output_v[i] << " ";
    }
    
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}