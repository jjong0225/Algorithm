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
    int n;
    cin >> n;
    priority_queue<lld, vector<lld>, greater<lld>> pq;
    for(int i=0; i<n; i++)
    {
        lld tmp_d;
        cin >> tmp_d;
        pq.push(tmp_d);
    }
    lld output = 0;
    if(n == 1)
    {
        cout << "0";
        return;
    }
    while(1)
    {
        lld a,b,c;
        a = pq.top(), pq.pop();
        b = pq.top(), pq.pop();
        c = a + b;
        output += c;
        if(pq.empty())
            break;
        pq.push(c);
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