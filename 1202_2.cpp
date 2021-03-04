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

struct my_compare
{
    bool operator()(pair<lld,lld> &lp, pair<lld,lld> &rp)
    {
        if(lp.first != rp.first)
            return lp.first < rp.first;
        else
            return lp.second > rp.second;
    }
};

vector<pair<lld,lld>> input_v;
vector<int> input_k;
vector<int> check_v;

int b_search(int low, int high, int target)
{
    int mid = 0;
    while(low < high)
    {
        mid = (low + high)/2;
        if(target < input_k[mid])
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

void solution()
{
    // code
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; i++)
    {
        lld a, b;
        cin >> a >> b;
        input_v.push_back(make_pair(a,b));
        check_v.push_back(0);
    }
    for(int i=0; i<k; i++)
    {
        int a;
        cin >> a;
        input_k.push_back(a);
    }
    sort(input_v.begin(), input_v.end(), my_compare());
    sort(input_k.begin(), input_k.end(), less<lld>());
    lld output = 0;
    int count = 0;
    priority_queue<int> pq;
    int jew_idx = 0;
    for(int i=0; i<k; i++)
    {
        while(input_v[jew_idx].first <= input_k[i] && jew_idx < n)
        {
            pq.push(input_v[jew_idx].second);
            jew_idx++;
        }
        if(!pq.empty())
            output+=pq.top(), pq.pop();
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