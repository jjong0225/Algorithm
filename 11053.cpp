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

int n;
vector<int> input_v;
vector<int> dp;

int b_search(int low, int high, int cmp_num)
{
    while(low < high)
    {
        int mid = (low + high)/2;
        if(dp[mid] == cmp_num)
            return 0;
        if(dp[mid] < cmp_num)
            low = mid + 1;
        else if(dp[mid] > cmp_num)
            high = mid;
    }
    return low;
}

void solution()
{
    // code
    cin >> n;
    dp.push_back(0);
    for(int i=0; i<n; i++)
    {
        int tmp_input;
        cin >> tmp_input;
        input_v.push_back(tmp_input);
        dp.push_back(0);
    }
    int max_idx = 1;
    dp[1] = input_v[0];
    for(int i=1; i<n; i++)
    {
        if(dp[max_idx] == input_v[i])
            continue;
        else if(dp[max_idx] < input_v[i])
            dp[++max_idx] = input_v[i];
        else
        {
            int idx = b_search(1,max_idx, input_v[i]); 
            dp[idx] = input_v[i];
        }
    }
    int count = 0;
    for(int i=1; i<=n; i++)
    {
        if(dp[i] != 0)
            count++;
        else
            break;
    }
    cout << count;
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}