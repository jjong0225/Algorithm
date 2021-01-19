// 내 코드
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    answer.push_back(arr.at(0));
    int ans_pos = 0;
    for(int i=1; i<arr.size(); i++)
    {
        if(arr.at(i) != answer.at(ans_pos))
        {
            answer.push_back(arr.at(i));
            ans_pos++;
        }
    }
    return answer;
}

// 배울점 있는 다른사람의 코드
/*
unique를 통해 연속된 값을 삭제함
Removes all but the first element from every consecutive group of equivalent elements in the range [first,last).


template <class ForwardIterator>
  ForwardIterator unique (ForwardIterator first, ForwardIterator last)
{
  if (first==last) return last;

  ForwardIterator result = first;
  while (++first != last)
  {
    if (!(*result == *first))  // or: if (!pred(*result,*first)) for version (2)
      *(++result)=*first;
  }
  return ++result;
}

여기서, unique해진 vector의 뒤엔 원래 사이즈만큼 다른 값들이 저장되기 때문에 앞선 코드에서 보듯이 그 뒤를 다 삭제해줘야한다.
it = std::unique (myvector.begin(), myvector.end());   // 10 20 30 20 10 ?  ?  ?  ?
                                                                         ^
it는 unique arr 이후 원소를 가리킨다.

*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) 
{

    arr.erase(unique(arr.begin(), arr.end()),arr.end());

    vector<int> answer = arr;
    return answer;
}