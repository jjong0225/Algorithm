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

bool my_cmp(const array<int,3> &lp, const array<int,3> &rp)
{
    if(lp[1] != rp[1])
        return lp[1] < rp[1];
    else
        return lp[0] > rp[0];
}

int n;
vector<array<int,3>> input_v;

int b_search(int low, int high, int cmp_num)
{
    while(low < high)
    {
        int mid = (low + high)/2;
        // cout << low << " " << mid << " " << high << "|" << input_v[mid][1] << " " <<  cmp_num << endl;
        if(input_v[mid][1] >= cmp_num)
            high = mid;
        else
            low = mid+1;
    }
    return low;
}

void solution()
{
    // code
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        int a, b;
        cin >> a >> b;
        input_v.push_back({a,b,i});
    }
    sort(input_v.begin(), input_v.end(), my_cmp);
    int output = 0;
    int idx = 0;
    for(int i=n-1; i>=0; i--)
    {
        array<int,3> now_arr =  input_v[i];
        int tmp = i-b_search(0, i,now_arr[0])+1;
        if(output < tmp)
        {
            idx = i;
            output = tmp;
        }
    }
    if(output == 1)
    {
        cout << 0;
        return;
    }
    for(int i=0; i<n; i++)
        cout << input_v[i][0] << " " << input_v[i][1] << " " << endl;
    // cout << output << "\n";
    // for(int i=idx; i>idx-output; i--)
    // {
    //     cout << input_v[i][2] << " ";
    // }
}

/* 
N : 300,000
1 ≤ Si < Ei ≤ 10^9

최댓값이 10^9 이므로 이만큼의 크기를 쓸 순 없다.

*/

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}