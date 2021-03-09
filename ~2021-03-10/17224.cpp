/*
1 ≤ N ≤ 100 문제 개수
1 ≤ L ≤ 50 역량
1 ≤ sub1 ≤ sub2 ≤ 50 문제 별 난이도
K 풀 수 있는 문제 개수

서브태스크 1 : K = N
서브태스크 2 : 0 ≤ K ≤ N

N L K
sub1 sub2 
... (n번 반복)

쉬운걸 풀면 100점
어려운걸 풀면 140점 (공존 불가)

풀 수 있는 어려운 문제
풀 수 있는 쉬운 문제 (단, 어려운 문제를 풀 순 없어야 한다)

*/

#include<iostream>
#include<string>

using namespace std;


int main ()
{
    int N, L, K = 0;
    cin >> N >> L >> K;
    int sub1_counter = 0;
    int sub2_counter = 0;
    for(int i=0; i<N; i++)
    {
        int tmp_1, tmp_2 =0;
        cin >>tmp_1 >> tmp_2;
        if(L >= tmp_2)
        {
            sub2_counter++;
            continue;
        }
        if(L >= tmp_1 && L < tmp_2)
        {
            sub1_counter++;
            continue;
        }
    }
    int output = 0;
    if(sub2_counter >= K)
        output = K * 140;
    else if(sub2_counter + sub1_counter >= K)
        output = sub2_counter*140 + (K-sub2_counter)* 100;
    else if (sub2_counter + sub1_counter < K)
        output = sub2_counter*140 + sub1_counter* 100;
    cout << output;
}