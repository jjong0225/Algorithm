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

vector<pair<int,int>> input_v;
vector<vector<pair<int,double>>> edge; // [i][j].first는 연결된 위치, [i][j].second는 길이
int n, k;

double get_dist(int l_idx, int r_idx)
{
    double tmp_d = pow((input_v[l_idx].first - input_v[r_idx].first), 2) + pow((input_v[l_idx].second - input_v[r_idx].second), 2);
    return sqrt(tmp_d);
}


bool is_possible(int mid)
{
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    int check_arr[10001] = {0};
    check_arr[0] = 1;
    while(!q.empty())
    {
        int now_count = q.front().first;
        int now_idx = q.front().second;
        if(now_count > k+1)
            break;

        q.pop();
        for(int i=0; i<edge[now_idx].size(); i++)
        {
            if(check_arr[edge[now_idx][i].first] == 0 && edge[now_idx][i].second <= mid)
            {
                check_arr[edge[now_idx][i].first] = now_count + 1;
                q.push(make_pair(now_count + 1, i));
            }
        }
    }
    if(check_arr[n+1] <= k+1 && check_arr[n+1] > 0)
        return true;
    else
        return false;
}

void solution()
{
    // code
    cin >> n >> k;
    vector<pair<int,double>> dummy_1;
    edge.push_back(dummy_1);
    input_v.push_back(make_pair(0,0));
    for(int i=0; i<n; i++)
    {
        vector<pair<int,double>> dummy_2;
        edge.push_back(dummy_2);
        int a, b;
        cin >> a >> b;
        input_v.push_back(make_pair(a,b));
    }
    vector<pair<int,double>> dummy_3;
    edge.push_back(dummy_3);
    input_v.push_back(make_pair(10000,10000));

    for(int i=0; i<input_v.size(); i++)
        for(int j=0; j<input_v.size(); j++)
            edge[i].push_back(make_pair(j,get_dist(i,j)));

    int low = 0;
    int high = 20000;
    int mid = (low + high) / 2;
    int output = MY_INT_MAX;
    while(low <= high)
    {
        int mid = (low + high)/2;
        if(is_possible(mid))
        {
            output = min(output, mid);
            high = mid-1;
        }
        else
            low = mid+1;
    }
    int last_output = output;
    if(last_output % 10 == 0)
        last_output = last_output / 10;
    else
        last_output = (last_output / 10) + 1;
    cout << last_output;
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}