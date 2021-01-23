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

using namespace std;

typedef long long int lld;
typedef unsigned long long int uld;
typedef unsigned int ui;

void solution()
{
    // code
    int N;
    cin >> N;
    priority_queue<int,vector<int>, greater<int>> a;
    priority_queue<int> b;

    
    for(int i=0; i<N;i++)
    {
        int tmp;
        cin >> tmp;
        a.push(tmp);
    }
    for(int i=0; i<N;i++)
    {
        int tmp;
        cin >> tmp;
        b.push(tmp);
    }
    lld output = 0;
    for(int i=0; i<N; i++)
    {
        output = output+(a.top()*b.top());
        a.pop(), b.pop();
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