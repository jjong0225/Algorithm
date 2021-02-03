#include <string>
#include <vector>
#include<vector>
#include<map>
#include<algorithm>
#include<math.h>
using namespace std;

vector<vector<string>> input_data;
map<string, string> my_map;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    for(int i=0; i<record.size(); i++)
    {
        vector<string> tmp_data;
        string tmp_str;
        tmp_data.push_back(tmp_str);
        for(int j=0; j<record[i].length(); j++)
        {
            if(record[i][j] != ' ')
                tmp_data[tmp_data.size()-1] += record[i][j];
            else
            {
                string noth;
                tmp_data.push_back(noth);
            }
        }
        input_data.push_back(tmp_data);
    }

    for(int i=0; i<input_data.size(); i++)
    {
        if(input_data[i][0].compare("Enter") == 0)
        {
            if(my_map.find(input_data[i][1]) == my_map.end())
                my_map.insert(make_pair(input_data[i][1], input_data[i][2]));
            else
                my_map.find(input_data[i][1])->second = input_data[i][2];
        }
        else if (input_data[i][0].compare("Change") == 0)
        {
            my_map.find(input_data[i][1])->second = input_data[i][2];
        }
    }

    for(int i=0; i<input_data.size(); i++)
    {
        string now_str;
        if(input_data[i][0].compare("Change") == 0)
            continue;
        if(input_data[i][0].compare("Enter") == 0)
            now_str +=  my_map.find(input_data[i][1])->second + "님이 들어왔습니다.";
        else if(input_data[i][0].compare("Leave") == 0)
            now_str += my_map.find(input_data[i][1])->second + "님이 나갔습니다.";
        answer.push_back(now_str);
    }

    return answer;
}

int main ()
{
    iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    cin.tie(NULL);
    cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}


/*

다른사람의 배울만한점
stringstream으로 쉽게 input받음
compare 안쓰고 그냥 ==로 string 비교함
+ 후처리 대신 input받은곳에서 처리

*/
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
using namespace std;


vector<string> solution(vector<string> record) {
    vector<string> answer;
    string command;
    string ID;
    string uid;
   map<string,string> m;


    for(string input:record)
    {
        stringstream ss(input);
        ss>>command;
        ss>>uid;
        if(command=="Enter" || command=="Change")
        {
            ss>>ID;
            m[uid]=ID;
        }
    }

   for(string input:record)
    {
        stringstream ss(input);
        ss>>command;
        ss>>uid;
        if(command=="Enter")
        {
         ID=(m.find(uid)->second);

            string temp = ID+"님이 들어왔습니다.";
         answer.push_back(temp);

        }
      else if(command=="Leave")
      {
         ID=(m.find(uid)->second);
            string temp = ID+"님이 나갔습니다.";
         answer.push_back(temp);
      }
    }
    return answer;
}
