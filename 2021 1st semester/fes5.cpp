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

struct my_cmp
{
    bool operator()(array<int,3> lp, array<int,3> rp)
    {
        if(lp[0] != rp[0])
            return lp[0] > rp[0];
        else if(lp[1] != rp[1])
            return lp[1] < rp[1];
        else
            return lp[2] > rp[2];
    }
};

void solution()
{
    // code
    int n,m;
    cin >> m >> n;
    vector<vector<int>> input_map;
    vector<vector<int>> dp;
    priority_queue<array<int,3>, vector<array<int,3>>, my_cmp> pq;
    for(int i=0; i<n; i++)
    {
        vector<int>tmp_v_1;
        vector<int>tmp_v_2;
        for(int j=0; j<m; j++)
        {
            char tmp_c;
            cin >> tmp_c;
            if(tmp_c == 'c')
            {
                array<int,3> tmp_arr = {0,i,j};                
                pq.push(tmp_arr);
                tmp_v_1.push_back(1);
            }
            else if(tmp_c == '.')
                tmp_v_1.push_back(1);
            else if(tmp_c == 'x')
                tmp_v_1.push_back(0);
            tmp_v_2.push_back(MY_INT_MAX);
        }
        input_map.push_back(tmp_v_1);
        dp.push_back(tmp_v_2);
    }

    int offset[3][2] = {{1,0}, {0,1}, {0,-1}};
    int output = MY_INT_MAX;
    while(!pq.empty())
    {
        array<int,3> front_arr = pq.top();
        pq.pop();
        if(front_arr[1] == n-1)
        {
            output = min(output, front_arr[0]);
            break;
        }

        for(int i=0; i<3; i++)
        {
            int now_row = front_arr[1] + offset[i][0];
            int now_col = front_arr[2] + offset[i][1];
            if(now_row >= n || now_row < 0 || now_col >= m || now_col < 0 || input_map[now_row][now_col] == 0)
                continue;

            int next_length = front_arr[0];
            if(i != 0)
                next_length++;

            if(dp[now_row][now_col] > next_length)
            {
                dp[now_row][now_col] = next_length;
                array<int,3> tmp_arr = {next_length, now_row, now_col};
                pq.push(tmp_arr);
            }
        }
    }
    if(output == MY_INT_MAX)
        cout << "-1";
    else
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