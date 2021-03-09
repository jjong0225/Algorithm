/*

아래/위/왼/오 -> 익는다
M X N크기의 상자
익은거 1, 안익은거 0, 토마토 없는거 -1

언제나 걸리는지 (몇일 걸리는지), 만약 불가능하면 -1

모든 익은 토마토가 하루에 다 익어야한다.

2 ≤ M,N ≤ 1,000 

Q?
한번 방문된 것은 다른 모든것을 생각할 필요없이 자식들 다 추가한다음에 사라져도 됨
근데 제일 문제는 어떻게 그 날을 결정할까?
priority_queue로 몇일쓴건지 다 생각한다음에 다 끝난다음 다 끝내버림

마지막에 다 확인한다음에 없으면 ㅇㅋ굿

복잡도에 대해 생각해보자
n*m정도?
<int, <int,int>>로 ㄱㄱ
*/

#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int input_arr[1004][1004] = {0};
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    cin >> M >> N;
    priority_queue<pair<int, pair<int, int>>> pq;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin >> input_arr[i][j];
            if(input_arr[i][j] == 1)
            {
                pq.push(make_pair(0,make_pair(i,j)));
            }
        }
    }
    const int row_offset[3] = {0,1,-1};
    const int col_offset[3] = {0,1,-1};
    int days_min = 100000000;
    while(!pq.empty())
    {
        pair<int, pair<int, int>> now_pair = pq.top();
        int days = now_pair.first;
        int row = now_pair.second.first;
        int col = now_pair.second.second;
        pq.pop();

        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(abs(row_offset[i]) == abs(col_offset[j]) || row + row_offset[i] >= N || row + row_offset[i] < 0 || col + col_offset[j] >=M || col + col_offset[j] < 0)
                    continue;
                if(input_arr[row + row_offset[i]][col + col_offset[j]] == 0)
                {
                    pq.push(make_pair(days-1,make_pair(row + row_offset[i], col + col_offset[j])));
                    input_arr[row + row_offset[i]][col + col_offset[j]] = (days-1) * -1;
                    days_min = min(days_min, days-1);
                }
            }
        }
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(input_arr[i][j] == 0)
            {
                cout << -1;
                return 0;
            }
        }
    }
    if(days_min != 100000000)
        cout << -1*days_min;
    else
        cout << 0;
}