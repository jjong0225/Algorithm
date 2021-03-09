#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer = arr;
    int min_val = INT_MAX;
    int min_pos = -1;
    for(int i=0; i<arr.size(); i++)
    {
        if (arr.at(i) < min_val)
        {
            min_val = arr.at(i);
            min_pos = i;
        }
    }
    answer.erase(answer.begin()+min_pos);
    if(answer.size() == 0)
    {
        answer.push_back(-1);
    }
    return answer;    
}

// int main ()
// {
//     vector<int> arr = {4,3,2,1};
//     vector<int> sol = solution(arr);
//     for(int i=0; i<sol.size(); i++)
//     {
//         cout << sol.at(i) << endl;
//     }

// }