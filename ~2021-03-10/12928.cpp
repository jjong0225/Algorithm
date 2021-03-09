/*

P_1+P_2+P_3.... = N-2
(P_1(P_1+1)+P_2(P_2+1)...)/2 = S
경우의 수를 모두 커버가 가능한가?

o^n 만큼이라 개오바임

그러면 하나씩 추가가 가능하다고 햇을 때,
ㅇㅋ 그러면 버릴 수 있다고 가정할 때,
최대 하나.
차선 최대 하나
나머지 남은 카운트의 개수가 합보다 작다면 불가능한것!
*/

#include<iostream>

using namespace std;

int main ()
{
    int N,S=0;
    cin >> N >> S;
    if(N <= 2)
    {
        if(S==0)
            cout << 1;
        else
            cout << 0;
        return 0;
    }
    int now_s = S;
    int node_counter = N-2;
    for(int i=N-2; i>=1; i--)
    {
        if(i*(i+1)/2 <= now_s && node_counter >= i)
        {
            now_s = now_s - i*(i+1)/2;
            node_counter = node_counter-i;
            i = i+1;
        }
    }
    if(node_counter >= now_s)
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
}