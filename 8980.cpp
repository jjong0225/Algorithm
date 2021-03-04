#include<iostream>
#include<vector>
#include<array>
#include<queue>
#include<algorithm>
#include<math.h>

using namespace std;

// struct my_compare
// {
//     bool operator()(array<int,3>lp, array<int,3>rp)
//     {
//         if(lp[0] != rp[0])
//             return lp[0] < rp[0];
//         else if(lp[1] != rp[1])
//             return lp[1] < rp[1];
//         else
//             return lp[2] < rp[2];
//     }
// };

// struct my_compare
// {
//     bool operator()(array<int,3>lp, array<int,3>rp)
//     {
//         if(lp[1] != rp[1])
//             return lp[1] < rp[1];
//         else if(lp[0] != rp[0])
//             return lp[0] > rp[0];
//         else
//             return lp[2] < rp[2];
//     }
// };

// struct my_compare_2
// {
//     bool operator()(array<int,3>lp, array<int,3>rp)
//     {
//         if(lp[1] != rp[1])
//             return lp[1] > rp[1];
//         else
//             return lp[0] < rp[0];
//     }
// };

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
    dp.push_back(0);
    for(int i=0; i<num; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        array<int,3> tmp_arr = {a,b,c};
        input_v.push_back(tmp_arr);
        dp.push_back(0);
    }

    sort(input_v.begin(), input_v.end(), my_compare());
    int output = 0;
    for(int i=0; i<num; i++)
    {
        int now_length = input_v[i][2];
        int tmp_val = exe_sum(input_v[i][0], input_v[i][1],input_v[i][2]);
        output += tmp_val;
    }
    cout << output;


    // int now_vil = input_v[0][0];
    // int now_weight = min(c,input_v[0][2]);
    // int output = 0;
    // for(int i=0; i<num; i++)
    // {
    //     cout << input_v[i][0] << " " << input_v[i][1] << " " << input_v[i][2] << " " << endl;
    // }
    // int count = 0;
    // for(int i=1; i<=n; i++)
    // {
    //     for(int j=count; j<num; j++)
    //     {
    //         if()
    //     }
    //     int tmp_weight = min(input_v[i][2], c-now_weight);
    //     now_weight += tmp_weight;
    //     array<int,3> insert_arr = {input_v[i][0], input_v[i][1], tmp_weight};
    //     pq.push(insert_arr);
    // }

    // for(int i=1; i<num; i++)
    // {
    //     if(now_vil == input_v[i][0])
    //     {
    //         int tmp_weight = min(input_v[i][2], c-now_weight);
    //         now_weight += tmp_weight;
    //         array<int,3> insert_arr = {input_v[i][0], input_v[i][1], tmp_weight};
    //         pq.push(insert_arr);
    //     }
    //     else
    //     {
    //         now_vil = input_v[i][0];
    //         while(!pq.empty())
    //         {
    //             array<int,3> top_arr = pq.top();
    //             if(top_arr[1] != now_vil)
    //                 break;
    //             // cout << top_arr[0] << ' ' << top_arr[1] << ' ' << top_arr[2] << endl;
    //             pq.pop();
    //             output += top_arr[2];
    //             now_weight -= top_arr[2];
    //         }
    //         // cout << endl;
    //         i--;
    //     }
    // }
    // cout << output + now_weight;
}
