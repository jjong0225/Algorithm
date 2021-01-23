#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<queue> // priority_queue 포함
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>

#include<algorithm>
#include<math.h>
#include<climits> // 자료형 limit포함

/*
첫째 줄에 N(1 ≤ N ≤ 1,000)이 주어진다. 둘째 줄에는 Ai (0 ≤ Ai ≤ 100)가 주어진다.

재환이가 최소 몇 번 점프를 해야 가장 오른쪽 끝 칸으로 갈 수 있는지 출력한다. 만약, 가장 오른쪽 끝으로 갈 수 없는 경우에는 -1을 출력한다.
*/

using namespace std;

typedef long long int lld;

vector<int> input_v;
vector<int> DP;
int N = 0;

int reg(int now_idx, int count)
{
    int output = -1;
    int next_idx = -1;
    for(int i=1; i<=input_v[now_idx]; i++)
    {
        if(now_idx+i < N)
        {
            if(output < input_v[now_idx+i])
            {
                output = max(output, input_v[now_idx+i]);
                next_idx = i;
            }
        }
    }
    if(now_idx + next_idx + output >= N-1)
        return count+2;
    return reg(now_idx+next_idx, count+1);
}

void solution()
{
    // code
    cin >> N;
    for(int i=0; i<N; i++)
    {
        int tmp_a = 0;
        cin >> tmp_a;
        DP.push_back(1000000000);
        input_v.push_back(tmp_a);
    }
    DP[0] = 0;
    cout << reg(0, 0);
    // for(int i=0; i<N; i++)
    // {
    //     if(input_v[i] == 0)
    //         continue;
    //     for(int j=1; j<=input_v[i]; j++)
    //     {
    //         if(i+j < N)
    //             DP[i+j] = min(DP[i+j], DP[i]+1);
    //     }
    // }
    // if(DP[N-1] == 1000000000)
    //     cout << -1;
    // else
    //     cout << DP[N-1];
}


int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}