// 내 코드
/*
qsort 사용 시 받는 파라미터의 순서를 잘 기억하자
compare 함수 작성 시 const void *인거 다시한번 기억하고
a,b가 차례대로 있을 때 compare함수의 return값이 1인 경우에 교환을 하고 그 외에는 하지 않는다.

c++에 정의된 sort함수의 경우 반대로 리턴값이 1인 경우에는 교환하지 않고 -1인 경우에는 교환한다
less -> Binary function object class whose call returns whether the its first argument compares less than the second (as returned by operator <).
그래서 이 less함수를 쓰면 오름차순으로 정렬되고 (왼쪽이 가장 값이 작고)
greater함수를 쓰면 내림차순 정렬되고 (왼쪽이 가장 값이 크다)


개선점 2. c의 qsort -> c++의 std::sort
실제로 C의 qsort()와 C++의 sort()를 비교하면,C++의 sort()가 압도적으로 빠르다.
C++의 sort()는 손으로 직접 구현한 퀵 소트보다 20% ~ 50% 가량 더 빠르며,
C의 qsort()보다는 250% ~ 1,000% 더 빠르다.
만약 100만 개의 element를 지닌 배열을 정렬할 시,C의 qsort()는 실행시간 0.247883초,C++의 sort()는 실행시간 0.086125초가 걸리게 된다.
그 이유는 다음과 같다.
첫 번째,C++의 sort()는,int 컨테이너의 sort()는 기본적으로 std::less::operator()를 사용하도록 컴파일되며, inline 함수화되고, sort() 함수는 정수를 직접 비교하게 된다.
두 번째,C언어의 qsort()는,함수 포인터가 매번의 정수 비교마다 간접적으로 호출되며, 이 오버헤드로 인해 현저한 속도 차이를 보이게 된다. 즉, 컴파일러의 최적화 실패 사례이다.
심지어 속도 차이뿐만이 아니라,type-safety마저 C언어의 qsort()가 밀린다.template화된 C++의 sort()는 불안전한 void 포인터로 데이터 항목에 접근할 필요가 없기에 type-safe하지만,C언어의 qsort()는 void 포인터로 데이터 항목에 접근을 해야만 하기 때문에 type-safe하지 못하다.
 

*/
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

int comp(const void *a, const void *b)
{
    if(*(int *)a < *(int *)b) return -1;
    else if(*(int *)a == *(int *)b) return 0;
    else if(*(int *)a > *(int *)b) return 1;
    return 0;
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int count=0; count<commands.size(); count++)
    {
        int i = commands.at(count).at(0);
        int j = commands.at(count).at(1);
        int k = commands.at(count).at(2);
        int tmp_v[104] = {0};
        int tmp_cnt = 0;
        for(int l=i-1; l<j; l++)
            tmp_v[tmp_cnt++] = array.at(l);            

        qsort(tmp_v, j-i+1, sizeof(int), comp);
        answer.push_back(tmp_v[k-1]);
    }
    return answer;
}

//남의 코드
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;

    for(int i = 0; i < commands.size(); i++) {
        temp = array;
        sort(temp.begin() + commands[i][0] - 1, temp.begin() + commands[i][1]);
        answer.push_back(temp[commands[i][0] + commands[i][2]-2]);
    }

    return answer;
}

/*
qsort -> sort로 속도 상승
.at()을 이용한 vector접근보다 직관적인 [][]을 이용하여 원소 접근
*/
