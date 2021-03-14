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
    lld K,P,N;
    cin >> K >> P >> N;
    int ex = N*10;
    queue<int> q;
    while(ex > 0)
    {
        q.push(ex%10);
        ex = ex / 10;
    }
    vector<int> digit_v;
    vector<int> ex_v;
    while(!q.empty())
    {
        digit_v.push_back(q.front());
        q.pop();
    }

    ex_v.push_back(P);
    for(int i=1; i<digit_v.size(); i++)
    {
        lld tmp_val = 1;
        lld prev_val = ex_v[i-1];
        for(int j=1; j<=10; j++)
        {
            tmp_val = (tmp_val * prev_val) % 1000000007;
        }
        ex_v.push_back(tmp_val);
    }

    lld output = K;
    for(int i=0; i<digit_v.size(); i++)
    {
        for(int j=0; j<digit_v[i]; j++)
        {
            output = (output * ex_v[i]) % 1000000007;
        }
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