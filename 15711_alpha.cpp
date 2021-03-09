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
vector<int> prime_v;
bool check_arr[2000001] = {0};

bool is_prime(lld now_val)
{
    lld sqrt_val = (lld)sqrt(now_val)+1;
    lld now_limit = lower_bound(prime_v.begin(), prime_v.end(), sqrt_val) - prime_v.begin();
    if(now_limit == prime_v.size())
        now_limit--;
    for(lld i=0; i<=now_limit; i++)
    {
        if(now_val % prime_v[i] == 0)
            return false;
    }
    return true;
}

void solution()
{
    int n;
    cin >> n;
    vector<pair<lld,lld>> input_v;
    lld my_max = 2;
    for(lld i=0; i<n; i++)
    {
        lld a,b;
        cin >> a >> b;
        input_v.push_back(make_pair(a,b));
        my_max = max(my_max, a + b);
    }
    lld limit_val = (lld)sqrt(my_max) + 1;
    for(lld i=2; i<=limit_val; i++)
    {
        if(check_arr[i] == 0)
        {
            prime_v.push_back(i);
            lld tmp_counter = 2;
            while(i*tmp_counter <= limit_val)
            {
                check_arr[i*tmp_counter] = 1;
                tmp_counter++;
            }
        }
    }
    for(lld i=0; i<n; i++)
    {
        lld now_sum = input_v[i].first + input_v[i].second;
        if(now_sum < 4)
            cout << "NO\n";
        else if(now_sum % 2 == 0)
                cout << "YES\n";
        else
        {
            if(is_prime(now_sum - 2))
                cout << "YES\n";
            else
                cout << "NO\n";
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