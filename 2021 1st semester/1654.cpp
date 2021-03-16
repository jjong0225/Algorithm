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

void solution()
{
    // code
    int n, k;
    cin >> n >> k;
    lld input_max = 0;
    vector<lld> input_v;
    for(int i=0; i<n; i++)
    {
        lld tmp_d;
        cin >> tmp_d;
        input_max = max(input_max, tmp_d);
        input_v.push_back(tmp_d);
    }
    lld now_min = 1;
    lld now_max = input_max;
    lld output = 0;
    while(now_min <= now_max)
    {
        lld mid = (now_min + now_max)/2;
        lld tmp_count = 0;
        lld tmp_dif = 0;
        for(int i=0; i<input_v.size(); i++)
        {
            tmp_count += input_v[i] / mid;
            tmp_dif += input_v[i] % mid;
        }
        if(tmp_count >= k) // 값을 키울 필요가 있다
        {
            output = max(output, mid);
            now_min = mid + 1;
        }
        else // 값을 줄일 필요가 있다.
            now_max = mid - 1;
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