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

const int MY_INT_MAX = 1000000000;

int input_map[1001][1001] = {0};
int dp[1001][1001] = {0};

void solution()
{
    // code
    int n,m,x;
    cin >> n >> m >> x;
    for(int i=0; i<=n; i++) for(int j=0; j<=n; j++) if(i != j) input_map[i][j] = MY_INT_MAX;
    for(int i=0; i<m; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        input_map[a][b] = c;
    }

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(input_map[i][j] > input_map[i][k] + input_map[k][j])
                    input_map[i][j] = input_map[i][k] + input_map[k][j];
            }
        }
    }
    int my_max = -1;
    for(int i=1; i<=n; i++) if(i != x) my_max = max(my_max, input_map[i][x] + input_map[x][i]);
    cout << my_max;
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}