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
    int n;
    cin >> n;
    vector<int> input_v;
    for(int i=0; i<n; i++)
    {
        int tmp;
        cin >> tmp;
        input_v.push_back(tmp);
    }
    sort(input_v.begin(), input_v.end());
    int now_gcd = input_v[1]-input_v[0];
    for(int i=2; i<n; i++)
    {
        now_gcd = __gcd(now_gcd, input_v[i]-input_v[i-1]);
    }
    cout << (input_v[input_v.size()-1] - input_v[0])/now_gcd - (input_v.size() - 1);

}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}