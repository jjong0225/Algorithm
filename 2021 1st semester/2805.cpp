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
vector<lld> input_v;
lld n,m;

lld param_search(lld param_min, lld param_max)
{
    lld now_min = param_min;
    lld now_max = param_max;
    lld tmp_m = 0;
    while(now_min <= now_max)
    {
        lld mid = (now_min + now_max)/2;
        lld now_m = 0;
        for(lld i=0; i<input_v.size(); i++)
        {
            if(input_v[i] > mid)
                now_m += (input_v[i] - mid);
        }

        if(now_m < m)
            now_max = mid-1;
        else if(now_m >= m)
        {
            tmp_m = max(tmp_m, mid);
            now_min = mid+1;
        }
    }
    return tmp_m;
}

void solution()
{
    // code
    cin >> n >> m;
    lld input_max = 0;
    for(int i=0; i<n; i++)
    {
        lld tmp;
        cin >> tmp;
        input_max = max(input_max, tmp);
        input_v.push_back(tmp);
    }
    cout << param_search(0, input_max);
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}