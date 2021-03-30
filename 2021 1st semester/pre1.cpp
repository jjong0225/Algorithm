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
    lld p,n;
    cin >> p >> n;
    vector<lld> input_v;
    vector<lld> dp;
    for(int i=0; i<n; i++)
    {
        lld a;
        cin >> a;
        input_v.push_back(a);
    }
    lld tmp_val = 1;
    dp.push_back(tmp_val);
    for(int i=1; i<=n; i++)
    {
        tmp_val = (tmp_val * p) % 1000000007;
        dp.push_back(tmp_val);
    }
    lld output = 0;
    for(int i=0; i<n; i++)
    {
        output = (output + input_v[i] * dp[n-1-i]) % 1000000007;
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