#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
1000 -> 10^3 
*/
struct my_cmp
{
    bool operator()(pair<int,int> &lp, pair<int,int> &rp)
    {
        if(lp.second != rp.second)
            return lp.second > rp.second;
        else
            return lp.first < rp.first;
    }
};


int main ()
{
    int n;
    int dp[1001] = {0};
    cin >> n;
    vector<pair<int,int>> input_v;
    for(int i=0; i<n; i++)
    {
        int a,b;
        cin >> a >> b;
        input_v.push_back(make_pair(a,b));
    }
    sort(input_v.begin(), input_v.end(), my_cmp());
    int output = 0;
    for(int i=0; i<n; i++)
    {
        int now_idx = 0;
        for(int j=input_v[i].first; j>=1; j--)
        {
            if(dp[j] == 0)
            {
                now_idx = j;
                break;
            }
        }
        if(now_idx != 0)
        {
            dp[now_idx] = input_v[i].second;
            output += input_v[i].second;
        }
    }
    cout << output;
}