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
    vector<int> input_v;
    vector<int> input_v_2;
    for(int i=0; i<n; i++)
    {
        int tmp_int;
        cin >> tmp_int;
        input_v.push_back(tmp_int);
        input_v_2.push_back(tmp_int);
    }
    sort(input_v.begin(), input_v.end(), greater<int>());
    int target = input_v[0];
    vector<pair<lld,lld>> dp;
    dp.push_back(make_pair(1,0)),dp.push_back(make_pair(0,1)),dp.push_back(make_pair(1,1));
    for(int i=3; i<= target; i++)
        dp.push_back(make_pair(dp[i-1].first + dp[i-2].first,dp[i-1].second + dp[i-2].second));
    for(int i=0; i<input_v_2.size(); i++)
    {
        cout << dp[input_v_2[i]].first << " " << dp[input_v_2[i]].second << "\n";
    }
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}