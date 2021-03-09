// 내 풀이
#include <string>
#include <vector>
#include <math.h>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    answer += "김서방은 ";
    int kim_idx = -1;
    for(int i=0; i<seoul.size(); i++)
    {
        if(seoul.at(i).compare("Kim") == 0)
        {
            kim_idx = i;
            break;
        }
    }
    int cmp = pow(10,3);
    int flag = 0;
    for(int i=0; i<=3; i++)
    {
        int tmp_val = kim_idx/cmp;
        if(tmp_val != 0 || flag == 1 || i == 3)
        {
            kim_idx -= tmp_val * cmp;
            tmp_val += '0';
            answer += tmp_val;
            flag = 1;
        }
        cmp = cmp / 10;
    }
    answer += "에 있다";
    return answer;
}


// 좋은 풀이
/*
string의 cmp대신 vector의 find를 통해 쉽게 찾음
int -> string과정에서 각 자리의 수를 노가다로 찾기 보단 to_string()함수 존재

*/
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int pos=find(seoul.begin(),seoul.end(),"Kim")-seoul.begin();
    answer="김서방은 "+to_string(pos)+"에 있다";
    return answer;
}