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

n,k = 100,000
DFS?
최악의 경우에는? -> 10만


*/

int N, K;
vector<int> min_v;
int MAX_INT = 1000000000;
// int travle(int X, int num)
// {
//     if(X == K)
//         return num;
//     int output = 1000000000;
//     min_v[X] = num;
//     if(2*X <= K && min_v[2*X] == MAX_INT)
//         output = min(output, travle(2*X, num+1));
//     if(X+1 <= K && min_v[X+1] == MAX_INT)
//         output = min(output, travle(X+1, num+1));
//     if(X-1 >= 0 && min_v[X-1] == MAX_INT)
//         output = min(output, travle(X-1, num+1));
//     return output;
// }

void solution()
{
    // code

    cin >> N >> K;
    int size = max(N,K);
    for(int i=0; i<=2*size; i++)
        min_v.push_back(MAX_INT);
    queue<pair<int,int>> q;
    q.push(make_pair(N,0));
    while(!q.empty())
    {
        pair<int,int> now_pair = q.front();
        q.pop();
        if(min_v[now_pair.first] != MAX_INT)
            continue;
        min_v[now_pair.first] = now_pair.second;
        if(now_pair.first == K)
            break;
        if(now_pair.first <= K && min_v[2*now_pair.first] == MAX_INT)
            q.push(make_pair(2*now_pair.first,now_pair.second+1));
        if(now_pair.first+1 <= K && min_v[now_pair.first+1] == MAX_INT)
            q.push(make_pair(now_pair.first+1,now_pair.second+1));
        if(now_pair.first-1 >= 0 && min_v[now_pair.first-1] == MAX_INT)
            q.push(make_pair(now_pair.first-1,now_pair.second+1));
    }
    cout << min_v[K];
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}