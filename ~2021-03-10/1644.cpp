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

int dp[4000001] = {0};
int n;
vector<int> prime_v;
vector<int> check_v;
int output = 0;


void solution()
{
    // code
    cin >> n;
    for(int i=2; i<=n; i++)
    {
        if(dp[i] == 0)
        {
            prime_v.push_back(i);
            check_v.push_back(0);
            dp[i] = 0;
            int counter = 2;
            while(i*counter <= n)
            {
                dp[i*counter] = -1;
                counter++;
            }
        }
    }
    for(int i=prime_v.size()-1; i>=0; i--)
    {
        int now_val = n;
        int now_idx = i;
        while(now_val >= 0 && now_idx >= 0)
        {
            if(now_val - prime_v[now_idx] == 0)
            {
                output++;
                break;
            }
            if(now_val - prime_v[now_idx] > 0)
            {
                now_val = now_val - prime_v[now_idx];
                now_idx--;
            }
            else
                break;
        }
    }
    cout << output << endl;
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}