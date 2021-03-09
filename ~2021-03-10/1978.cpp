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

int dp[1001] = {0};

void solution()
{
    int max_input = 0;
    int n;
    cin >> n;
    vector<int> input_v;
    for(int i=0; i<n; i++)
    {
        int tmp_input;
        cin >> tmp_input;
        input_v.push_back(tmp_input);
        max_input = max(tmp_input ,max_input);
    }
    dp[0] = 3, dp[1] = 3;
    for(int i=2; i<=max_input; i++)
    {
        int now_d = 1;
        while(i*now_d <= max_input)
        {
            dp[i*now_d]++;
            now_d++;
        }
    }
    int output = 0;
    for(int i=0; i< input_v.size(); i++)
    {
        if(dp[input_v[i]] == 1)
            output++;
    }
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