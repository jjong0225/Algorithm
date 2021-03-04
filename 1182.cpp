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
int n,s,output = 0;
int input_arr[22] = {0};
void dfs(int now_idx, int now_sum)
{
    if(now_sum == s)
        output++;
    for(int i=now_idx+1; i<n; i++)
        dfs(i, now_sum + input_arr[i]);
}

void solution()
{
    cin >> n >> s;
    for(int i=0; i<n; i++)
        cin >> input_arr[i];
    for(int i=0; i<n; i++)
        dfs(i, input_arr[i]);
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