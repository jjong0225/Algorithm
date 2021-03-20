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

void solution()
{
    // code
    int n;
    cin >> n;
    vector<int> v;
    vector<lld> dp;
    for(int i=0; i<n; i++)
    {
        char tmp_a;
        cin >> tmp_a;
        v.push_back(tmp_a-'0');
        dp.push_back(0);
    }
    dp[0] = 1;
    if(v[1] == 1)
        dp[1] = 1;
    for(int i=2; i<n; i++)
    {
        if(v[i] == 1)
            dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n-1];

}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}