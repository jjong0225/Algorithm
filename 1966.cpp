#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<list>
#include<stack>
#include<queue> // priority_queue 포함
#include<set>
#include<deque>
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

void solution()
{
    int n;
    cin >> n;
    for(int count = 0; count < n; count++)
    {
        int n, m;
        cin >> n >> m;
        vector<int> v;
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++)
        {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
            q.push(make_pair(tmp,i));
        }
        sort(v.begin(), v.end(),greater<int>());
        int now_idx = 0;
        for(int i=0; i<n; i++)
        {
            while(!q.empty() && q.front().first != v[now_idx])
            {
                pair<int,int> tmp = q.front();
                q.pop();
                q.push(tmp);
            }
            if(q.front().second == m)
            {
                cout << now_idx+1 << "\n";
            }
            q.pop();
            now_idx++;
        }
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