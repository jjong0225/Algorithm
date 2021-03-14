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

struct my_comp
{
    bool operator()(pair<int,int>lp, pair<int,int>rp)
    {
        if(lp.second != rp.second)
            return lp.second < rp.second;
        else
            return lp.first > rp.first;
    }
};
void solution()
{
    // code
    int n;
    cin >> n;
    vector<pair<int,int>> input_v;
    for(int i=0; i<n; i++)
    {
        int a,b;
        cin >> a >> b;
        input_v.push_back(make_pair(a,b));
    }
    sort(input_v.begin(), input_v.end(), my_comp());
    int output = 1;
    int prev_end_time = input_v[0].second;
    for(int i=1; i<input_v.size(); i++)
    {
        if(prev_end_time <= input_v[i].first)
        {
            prev_end_time = input_v[i].second;
            output++;
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