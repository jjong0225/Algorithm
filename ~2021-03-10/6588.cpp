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
int dp[1000001] = {0};
vector<int> prime_v;

int goldbach(int parma_val)
{
    int start_idx = lower_bound(prime_v.begin(), prime_v.end(), parma_val) - prime_v.begin();
    for(int i=start_idx; i>=0; i--)
    {
        int lower_idx = lower_bound(prime_v.begin(), prime_v.end(), parma_val - prime_v[i]) - prime_v.begin();
        if(prime_v[i] + prime_v[lower_idx] == parma_val)
        {
            cout << parma_val << " = " << prime_v[lower_idx] << " + " << prime_v[i] << "\n";
            return 0;
        }
    }
    cout << "Goldbach's conjecture is wrong." << endl;
    return 0;
}

void solution()
{
    // code
    int input_d = 0;
    cin >> input_d;
    vector<int> input_v;
    int my_max = 0;

    while(input_d)
    {
        my_max = max(my_max, input_d);
        input_v.push_back(input_d);
        cin >> input_d;
    }

    for(int i=2; i<= my_max; i++)
    {
        if(dp[i] == 0)
        {
            prime_v.push_back(i);
            int my_counter = 2;
            while(i*my_counter <= my_max)
            {
                dp[i*my_counter] = 1;
                my_counter++;
            }
        }
    }
    for(int i=0; i<input_v.size(); i++)
    {
        goldbach(input_v[i]);
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