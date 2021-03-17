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

int count_arr[10000000] = {0};
lld output = MY_INT_MAX;
vector<vector<lld>> dp;

int get_n_k(int k, int n)
{
    int return_val = n;
    for(int i=1; i<k; i++)
        return_val = return_val * 10 + n;
    return return_val;
}

int solution(int n, int number)
{
    vector<lld>dummy_v;
    dp.push_back(dummy_v);
    for(int i=1; i<=8; i++)
    {
        vector<lld>tmp_v;
        tmp_v.push_back(get_n_k(i, n));
        if(tmp_v[0] == number)
            return i;

        for(int k=1; k<i; k++)
        {
            for(int a=0; a<dp[k].size(); a++)
            {
                for(int b=0; b<dp[i-k].size(); b++)
                {
                    lld tmp_1 = dp[k][a] + dp[i-k][b];
                    lld tmp_2 = dp[k][a] * dp[i-k][b];
                    lld tmp_3 = dp[k][a] - dp[i-k][b];
                    lld tmp_4 = dp[k][a] / dp[i-k][b];
                    if(tmp_1 == number || tmp_2 == number || tmp_3 == number || tmp_4 == number)
                        return i;

                    if(tmp_1 < 1000000 && tmp_1 > 0 && count_arr[tmp_1] == 0)
                    {
                        count_arr[tmp_1] = k;
                        tmp_v.push_back(tmp_1);
                    }
                    if(tmp_2 < 1000000  && tmp_2 > 0 && count_arr[tmp_2] == 0)
                    {
                        count_arr[tmp_2] = k;
                        tmp_v.push_back(tmp_2);
                    }
                    if(tmp_3 > 0 &&  tmp_3 > 0 && count_arr[tmp_3] == 0)
                    {
                        count_arr[tmp_3] = k;
                        tmp_v.push_back(tmp_3);
                    }
                    if(tmp_4 > 0  && tmp_4 > 0 && count_arr[tmp_4] == 0)
                    {
                        count_arr[tmp_4] = k;
                        tmp_v.push_back(tmp_4);
                    }
                }
            }

        }
        dp.push_back(tmp_v);
    }
    return -1;
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    int a,b;
    cin >> a >> b;
    cout << solution(a,b);
    return 0;
}