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
    int max_count = 0;  
    cin >> n;
    vector<int> input_v;
    vector<int> dp;
    vector<int> dp_2;
    vector<int> dp_2_count;
    vector<int> dp_2_max;

    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        input_v.push_back(a);
        dp.push_back(MY_INT_MAX);
        dp_2.push_back(MY_INT_MAX);        
        dp_2_count.push_back(MY_INT_MAX);
        dp_2_max.push_back(MY_INT_MAX);        
    }
    dp[0] = input_v[0];

    int max_count_2 = 0;
    dp_2[0] = input_v[dp_2.size()-1];
    dp_2_count[dp_2.size()-1] = 1;
    dp_2_max[dp_2.size()-1] = input_v[dp_2.size()-1];

    for(int i=input_v.size()-2; i>=0; i--)
    {
        if(dp_2[max_count_2] < input_v[i])
            dp_2[++max_count_2] = input_v[i];

        vector<int>::iterator it = lower_bound(dp_2.begin(), dp_2.end(), input_v[i]);
        if(*it != input_v[i])
            *it = input_v[i];
        int tmp_idx = i;
        dp_2_count[tmp_idx] = max_count_2 + 1;
        dp_2_max[tmp_idx] = dp_2[max_count_2];        
    }

    int output = 0;
    for(int i=1; i<input_v.size(); i++)
    {
        if(dp[max_count] < input_v[i])
            dp[++max_count] = input_v[i];

        vector<int>::iterator it = lower_bound(dp.begin(), dp.end(), input_v[i]);
        if(*it != input_v[i])
            *it = input_v[i];
        if (dp[max_count] == dp_2_max[i])
        {
            output = max(output, max_count + dp_2_count[i] - 1);
        }
        else if(dp[max_count] > dp_2_max[i])
        {
            output = max(output, max_count + dp_2_count[i]);
        }
    }

    cout << output + 1;
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}