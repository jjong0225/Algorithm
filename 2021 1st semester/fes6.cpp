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
    bool operator()(array<int,3> lp, array<int,3> rp)
    {
        if(lp[0] != rp[0])
            return lp[0] > rp[0];
        else if(lp[1] != rp[1])
            return lp[1] < rp[1];
        else
            return lp[2] > rp[2];
    }
};

void solution()
{
    // code
    int n,m;
    cin >> m >> n;
    vector<vector<lld>> input_map;
    for(int i=0; i<n; i++)
    {
        vector<lld>tmp_v_1;
        for(int j=0; j<m; j++)
        {
            lld tmp_d;
            cin >> tmp_d;
            lld next_num = 0;
            if(i != 0)
                next_num = max(next_num, input_map[i-1][j]);
            if(j != 0)
                next_num = max(next_num, tmp_v_1[j-1]);
            next_num = next_num + tmp_d;
            tmp_v_1.push_back(next_num);
        }
        input_map.push_back(tmp_v_1);
    }
    cout << input_map[n-1][m-1];
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}