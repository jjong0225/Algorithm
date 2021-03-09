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
    int a, b =0;
    cin >> a >> b;
    if(a>b)
        cout << ">";
    else if(a < b)
        cout << "<";
    else if(a == b)
        cout << "==";
    return 0;
}