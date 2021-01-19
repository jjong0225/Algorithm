/*
1000000 // 100만
100000000000 // 1억
1000000000000 // 100만의 제곱

O(NlogN) 이하여야 한다! O(N^2)는 안된다


string의 find기능의 복잡도가 N정도라고 한다.


N : 1000000 // 100만
M : 36

단어를 찾는것의 복잡도를 x라고 할때,
최대 지워야 할 수는 N
O(NX)

그러면 이 단어를 찾는 복잡도를 최대한 줄여야 한다 (적어도 N은 되면 안된다!)
그럼 메모리를 사용해야 하는건가?
scan all?()

걍 뒤에서 부터 찾아서 계속 하면 될거같긴한데?

음 모르겠다...

결국에는 그 첫 글자의 위치는 계속 바껴야 한다.
um....
pop?

erase 하는걸 바꿔서
compare할때 다른 방식으로?
음...

나중에 다시 해보자
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;
vector<int> first_letter_place;

int main()
{
    string target_str, bomb_str;
    cin >> target_str >> bomb_str;
    int bomb_len = bomb_str.size();

    char first_letter = bomb_str.at(0);
    for(int i=0; i<target_str.size(); i++)
    {
        if(target_str.at(i) == first_letter)
        {
            first_letter_place.push_back(i);
        }
    }
    while(1)
    {
        int bomb_count = 0;
        for(int i=first_letter_place.size()-1; i>=0; i--)
        {
            if(target_str.compare(first_letter_place[i],bomb_len, bomb_str) == 0)
            {
                target_str.erase(first_letter_place[i],bomb_len);
                bomb_count++;
                for(int j=i+1; j<first_letter_place.size(); j++)
                {
                    if(first_letter_place[j] < first_letter_place[i]+bomb_len)
                    {
                        first_letter_place.erase(first_letter_place.begin()+j);
                    }
                    else
                    {
                        first_letter_place[j] = first_letter_place[j] - bomb_len;
                    }
                }
                first_letter_place.erase(first_letter_place.begin()+i);
            }
        }
        if(bomb_count == 0)
            break;
    }
    if(target_str.length() == 0)
        cout << "FRULA";
    else
        cout << target_str;
}



