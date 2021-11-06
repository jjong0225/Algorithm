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
lld input_map[2002][2002] = {0};
lld DP[2002][2002] = {0};

void solution()
{
    // code
    lld n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> input_map[i][j];

    if(m == 1)
    {
        for(int i=0; i<n; i++) 
        {
            for(int j=0; j<n; j++)
            {
                cout << -1 * input_map[i][j] << " ";
            }
            cout << endl;
        }
        return ;
    }

    for(int i=0; i<n; i++) 
    {
        for(int j=0; j<n; j++)
        {
            int dp_x = i + m/2 < n ? i + m/2 : n-1;
            int dp_y = j + m/2 < n ? j + m/2 : n-1;
            int dp_x2 = i - m/2 -1 >= 0 ? i - m/2 -1 : 0;
            int dp_y2= j - m/2 - 1 >= 0 ? j - m/2 -1 : 0;

            if(dp_x >= n || dp_y >= n) continue;
            DP[dp_x][dp_y] = DP[dp_x-1][dp_y] + DP[dp_x][dp_y-1] - DP[dp_x-1][dp_y-1];

            lld new_bomb = -1 * ((DP[dp_x][dp_y] - DP[dp_x][dp_y2] - DP[dp_x2][dp_y] + DP[dp_x2][dp_y2]) + input_map[i][j]); 
            DP[dp_x][dp_y] += new_bomb;
        }
    }

    for(int i=0; i<n; i++) 
    {
        for(int j=0; j<n; j++)
        {
            int dp_x = i-1 >= 0 ? i-1 : 0;
            int dp_y = j-1 >= 0 ? j-1 : 0;
            lld new_bomb = DP[i][j] - DP[dp_x][j] - DP[i][dp_y] + DP[dp_x][dp_y];
            cout << new_bomb << " ";
        }
        cout << endl;
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