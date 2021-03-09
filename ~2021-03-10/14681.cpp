#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
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

int main ()
{
    int a, b;
    cin >> a >> b;
    if(a > 0 && b>0)
        cout << 1;
    else if (a < 0 && b > 0)
        cout << 2;
    else if (a < 0 && b < 0)
        cout << 3;
    else
        cout << 4;
    return 0;
}

