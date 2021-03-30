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
int n, k;
int prev_idx = 0;
vector<int> input_v;

int find_h(int parma_idx)
{
    int tmp_idx = max(prev_idx, parma_idx-k);
    for(int i=tmp_idx; i<=parma_idx+k; i++)
    {
        if(i>=0 && i<n)
        {
            if(input_v[i] == 1)
            {
                input_v[i] = -1;
                prev_idx = i+1;
                return 1;
            }
        }
    }
    prev_idx = parma_idx + k + 1;
    return 0;
}

void solution()
{
    // code
    cin >> n >> k;
    for(int i=0; i<n; i++)
    {
        char tmp_c;
        cin >> tmp_c;
        if(tmp_c == 'H')
            input_v.push_back(1);
        else if(tmp_c == 'P')
            input_v.push_back(0);
    }
    int output = 0;
    for(int i=0; i<n; i++)
    {
        if(input_v[i] == 0)
            output += find_h(i);
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