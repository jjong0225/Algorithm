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

struct my_cmp 
{
    bool operator()(pair<int,bool> lp, pair<int,bool>rp)
    {
        if(lp.first != rp.first)
            return lp.first > rp.first;
        else
            return lp.second < rp.second;
    }
};

void solution()
{
    // code
    int n;
    cin >> n;
    priority_queue<pair<int,bool>, vector<pair<int,bool>>, my_cmp> pq;
    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        if(a == 0)
        {
            if(pq.empty())
                cout << 0 << "\n";
            else
            {
                pair<int,bool> tmp_p = pq.top();
                int out_d = tmp_p.first;
                if(tmp_p.second == 1)
                    out_d = out_d * -1;
                cout << out_d << "\n";
                pq.pop();
            }
        }
        else
        {
            if(a < 0)
                pq.push(make_pair(-1*a, 1));
            else
                pq.push(make_pair(a, 0));
        }
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