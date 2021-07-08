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

int dfs(int param_count, int continuous_count)
{
    if(param_count + continuous_count < 6 || param_count < 0)
        return 0;
    if(continuous_count == 6 && param_count == 0)
        return 1;
    return dfs(param_count-1, continuous_count+1) + dfs(param_count-1, 1);
}

int offset[6][2] = {{-1, 2}, {1, 2}, {3, 0}, {1, -2}, {-1, -2}, {-3, 0}};
int my_map[200][200] = {0};
int n;
int result = 0;
int travle(int param_x, int param_y, int param_dir, int param_count)
{
    param_x += offset[param_dir][0];
    param_y += offset[param_dir][1];
    if(my_map[param_y][param_x] == 1)
    {
        if(param_count == n)
        {
            result++;
            return 1;
        }
        else
            return 0;
    }
    if(param_count >= n)
        return 0;
    my_map[param_y][param_x] = 1;
    int return_val = 0;
    return_val += travle(param_x, param_y, (param_dir+1)%6, param_count+1);
    return_val += travle(param_x, param_y, (param_dir+5)%6, param_count+1);
    my_map[param_y][param_x] = 0;
    return return_val;
}

void solution()
{
    // code
    int now_dir = 1;
    int now_x = 100;
    int now_y = 100;
    cin >> n;
    my_map[now_y][now_x] = 1;
    cout << travle(100, 100, 1, 0);
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}