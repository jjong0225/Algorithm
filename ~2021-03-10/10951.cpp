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

void solution()
{
    while(1)
    {
        char a, b = 0;
        cin >> a >> b;

        if (cin.eof())
        {
            break;

        }

        else
        {
            cout << a-'0' + b-'0' << "\n";
        }
    }
}

int main ()
{
    solution();
    return 0;
}