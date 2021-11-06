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

double get_dist(pair<int,int>lp, pair<int,int>rp)
{
    return sqrt(pow((lp.first-rp.first),2) + pow((lp.second-rp.second), 2));
}

void solution()
{
    int n;
    cin >> n;
    vector<pair<int, int>> input_v;
    for(int i=0; i<n; i++)
    {
        int a,b;
        cin >> a >> b;
        input_v.push_back(make_pair(a,b));
    }

    double output_min = 1000000000;
    int output_idx = -1;
    for(int i=0; i<n; i++)
    {
        double tmp_mmax = -1;
        for(int j=0; j<n; j++)
        {
            if(i == j)
                continue;
            double tmp_dist = get_dist(input_v[i], input_v[j]);
            if(tmp_mmax < tmp_dist)
                tmp_mmax = tmp_dist;
        }
        if(output_min > tmp_mmax)
        {
            output_min = tmp_mmax;
            output_idx = i;
        }
    }
    cout << input_v[output_idx].first << " " << input_v[output_idx].second;
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}