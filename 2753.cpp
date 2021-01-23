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
    int a = 0;
    cin >> a;
    if((a % 4 == 0 && a % 100 != 0) || a % 400 == 0) 
        cout << 1;
    else
        cout << 0;
    return 0;
}