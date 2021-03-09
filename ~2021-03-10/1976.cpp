/*
10000 : 10^4
O N^2상관ㄴ

루트노드는 1
간선의 가중치는 0 <= W <= 100

*/



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

int n;
vector<vector<pair<int,int>>> input_tree;
vector<int> output_v;

int dfs(int node_idx, int path_w)
{
    int output = -1;
    if(input_tree[node_idx].size() == 0)
        return 0;
    int first_one=-1;
    int second_one=-1;
    for(int i=0; i<input_tree[node_idx].size(); i++)
    {
        int tmp = dfs(input_tree[node_idx][i].first, path_w+input_tree[node_idx][i].second)+input_tree[node_idx][i].second;
        if(tmp >= first_one)
        {
            int tmp_2 = first_one;
            first_one = tmp;
            second_one = tmp_2;
        }
        else if (tmp > second_one)
            second_one = tmp;
    }
    if(first_one > 0 && second_one > 0)
        output_v.push_back(first_one + second_one);
    output_v.push_back(first_one);
    return first_one;
}

void solution()
{
    // code
    cin >> n;
    for(int i=0; i<=n; i++)
    {
        vector<pair<int,int>> tmp_v;
        input_tree.push_back(tmp_v);
    }
    for(int i=1; i<n; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        input_tree[a].push_back(make_pair(b,c));
    }
    if(n == 1)
    {
        cout << "0";
        return;
    }
    dfs(1,0);
    sort(output_v.begin(), output_v.end(), greater<int>());
    cout << output_v[0];
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}