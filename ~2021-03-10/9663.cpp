#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<list>
#include<stack>
#include<queue> // priority_queue 포함
#include<set>
#include<deque>
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
int map_arr[20][20] = {0};
int output = 0;
bool cross_check(int c, int d)
{
    for(int i=0; i<=d; i++)
    {
        if(c+i < n)
        {
            if(map_arr[c+i][d-i] == 1)
                return false;
        }
        if(c-i >= 0)
        {
            if(map_arr[c-i][d-i] == 1)
                return false;
        }
        if(map_arr[c][d-i] == 1)
            return false;
    }

    return true;
}

void dfs(int a, int b)
{
    if(b == n-1)
    {
        output++;
        return;
    }
    map_arr[a][b] = 1;
    for(int i=0; i<n; i++)
    {
        if(cross_check(i,b+1))
            dfs(i,b+1);
    }
    map_arr[a][b] = 0;
}

void solution()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        dfs(i,0);
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