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
int n;
int input_map[21][21] = {0};
int visited[21] = {0};

int dfs(int now_d, int prev_1, int prev_2)
{
    // cout << "ff";
    if(prev_1 > n/2 || prev_2 > n/2)
        return MY_INT_MAX;
    else if(prev_1 == n/2 && prev_2 == n/2)
    {
        int sum_1 = 0, sum_2 = 0;
        vector<int> v_1, v_2;
        for(int i=0; i<n; i++)
        {
            if(visited[i] == 1)
                v_1.push_back(i);
            else if (visited[i] == 2)
                v_2.push_back(i);
        }
        for(int i=0; i<v_1.size(); i++)
            for(int j=i+1; j<v_1.size(); j++)
                sum_1 += (input_map[v_1[i]][v_1[j]] + input_map[v_1[j]][v_1[i]]);
        for(int i=0; i<v_2.size(); i++)
            for(int j=i+1; j<v_2.size(); j++)
                sum_2 += (input_map[v_2[i]][v_2[j]] + input_map[v_2[j]][v_2[i]]);
        return abs(sum_1-sum_2);
    }
    int output = MY_INT_MAX;
    if(prev_1 < n/2)
    {
        visited[now_d] = 1;
        output = min(output,dfs(now_d+1, prev_1 + 1, prev_2));
    }
    if(prev_2 < n/2)
    {
        visited[now_d] = 2;
        output = min(output, dfs(now_d+1, prev_1, prev_2 + 1));
    }
    visited[now_d] = 0;
    return output;
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> input_map[i][j];

    
    cout << dfs(0,0,0);

    return 0;
}