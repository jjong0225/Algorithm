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
        return lp.second > rp.second;
    }
};

void solution()
{
    // code
    int m,n;
    cin >> m >> n;
    vector<pair<int,int>> input_v;
    for(int i=0; i<n; i++)
    {
        int a,b;
        cin >> a >> b;
        input_v.push_back(make_pair(a,b));
    }
    sort(input_v.begin(), input_v.end(), my_comp());
    int now_weight = m;
    int output = 0;
    for(int i=0; i<input_v.size(); i++)
    {
        if(now_weight >= input_v[i].first)
        {
            output = output + input_v[i].first * input_v[i].second;
            now_weight = now_weight - input_v[i].first;
        }
        else
        {
            output = output +  now_weight * input_v[i].second;
            now_weight = 0;
        }
        if(now_weight == 0)
            break;
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