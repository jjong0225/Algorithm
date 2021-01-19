/*
N (1 ≤ N ≤ 500,000
길이 N을 갖는 문자열은 R과 B로 이루어져 있다 (R은 빨간색, B는 파란색)
캔버스에 다음과 같이 한붓그리기 할 때, 그리는 최소 횟수를 나타내라

BBRBRBBR
 흰색이 0, 파란색이 1, 빨간색이 2라고 할 때 
 -> 11212112
 -> 11111111
 -> 11211111
 -> 11212111
 -> 11212112
    4번!

연속된 색을 하나의 문자로만 나타내보자
    -> 11212112
    -> 121212

    그러면 반드시 다음과 같이 1과2 교차의 연속으로 나타날것이다.
    길이는 상관없으니까 그냥 해볼까?
    가장 많은것을 찾아서 칠한다?
    처음부터 찾아서

    첫번째 색이 무조건 그 다음 색의 수보다 많거나 같다
    1(한번에 한색으로) + 두번째 색의 칸 (나머지) 
    1 + N'/2
*/

#include<iostream>
#include<stack>

using namespace std;

int main ()
{
    int N = 0;
    cin >> N;
    stack<int> input_stack;
    input_stack.push(0); // empty 방지를 위해서
    for(int i=0; i<N; i++)
    {
        char tmp_c = 0;
        cin >> tmp_c;
        if(tmp_c == 'B' && (input_stack.top() != 1))
        {
            input_stack.push(1);
        }
        else if(tmp_c == 'R' && (input_stack.top() != 2))
        {
            input_stack.push(2);
        }
    }
    if(input_stack.size() == 1)
    {
        cout << 0;
    }
    else
    {
        cout << (1 + ((input_stack.size()-1)/2));
    }
    return 0;    
}