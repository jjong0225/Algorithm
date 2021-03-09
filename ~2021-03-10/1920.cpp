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



void solution()
{
    // code
    int n,m;
    cin >> n;
    vector<int> input_v;
    vector<int> output_v;
    for(int i=0; i<n; i++)
    {
        int tmp;
        cin >> tmp;
        input_v.push_back(tmp);
    }
    cin >> m;
    for(int i=0; i<m; i++)
    {
        int tmp;
        cin >> tmp;
        output_v.push_back(tmp);
    }
    sort(input_v.begin(), input_v.end());

    for(int i=0; i<m; i++)
    {
        int tmp_val = *(lower_bound(input_v.begin(),input_v.end(), output_v[i]));
        if(tmp_val == output_v[i])
            cout << "1\n";
        else
            cout << "0\n";
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