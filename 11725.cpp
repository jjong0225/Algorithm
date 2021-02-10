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

typedef struct node
{
    int data;
    vector<struct node *>children;
}Node;

void solution()
{
    // code
    int n;
    cin >> n;
    vector<vector<int>> E;
    vector<int> checker;
    for(int i=0; i<=n; i++)
    {
        vector<int> tmp_v;
        E.push_back(tmp_v);
        checker.push_back(0);
    }
    for(int i=1; i<n; i++)
    {
        int in_1, in_2;
        cin >> in_1 >> in_2;
        E[in_1].push_back(in_2);
        E[in_2].push_back(in_1);
    }
    queue<int> q;
    q.push(1);
    checker[1] = 1;
    while(!q.empty())
    {
        int now_idx = q.front();
        q.pop();
        for(int i=0; i<E[now_idx].size(); i++)
        {
            if(checker[E[now_idx][i]] == 0)
            {
                checker[E[now_idx][i]] = now_idx;
                q.push(E[now_idx][i]);
            }
        }
    }
    for(int i=2; i<=n; i++)
        cout << checker[i] << "\n";
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}