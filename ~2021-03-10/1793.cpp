#include <string>
#include <vector>
#include <iostream>
#include<algorithm>
#include<math.h>

using namespace std;

typedef struct new_num 
{
    int part_of_digit[100];
} Bigint;

Bigint DP[260] = {0};
int idx = 2;
void solution(int n) {
    DP[0].part_of_digit[0] = 1, DP[0].part_of_digit[1] = 1, DP[0].part_of_digit[2] = 3;
    if(idx >= n)
        return DP[n];
    for(int i=3; i<=n; i++)
    {
        DP[i] = DP[i-1] + 2*DP[i-2];
    }
    idx = max(idx, n);
    return DP[n];
}


int main()
{
    while(1)
    {
        int n;
        cin >> n;
        printf("%g\n",solution(n));
    }
}