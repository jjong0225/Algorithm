/*
N S


첫째 줄에 펜스의 개수 N(1 ≤ N ≤ 50,000)
지민이가 있는 x좌표 S(-100,000 ≤ S ≤ 100,000)

2~N+1번째 줄까지 펜스의 시작 좌표 x와 끝 좌표 x가 공백으로 구분되어 주어진다. (좌표의 범위는 -100,000 이상 100,000 이하이다.)

y축 내려가는 길이는 고려 ㄴㄴ (일정하므로)

예시
       S - 
   +-+-+-+             4번째 펜스
 +-+-+-+ ㅁ -            3번째 펜스
     +-+-+-+           2번째 펜스
   +-+-+-+             1번째 펜스
       - - ㅁ
 |=|=|=*=|=|=|         
-3-2-1 0 1 2 3 

 -> 4번

펜스에는 왼쪽과 오른쪽이 존재한다
펜스는 넘을 수 없고 이 둘중에 하나를 지나야만 한다.
y축 이동의 길이는 0으로 고려할 필요는 없다
반드시 최단거리여야 한다
이전/현재/이후 이렇게 3개만 생걱해선 안되고 전체적으로 봐야한다.
둘다 봐야하는가?
왼쪽과 오른쪽에 대해서 생각해보자
왼쪽 = 0 / 오른쪽 = 1 이라고할때 결과적으로는
01010101011 이런 느낌으로 움직일거같다.
ㅇㅇㅇㅇ
맨 밑에서 부터 생각해볼까?
DP로 가면 될거같은데...

탈출구의 X좌표는 0
4
-> 3 1
-> 2 2
-> 1 3

맨 밑에서 부터 시작하자 (언제나 고정되어 있기 때문에)
오른쪽으로 올라올 때 까지의 최대 길이 / 왼쪽으로 올라올 때 까지의 최대 길이에 대해서 둘다 계산해두자


*/

#include<iostream>
#include<algorithm>
#include <stdlib.h>
using namespace std;

int fence[50002][2] = {0};

int main () 
{
    int N, S = 0;
    cin >> N >> S;
    for(int i=0; i<N; i++)
    {
        cin >> fence[i][0] >> fence[i][1];
    }

    int left_counter = abs(fence[N-1][0]);
    int right_counter = abs(fence[N-1][1]);
    int current_left_pos = fence[N-1][0];
    int current_right_pos = fence[N-1][1];
    for(int i=N-2; i>=0; i--)
    {
        cout << current_left_pos<<":"<<current_right_pos<<endl;
        if(current_right_pos >= fence[i][1] && current_left_pos <= fence[i][0])
            continue;
        else if (current_right_pos <= fence[i][0] || current_left_pos >= fence[i][1])
            continue;
        else if(current_right_pos >= fence[i][1] && current_left_pos > fence[i][0] )
        {
            // 왼쪽만 그냥 갱신
            left_counter = min(left_counter + abs(current_left_pos-fence[i][0]), right_counter + abs(current_right_pos-fence[i][0]));
            current_left_pos = fence[i][0];
        }
        else if(current_left_pos <= fence[i][0] && current_right_pos < fence[i][1])
        {
            // 오른쪽만 갱신
            right_counter = min(right_counter + abs(fence[i][1]-current_right_pos), left_counter + abs(fence[i][1]-current_left_pos));
            current_right_pos = fence[i][1];
        }
        else if(current_right_pos < fence[i][1] && current_left_pos > fence[i][0])
        {
            // 둘다 갱신
            left_counter = min(left_counter + abs(current_left_pos-fence[i][0]), right_counter + abs(current_right_pos-fence[i][0]));
            current_left_pos = fence[i][0];
            right_counter = min(right_counter + abs(fence[i][1]-current_right_pos), left_counter + abs(fence[i][1]-current_left_pos));
            current_right_pos = fence[i][1];
        }
    }
    cout << current_left_pos<<":"<<current_right_pos<<endl;
    cout << min(left_counter+abs(S-current_left_pos), right_counter+abs(S-current_right_pos));
    // cout << left_counter+abs(current_left_pos) << " " <<  right_counter+abs(current_right_pos);
}