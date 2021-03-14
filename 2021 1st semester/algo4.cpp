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

void solution()
{
    // code
    int n,m;
    cin >> n >> m;
    vector<vector<int>> graph_v;
    vector<int> input_v;
    for(int i=0; i<n; i++)
    {
        vector<int> tmp_v;
        int a;
        cin >> a;
        input_v.push_back(a);
        graph_v.push_back(tmp_v);
    }
    for(int i=0; i<m; i++)
    {
        int a,b;
        cin >> a >> b;
        a--, b--;
        graph_v[a].push_back(b);
        graph_v[b].push_back(a);
    }
    int output = 0;
    for(int i=0; i<n; i++)
    {
        int flag = 0;
        for(int j=0; j<graph_v[i].size(); j++)
        {
            if(input_v[i] <= input_v[graph_v[i][j]])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            output++;
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