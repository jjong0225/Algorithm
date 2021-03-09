/* 
내 코드
1,4,7 -> 왼손 엄지
3,6,9 -> 오른손 엄지
2,5,8,0 -> 더 가까운 엄지 (만약 같다면 오른손/왼손잡이 여부에 따라 주 손으로 선택됨)
엄지 손가락은 * #에서 시작, 4가지 방향으로만 움직일 수 있음

input 2개
하나는 누르는 번호들
하나는 주 손

결과값 : 번호를 누르는 엄지손가락을 L,R의 연속된 문자열로 표현.
그리디
*/
#include <string>
#include <vector>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    bool right_handed = 1;
    if(hand.compare("left") == 0)
        right_handed = 0;
    int left_hand_pos = 9;
    int right_hand_pos = 11;
    
    for(int i=0; i<numbers.size(); i++)
    {
        int now_num = 0;
        if(numbers[i] != 0)
            now_num = numbers[i]-1;
        else
            now_num = 10;
        if(now_num % 3 == 0)
        {
            answer += "L";
            left_hand_pos = now_num;
            continue;
        }
        else if (now_num % 3 == 2)
        {
            answer += "R";
            right_hand_pos = now_num;
            continue;            
        }
        // now_num % 3 == 1 일때
        int left_hand_move = abs(left_hand_pos%3-now_num%3) + abs(left_hand_pos/3 - now_num/3);
        int right_hand_move = abs(right_hand_pos%3-now_num%3) + abs(right_hand_pos/3 - now_num/3);
        if(right_hand_move < left_hand_move)
        {
            answer += "R";
            right_hand_pos = now_num;
        }
        else if(right_hand_move > left_hand_move)
        {
            answer += "L";
            left_hand_pos = now_num;
        }
        else
        {
            if(right_handed == 1)
            {
                answer += "R";
                right_hand_pos = now_num;                
            }
            else
            {
                answer += "L";
                left_hand_pos = now_num;
            }
        }
    }
    return answer;
}