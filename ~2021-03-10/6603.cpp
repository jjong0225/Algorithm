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
int v[20] = {0};
int n = 0;
int tmp_arr[20] = {0};

void dfs(int num_of_count, int now_idx)
{
    int k = n-(5-num_of_count);
    tmp_arr[num_of_count] = v[now_idx];
    if(num_of_count == 6)
        cout <<  tmp_arr[1] << " " << tmp_arr[2] << " " << tmp_arr[3] << " " << tmp_arr[4] << " " << tmp_arr[5] << " " << tmp_arr[6] << "\n";
    else
    {
        for(int i = now_idx+1; i<k; i++)
            dfs(num_of_count+1, i);
    }
}

void solution()
{
    while(1)
    {
        cin >> n;
        if(n == 0)
            break;
        for(int i=0; i<n; i++)
            cin >> v[i];
        for(int i=0; i<n-5; i++)
        {
            dfs(1, i);
        }
        cout << "\n";
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