#include<iostream>
#include<string>
#include<map>
using namespace std;
map<int,char> MBTI = {{0, 'E'}, {1, 'I'}, {2, 'S'},{3, 'N'}, {4,'T'}, {5,'F'}, {6,'J'},{7,'P'}};
map<char,int> MBTI_CODE = {{'E',0}, {'I',1}, {'S',2},{'N',3}, {'T',4}, {'F',5}, {'J',6},{'P',7}};

int main ()
{
    string input_str;
    cin >> input_str;
    int output[5] = {0};
    for(int i=0; i<4; i++)
    {
        output[i] = (!(MBTI_CODE.find(input_str.at(i))->second%2)) + 2 * i;
    }
    for(int i=0; i<4; i++)
    {
        cout <<  MBTI.find(output[i])->second;
    }
    return 0;
}