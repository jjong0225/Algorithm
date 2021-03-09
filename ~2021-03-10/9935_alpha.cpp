#include<iostream>
#include<string>

using namespace std;

string target_str, bomb_str;
char result_str[1000004] = {0};

int main ()
{
    cin >> target_str >> bomb_str;
    int insert_pos = 0;
    int bomb_len = bomb_str.length();
    char trigger = bomb_str.at(bomb_len-1);

    for(int i=0; i<target_str.length(); i++)
    {
        result_str[insert_pos++] = target_str.at(i);
        if((target_str.at(i) == trigger) && (i+1 >= bomb_len))
        {
            bool bomb_flag = 1;
            for(int j=1; j<=bomb_len; j++)
            {
                if(result_str[insert_pos-j] != bomb_str.at(bomb_len-j))
                {
                    bomb_flag = 0;
                    break;
                }
            }
            if(bomb_flag == 1)
            {
                insert_pos = insert_pos - bomb_len;
                result_str[insert_pos] = 0;
            }
        }
    }
    if(insert_pos == 0)
        cout << "FRULA";
    else
    {
        for(int i=0; i<insert_pos; i++)
        {
            cout << result_str[i];
        }
    }
    
}