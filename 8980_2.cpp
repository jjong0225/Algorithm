#include<iostream>
#include<vector>
#include<array>
#include<queue>
#include<algorithm>
#include<math.h>

using namespace std;

struct my_compare
{
    bool operator()(array<int,3>lp, array<int,3>rp)
    {
        if(lp[1]-lp[0] != rp[1]-rp[0])
            return lp[1]-lp[0] < rp[1]-rp[0];
        else
            return lp[0] < rp[0];
    }
};

vector<int> dp;
int n,c, num;

int exe_sum(int start_idx, int end_idx, int offset)
{
    int param_offset = min(offset, c-dp[start_idx]);
    if(start_idx + 1 < end_idx)
        param_offset = exe_sum(start_idx+1,end_idx,param_offset);
    dp[start_idx] += param_offset;
    return param_offset;
}

int main ()
{
    cin >> n >> c >> num;
    vector<array<int,3>> input_v;
    for(int i=0; i<=n; i++)
        dp.push_back(c);
    for(int i=0; i<num; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        array<int,3> tmp_arr = {a,b,c};
        input_v.push_back(tmp_arr);
    }

    sort(input_v.begin(), input_v.end(), my_compare());
    int output = 0;
    for(int i=0; i<num; i++)
    {
        array<int,3> now_arr = input_v[i];
        int val = now_arr[2];
        for(int j=now_arr[0]; j<now_arr[1]; j++)
        {
            val = min(dp[j], val);
        }
        for(int j=now_arr[0]; j<now_arr[1]; j++)
        {
            dp[j] -= val;
        }
        output += val;
    }
    cout << output;

}
