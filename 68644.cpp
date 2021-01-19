// 내 코드
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    bool checker[203] = {0};
    for(int i=0; i<numbers.size(); i++)
    {
        for(int j=i+1; j<numbers.size(); j++)
        {
            checker[numbers.at(i) + numbers.at(j)]=1;
        }        
    }
    for(int i=0; i<203; i++)
    {
        if(checker[i] == 1)
            answer.push_back(i);
    }
    return answer;
}

// 배울 점 있는 타인의 코드
/*
자료구조 set의 특성 (unique, ordered, immutable)을 이용한 코드
compare 함수가 주어지지 않는다면 자동적으로 less (적은게 더 앞에)로 정렬된다.
set -> vector로 할당하는 assign함수도 알아두면 좋을것 같다.
iterator를 인자로 받아서 그 사이의 모든 원소를 포함하는 vector 형성한다 (end는 포함 ㄴㄴ)

*/
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> st;
    for(int i = 0;i<numbers.size();++i){
        for(int j = i+1 ; j< numbers.size();++j){
            st.insert(numbers[i] + numbers[j]);
        }
    }
    answer.assign(st.begin(), st.end());
    return answer;
}
