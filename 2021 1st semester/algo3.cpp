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

lld prefix_sum[1000010] = {0};

void solution()
{
    // code
    int n, m;
    cin >> n >> m;
    prefix_sum[0] = 0;
    for(int i=1; i<=n; i++)
    {
        cin >> prefix_sum[i];
        prefix_sum[i] = prefix_sum[i] + prefix_sum[i-1];
    }
    for(int i=0; i<m; i++)
    {
        int s,e;
        cin >> s >> e;
        s--;
        double output_lf = (double)(prefix_sum[e] - prefix_sum[s])/(double)(e-s);
        output_lf = round(output_lf * 100);
        output_lf = output_lf / 100;
        printf("%.2lf\n", output_lf);
    }
}

int main ()
{
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}