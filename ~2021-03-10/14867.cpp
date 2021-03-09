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

/*
1,000,000,000 -> 10^9
long long int로 2개 나눠 -> ㅇㅋ
a(1 ≤ a < 100,000)
b(a < b ≤ 100,000)
c(0 ≤ c ≤ a)
d(0 ≤ d ≤ b)
*/


typedef struct bucket
{
    int max_amout;
    int now_amout;
} Bucket;

int a,b,c,d;
Bucket A,B = {0};
queue<array<Bucket,3>> q;


int checker[2][2][100010] = {0}; // [왼쪽? 오른쪽?][반대쪽은 차있나?][그 외엔?] = {횟수}

void solution()
{
    // code
    cin >> a >> b >> c >> d;
    A = {a,0};
    B = {b,0};
    Bucket init_b= {0,0};
    q.push({A,B,init_b});
    int b_flag = 0;
    checker[0][0][0] = 1;
    checker[1][0][0] = 1;
    if(c != 0 && d != 0 && a != c && b != d)
    {
        cout << "-1";
        return;
    }
    if(c == 0 && d == 0)
    {
        cout << 0;
        return;
    }
    while(!q.empty())
    {
        array<Bucket,3> now_arr = q.front();
        q.pop();
        if(now_arr[0].now_amout == c && now_arr[1].now_amout == d)
        {
            b_flag = 1;
            break;
        }

        if(!checker[0][1][now_arr[1].now_amout])
        {
            Bucket tmp_bucket = now_arr[0];
            Bucket count_b = now_arr[2];
            tmp_bucket.now_amout = tmp_bucket.max_amout;
            checker[0][1][now_arr[1].now_amout] = ++count_b.max_amout;
            q.push({tmp_bucket,now_arr[1],count_b});
        }

        if(!checker[1][1][now_arr[0].now_amout])
        {
            Bucket tmp_bucket = now_arr[1];
            Bucket count_b = now_arr[2];
            tmp_bucket.now_amout = tmp_bucket.max_amout;
            checker[1][1][now_arr[0].now_amout] = ++count_b.max_amout;
            q.push({now_arr[0],tmp_bucket,count_b});
        }

        if(!checker[0][0][now_arr[1].now_amout])
        {
            Bucket tmp_bucket = now_arr[0];
            Bucket count_b = now_arr[2];
            tmp_bucket.now_amout = 0;
            checker[0][0][now_arr[1].now_amout] = ++count_b.max_amout;
            q.push({tmp_bucket,now_arr[1],count_b});
        }
        if(!checker[1][0][now_arr[0].now_amout])
        {
            Bucket tmp_bucket = now_arr[1];
            Bucket count_b = now_arr[2];
            tmp_bucket.now_amout = 0;
            checker[1][0][now_arr[0].now_amout] = ++count_b.max_amout;
            q.push({now_arr[0], tmp_bucket,count_b});
        }

        { // bucket1->bucket2
            Bucket tmp_bucket_1 = now_arr[0];
            Bucket tmp_bucket_2 = now_arr[1];
            Bucket count_b = now_arr[2];
            if(tmp_bucket_2.now_amout != tmp_bucket_2.max_amout)
            {
                if(tmp_bucket_1.now_amout + tmp_bucket_2.now_amout <= tmp_bucket_2.max_amout)
                {
                    tmp_bucket_2.now_amout = tmp_bucket_1.now_amout + tmp_bucket_2.now_amout;
                    tmp_bucket_1.now_amout = 0;
                    if(!checker[0][0][tmp_bucket_2.now_amout])
                    {
                        checker[0][0][tmp_bucket_2.now_amout] = ++count_b.max_amout;
                        q.push({tmp_bucket_1, tmp_bucket_2, count_b});
                    }
                }
                else
                {
                    tmp_bucket_1.now_amout = tmp_bucket_1.now_amout - (tmp_bucket_2.max_amout - tmp_bucket_2.now_amout);
                    tmp_bucket_2.now_amout = tmp_bucket_2.max_amout;
                    if(!checker[1][1][tmp_bucket_1.now_amout])
                    {
                        checker[1][1][tmp_bucket_1.now_amout] = ++count_b.max_amout;
                        q.push({tmp_bucket_1, tmp_bucket_2, count_b});
                    }
                }
            }

        }
        
        {
            Bucket tmp_bucket_1 = now_arr[0];
            Bucket tmp_bucket_2 = now_arr[1];
            Bucket count_b = now_arr[2];
            if(tmp_bucket_1.now_amout != tmp_bucket_1.max_amout)
            {
                if(tmp_bucket_2.now_amout + tmp_bucket_1.now_amout <= tmp_bucket_1.max_amout)
                {
                    tmp_bucket_1.now_amout = tmp_bucket_1.now_amout + tmp_bucket_2.now_amout;
                    tmp_bucket_2.now_amout = 0;
                    if(!checker[1][0][tmp_bucket_1.now_amout])
                    {
                        checker[1][0][tmp_bucket_1.now_amout] = ++count_b.max_amout;
                        q.push({tmp_bucket_1, tmp_bucket_2, count_b});
                    }
                }
                else
                {
                    tmp_bucket_2.now_amout = tmp_bucket_2.now_amout - (tmp_bucket_1.max_amout - tmp_bucket_1.now_amout);
                    tmp_bucket_1.now_amout = tmp_bucket_1.max_amout;
                    if(!checker[0][1][tmp_bucket_2.now_amout])
                    {
                        checker[0][1][tmp_bucket_2.now_amout] = ++count_b.max_amout;
                        q.push({tmp_bucket_1, tmp_bucket_2, count_b});
                    }
                }
            }
        }
    }

    vector<array<int,3>> output_pair;
    if(c == 0)
        output_pair.push_back({0,0,d});
    if(c == A.max_amout)
        output_pair.push_back({0,1,d});
    if(d == 0)
        output_pair.push_back({1,0,c});
    if(d == B.max_amout)
        output_pair.push_back({1,1,c});

    int output = 1000000000;
    for(int i=0; i<output_pair.size(); i++)
    {
        array<int,3> tmp_arr = output_pair[i];
        int tmp_int = checker[tmp_arr[0]][tmp_arr[1]][tmp_arr[2]];
        if(tmp_int != 0)
            output = min(output, tmp_int);
    }
    if(output == 1000000000)
        cout << "-1";
    else
        cout << output;
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}