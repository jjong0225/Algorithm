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
int input_map[51][51] = {0};
int dp[2][51][51] = {0};
void solution()
{
    // code
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            char tmp_c;
            cin >> tmp_c;
            if(tmp_c == 'W')
                input_map[i][j] = 0;
            else
                input_map[i][j] = 1;
        }
    }

    int output = 1000000000;
    for(int i=0; i<=n-8; i++)
    {
        for(int j=0; j<=m-8; j++)
        {
            int tmp_val = 0;
            for(int k=0; k<8; k++)
            {
                for(int l=0; l<8; l++)
                {
                    if(input_map[i+k][j+l] != (k+l)%2)
                        tmp_val++;
                }
            }
            output = min(output, min(tmp_val, 64-tmp_val));
        }
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