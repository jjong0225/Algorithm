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
// N <= 100,000
void solution()
{
    // code
    int n, mid;
    cin >> n;
    priority_queue<int,vector<int>, less<int>> small_pq;
    priority_queue<int,vector<int>, greater<int>> large_pq;
    cin >> mid;
    cout << mid << "\n";

    for(int i=1; i<n; i++)
    {
        int input_d;
        cin >> input_d;
        if(mid < input_d)
            large_pq.push(input_d);
        else
            small_pq.push(input_d);
        if(small_pq.size() != large_pq.size())
        {
            //s
            if(small_pq.size() > large_pq.size())
            {
                large_pq.push(mid);
                mid = small_pq.top();
                small_pq.pop();
            }
            if(small_pq.size() + 1 < large_pq.size())
            {
                small_pq.push(mid);
                mid = large_pq.top();
                large_pq.pop();
            }
        }
        cout << mid << "\n";
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