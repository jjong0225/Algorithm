#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<string>
#include<list>
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

bool myfunction (array<int,3>&lp, array<int,3> &rp)
{
    if(lp[0] != rp[0])
        return lp[0] < rp[0];
    else
        return lp[1] < rp[1];
}



struct first_cmp {
    bool operator()(array<int,3>&lp, array<int,3> &rp)
    {
        if(lp[0] != rp[0])
            return lp[0] > rp[0];
        else
            return lp[1] > rp[1];
    }
};

struct second_cmp {
    bool operator()(array<int,3>&lp, array<int,3> &rp)
    {
        if(lp[1] != rp[1])
            return lp[1] > rp[1];
        else
            return lp[0] > rp[0];
    }
};

void solution()
{
    // code
    int input_n;
    cin >> input_n;
    vector<array<int,3>> first_pq;
    priority_queue<array<int,3>, vector<array<int,3>>, second_cmp> second_pq;
    for(int i=1; i<=input_n; i++)
    {
        array<int,3> tmp_input = {0};
        cin >> tmp_input[0] >> tmp_input[1];
        tmp_input[2] = i;
        first_pq.push_back(tmp_input);
    }
    int result = 0;
    int counter = 0;
    int seq = 0;
    sort(first_pq.begin(),first_pq.end(), myfunction);

    while(seq != input_n)
    {
        array<int,3>tmp_arr = first_pq[seq];
        while(!second_pq.empty())
        {
            array<int,3>cmp_arr = second_pq.top();
            if(cmp_arr[1] >= tmp_arr[0])
                break;
            second_pq.pop();
            counter--;
        }
        second_pq.push(tmp_arr);
        counter++;
        result = max(result, counter);
        seq++;
    }
    cout << result << endl;

    priority_queue<array<int,3>, vector<array<int,3>>, second_cmp> third_pq;
    set<int> result_s;
    seq = 0;
    counter = 0;
    while(seq != input_n)
    {
        array<int,3>tmp_arr = first_pq[seq];
        while(!third_pq.empty())
        {
            array<int,3>cmp_arr = third_pq.top();
            if(cmp_arr[1] >= tmp_arr[0])
                break;
            third_pq.pop();
            if(result_s.find(cmp_arr[2]) != result_s.end())
                result_s.erase(cmp_arr[2]);
            counter--;
        }
        third_pq.push(tmp_arr);
        counter++;
        result_s.insert(tmp_arr[2]);
        if(result == counter)
        {
            set<int>::iterator it = result_s.begin();
            while(it != result_s.end())
            {
                cout << *it << " ";
                it++;
            }
            break;
        }
        seq++;
    }
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}