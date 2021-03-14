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

    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        input_v.push_back(a);
        dp.push_back(MY_INT_MAX);
    }
    dp[0] = input_v[0];
    for(int i=1; i<input_v.size(); i++)
    {
        if(dp[max_count] < input_v[i])
            dp[++max_count] = input_v[i];

        vector<int>::iterator it = lower_bound(dp.begin(), dp.end(), input_v[i]);
        if(*it != input_v[i])
            *it = input_v[i];
    }
    cout << max_count+1;
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}