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

bool check_v[2000010] = {0};
void solution()
{
    // code
    lld a, b, max_sqr;
    cin >> a >> b;
    max_sqr = floor(pow(b,0.5));
    vector<lld> k_v;
    for(lld i=2; i<=max_sqr; i++)
        k_v.push_back(i*i);

    lld output = b-a+1;
    for(lld i=0; i<k_v.size(); i++)
    {
        lld counter = ceil((double)a/(double)k_v[i]);
        while(k_v[i] * counter <= b)
        {
            if(check_v[k_v[i]*counter - a] == 0)
            {
                check_v[k_v[i]*counter - a] = 1;
                output--;
            }
            counter++;
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