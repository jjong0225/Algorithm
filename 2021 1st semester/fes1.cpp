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
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        string tmp_str;
        cin >> tmp_str;
        int total_min_a=0, total_min_b=0;
        {
            int now_hour = 0, now_min = 0;
            now_hour = ((tmp_str[0]-'0') * 10) + (tmp_str[1]-'0');
            now_min = ((tmp_str[3]-'0') * 10) + (tmp_str[4]-'0');
            total_min_a = now_hour * 60 + now_min;
        }
        cin >> tmp_str;
        cin >> tmp_str;
        {
            int now_hour = 0, now_min = 0;
            now_hour = ((tmp_str[0]-'0') * 10) + (tmp_str[1]-'0');
            now_min = ((tmp_str[3]-'0') * 10) + (tmp_str[4]-'0');
            total_min_b = now_hour * 60 + now_min;
        }
        v.push_back(make_pair(total_min_a, total_min_b));
    }
    sort(v.begin(), v.end(), my_cmp());
    int min_time = v[0].first, max_time = v[0].second;
    for(int i=1; i<v.size(); i++)
    {
        min_time = max(min_time,v[i].first);
        max_time = min(max_time, v[i].second);
    }
    if(min_time > max_time)
    {
        cout << -1;
        return;
    }
    else
    {
        int now_min_hour = min_time / 60;
        int now_min_min = min_time%60;
        int now_max_hour = max_time / 60;
        int now_max_min = max_time%60;
        printf("%02d:%02d ~ %02d:%02d", now_min_hour, now_min_min, now_max_hour, now_max_min);
    }
}

int main ()
{
    // iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}