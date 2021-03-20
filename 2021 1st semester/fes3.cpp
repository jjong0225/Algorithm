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

int input_map[52][52] = {0};
int dp[52][52] = {0};
int n;
int output_arr[52] = {0};

void solution()
{
    // code
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            char tmp_c;
            cin >> tmp_c;
            input_map[i][j] = tmp_c-'0';
        }
    lld output = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(input_map[i][j] == 1)
            {
                if(i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                output += dp[i][j];
                for(int k=1; k<=dp[i][j]; k++)
                    output_arr[k]++;
            }
        }
    }
    cout << "total: " << output << "\n";
    for(int i=1; i<=n; i++)
    {
        if(output_arr[i] != 0)
            cout << "size[" << i << "]: " << output_arr[i] << "\n";
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