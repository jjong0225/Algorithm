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
    int n;
    cin >> n;
    vector<vector<int>> input_map;
    vector<vector<lld>> checker_v;
    for(int i=0; i<n; i++)
    {
        vector<int> tmp_v;
        vector<lld> tmp_v_2;
        for(int j=0; j<n; j++)
        {
            int tmp_c;
            cin >> tmp_c;
            tmp_v.push_back(tmp_c);            
            tmp_v_2.push_back(0);
        }
        input_map.push_back(tmp_v);
        checker_v.push_back(tmp_v_2);
    }

    queue<array<int,3>> q;
    q.push({0,0,0});
    checker_v[0][0] = 1;
    const int offset[2][2] = {{1,0}, {0,1}};
    uld output = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int jump_dis = input_map[i][j];
            if(jump_dis == 0)
                continue;
            for(int k=0; k<2; k++)
            {
                int now_row = i + jump_dis * offset[k][0];
                int now_col = j + jump_dis * offset[k][1];
                if(now_row >= 0 && now_row < n && now_col >= 0 && now_col < n)
                    checker_v[now_row][now_col] += checker_v[i][j];
            }
        }
    }
    cout << checker_v[n-1][n-1];
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}