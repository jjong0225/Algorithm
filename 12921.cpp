// 내 코드
#include <string>
#include <vector>
#include <math.h>

using namespace std;
bool checker[1000002] = {0};

int solution(int n) {
    int answer = 0;
    for(int i=2; i<= n; i++)
    {
        if(checker[i] == 0)
        {
            answer++;
            for(int j=i; j<= n/i; j++)
                checker[i*j] = 1;
        }
    }
    return answer;
}

// 배울만한 다른 사람 코드
/*
알고리즘은 비슷
나는 최댓값의 고정 배열사용 / vector 생성자를 통한 동적할당.
생성자의 활용!
*/
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool> tmp(n+1, true);

    for (int i=2; i<n+1; i++) {
        if (tmp[i] == true) {
            for (int j=2; i*j<n+1; j++) tmp[i*j] = false;
            answer++;
        }
    }

    return answer;
}