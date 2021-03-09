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
    queue<int> q;
    for(int i=1; i<=n; i++)
    {
        q.push(i);
    }
    vector<int> output_v;
    int counter = 0;
    while(!q.empty())
    {
        counter++;
        int now_int = q.front();
        q.pop();
        if(counter == k)
        {
            output_v.push_back(now_int);
            counter = 0;
        }
        else
            q.push(now_int);
    }
    cout << "<";
    for(int i=0; i<output_v.size(); i++)
    {
        cout << output_v[i];
        if(i != output_v.size()-1)
            cout << ", ";
    }
    cout << ">";
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}