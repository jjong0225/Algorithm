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

struct my_cmp
{
    bool operator()(pair<int,int> lp, pair<int,int> rp)
    {
        return lp.first < rp.first;
    }
};


void solution()
{
    // code
    int n;
    cin >> n;
    vector<pair<int,int>> input_a;
    for(int i=0; i<n; i++)
    {
        int a,b;
        cin >> a >> b;
        input_a.push_back(make_pair(a,b));
    }
    sort(input_a.begin(), input_a.end(), my_cmp());
    int now_idx = 0, now_fuel = 0 , end_idx = 0;
    cin >> end_idx >> now_fuel;
    input_a.push_back(make_pair(end_idx, 0));

    priority_queue<int, vector<int>, less<int>> pq;
    int output = 0;
    for(int i=0; i<input_a.size(); i++)
    {
        int top_idx = input_a[i].first, top_fuel = input_a[i].second;
        while(top_idx-now_idx > now_fuel)
        {
            if(pq.empty())
            {
                cout << "-1";
                return;
            }
            now_fuel += pq.top();
            pq.pop();
            output++;
        }
        pq.push(top_fuel);
        now_fuel = now_fuel - (top_idx-now_idx);
        now_idx = top_idx;
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