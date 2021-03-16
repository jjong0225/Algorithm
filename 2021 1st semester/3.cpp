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
    int k, n;
    cin >> k >> n;
    vector<int> prev;
    for(int i=0; i<k; i++)
    {
        int tmp;
        cin >> tmp;
        prev.push_back(tmp);
    }

    for(int i=0; i<n-1; i++)
    {
        vector<int> tmp_v;
        for(int asdf=0; asdf<k; asdf++)
        {
            tmp_v.push_back(MY_INT_MAX);
        }
        for(int j=0; j<k; j++)
        {
            int tmp_min = prev[j];
            for(int l=0; l<k; l++)
            {
                if(j != l)
                {
                    int tmp_d;
                    cin >> tmp_d;
                    tmp_v[l] = min(prev[j] + tmp_d, prev[l]);
                }
            }
        }
        for(int j=0; j<k; j++)
        {
            int tmp_d;
            cin >> tmp_d;
            prev[j] = tmp_v[j] + tmp_d;
        }
    }
    int output = MY_INT_MAX;
    for(int j=0; j<k; j++)
        output = min(output, prev[j]);
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