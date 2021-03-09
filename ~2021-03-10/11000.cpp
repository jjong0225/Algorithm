#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int checker[200001] = {0};

bool my_operator(pair<int,int> lp, pair<int,int> rp)
{
    if(lp.second != rp.second)
        return lp.second < rp.second;
    else
        return lp.first < rp.first;
}

vector<pair<int,int>> input_v;

int b_search(int param_low, int param_high, int target)
{
    int low = param_low, high = param_high;
    int mid = (low + high)/2;
    while(low < high)
    {
        mid = (low + high)/2;
        if(input_v[mid].second > target)
            high = mid;
        else // 작거나 같으면 포함
            low = mid+1;
    }
    if(input_v[low].second > target)
        low--;
    while(1)
    {
        if(low < 0)
            return 0;
        if(checker[low] == 1)
        {
            if(low == 0)
                return 0;
            low--;
        }
        else
            break;
    }
    return low;
}

int dfs(int now_idx)
{
    checker[now_idx] = 1;
    if(now_idx == 0)
    {
        checker[0] = 1;
        return 0;
    }
    int next_idx = b_search(0,now_idx,input_v[now_idx].first);
    if(input_v[next_idx].second <= input_v[now_idx].first)
        dfs(next_idx);
    return 0;
}


int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int a,b;
        cin >> a >> b;
        input_v.push_back(make_pair(a,b));
    }
    sort(input_v.begin(), input_v.end(), my_operator);
    int output = 0;
    for(int i=n-1; i>=0; i--)
    {
        if(checker[i] == 0)
        {
            dfs(i);
            output++;
        }
    }
    cout << output;
}
