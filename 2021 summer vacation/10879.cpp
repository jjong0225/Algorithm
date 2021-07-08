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

int DP[50001] = {0};


int dfs(int param_d)
{
    if(DP[param_d] != 0 || param_d == 0)
        return DP[param_d];

    int tmp_exp = 1;
    while(param_d / tmp_exp > 0)
        tmp_exp *= 2;
    
    int return_val = MY_INT_MAX;
    if(tmp_exp == 65536)
        return_val = min(return_val, (DP[tmp_exp/2]+1) +  dfs(tmp_exp - param_d) + 4);
    else
        return_val = min(return_val, DP[tmp_exp] +  dfs(tmp_exp - param_d) + 4);
    return_val = min(return_val, DP[tmp_exp/2] +  dfs(param_d - tmp_exp/2) + 4);
    DP[param_d] = return_val;
    return return_val;
}

void solution()
{
    // code
    int n;
    cin >> n;
    int init_d = 1;
    int init_count = 1;
    while(init_d <= 50001)
    {
        DP[init_d] = init_count;
        init_d *= 2, init_count++;
    }
    DP[0] = 6;

    for(int i=0; i<n; i++)
    {
        int target_d;
        cin >> target_d;
        target_d = abs(target_d);
        int out_val = dfs(target_d);
        cout << out_val << endl;
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