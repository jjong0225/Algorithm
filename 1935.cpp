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

void solution()
{
    // code
    int n;
    cin >> n;
    string input_str;
    vector<int> input_v;
    cin >> input_str;
    for(int i=0; i<n; i++)
    {
        int input_d;
        cin >> input_d;
        input_v.push_back(input_d);
    }
    stack<double> s;
    double output = 0;
    for(int i=0; i<input_str.length(); i++)
    {
        if(input_str[i] >= 'A' && input_str[i] <= 'Z')
            s.push(input_v[input_str[i]-'A']);
        else
        {
            double a,b,c = 0;
            b=s.top(), s.pop();
            a=s.top(), s.pop();
            if(input_str[i] == '*')
                c = a*b;
            else if(input_str[i] == '+')
                c = a+b;
            else if(input_str[i] == '/')
                c = a/b;
            else if(input_str[i] == '-')
                c = a-b;
            s.push(c);
        }
    }
    printf("%.2lf", s.top());
}

int main ()
{
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}