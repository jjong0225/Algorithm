#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
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
    int n; // 200,000
    cin >> n;
    vector<vector<ui>> pq_v;
    priority_queue<ui> pq; 
    lld result = 0;
    for(int i=0; i<=n; i++)
    {
        vector<ui> tmp_v;
        pq_v.push_back(tmp_v);
    }
    for(int i=0; i<n; i++)
    {
        lld a,b = 0;
        cin >> a >> b;
        pq_v[a].push_back(b);
    }
    for(int i=n; i>=1; i--)
    {
        for(int j=0; j<pq_v[i].size(); j++)
            pq.push(pq_v[i][j]);
        if(!pq.empty())
        {
            result += pq.top();
            pq.pop();
        }
    }
    cout << result;
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}