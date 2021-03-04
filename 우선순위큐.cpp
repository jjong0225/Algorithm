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

struct my_compare
{
    bool operator()(pair<lld,lld> &lp, pair<lld,lld> &rp)
    {
        if(lp.second != rp.second)
            return lp.second > rp.second;
        else
            return lp.first > rp.first;
    }
};
