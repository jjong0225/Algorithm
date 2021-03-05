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
int n;
int now_idx = 0;
vector<string>prev_v;
string prev_s = "1";

int gen_seq(int now_length)
{
    string tmp_s = prev_s;
    for(char j='1'; j<='3'; j++)
    {
        string now_string = tmp_s + j;
        bool flag = 0;
        for(int k=1; k<= now_length/2; k++)
        {
            string str_1 = now_string.substr(now_string.length()-k ,k); // 123456 = 6
            string str_2 = now_string.substr(now_string.length()-2*k ,k); // 
            if(str_1.compare(str_2) == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            prev_s = now_string;
            if(now_length == n)
            {
                cout << now_string;
                return 1;
            }
            if(gen_seq(now_length+1))
            {
                return 1;
            }
        }
    }
    prev_s = tmp_s;
    return 0;
}


void solution()
{
    // code
    cin >> n;
    if(n == 1)
    {
        cout << "1";
        return;
    }
    prev_v.push_back("1");
    prev_v.push_back("2");
    prev_v.push_back("3");
    gen_seq(2);
    
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}