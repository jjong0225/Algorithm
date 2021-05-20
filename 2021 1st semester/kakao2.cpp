#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <math.h>

using namespace std;

vector<string> input_v;
vector<string> origin_v;
vector<string> tmp_v;

long long int string_to_int(string ex)
{
    long long return_val = 0;
    int i=0;
    if(ex[0] == '-')
    {
        i = 1;
    }        
    for(; i<ex.length(); i++)
    {
        return_val *= 10;
        return_val += (ex[i] - '0');
    }
    if(ex[0] == '-')
    {
        return_val *= -1;
    }        
    return return_val;
}

string int_to_string(long long tin)
{
    string a, b;
    if(tin < 0)
    {
        b.push_back('-');
        tin *= -1;
    }
    while(tin > 0)
    {
        a.push_back((tin%10) + '0');
        tin = tin / 10;
    }
    for(int i=a.length()-1; i>=0; i--)
        b.push_back(a[i]);
    return b;
}

void add_all()
{
    tmp_v.clear();
    long long tmp_val = 0;
    for(int i=0; i<input_v.size(); i++)
    {
        if(i%2 == 0)
            tmp_val = string_to_int(input_v[i]);
        else
        {
            if(input_v[i][0] == '+')
                tmp_val += string_to_int(input_v[++i]);
            else
            {
                tmp_v.push_back(int_to_string(tmp_val));
                tmp_v.push_back(input_v[i]);
                tmp_val = 0;
            }
        }
    }
    tmp_v.push_back(int_to_string(tmp_val));
}

void mul_all()
{
    tmp_v.clear();
    long long tmp_val = 1;
    for(int i=0; i<input_v.size(); i++)
    {
        if(i%2 == 0)
            tmp_val = string_to_int(input_v[i]);
        else
        {
            if(input_v[i][0] == '*')
                tmp_val *= string_to_int(input_v[++i]);
            else
            {
                tmp_v.push_back(int_to_string(tmp_val));
                tmp_v.push_back(input_v[i]);
                tmp_val = 1;
            }
        }
    }
    tmp_v.push_back(int_to_string(tmp_val));
}

void sub_all()
{
    tmp_v.clear();
    long long tmp_val = 0;
    for(int i=0; i<input_v.size(); i++)
    {
        if(i%2 == 0)
            tmp_val = string_to_int(input_v[i]);
        else
        {
            if(input_v[i][0] == '-')
                tmp_val -= string_to_int(input_v[++i]);
            else
            {
                tmp_v.push_back(int_to_string(tmp_val));
                tmp_v.push_back(input_v[i]);
                tmp_val = 0;
            }
        }
    }
    tmp_v.push_back(int_to_string(tmp_val));
}

long long solution(string expression) {
    long long answer = 0;
    string tmp;
    for(int i=0; i<expression.length(); i++)
    {
        if(expression[i] == '+' || expression[i] == '*' || expression[i] == '-')
        {
            input_v.push_back(tmp);
            tmp.clear();

            tmp.push_back(expression[i]);
            input_v.push_back(tmp);
            tmp.clear();
        }
        else
            tmp.push_back(expression[i]);
    }
    input_v.push_back(tmp);

    tmp_v = input_v;
    origin_v = input_v;

    add_all();
    input_v  = tmp_v;
    mul_all();
    input_v  = tmp_v;
    sub_all();
    answer = max(answer, abs(string_to_int(tmp_v[0])));
    
    input_v = origin_v;
    tmp_v = origin_v;
    
    add_all();
    input_v  = tmp_v;
    sub_all();
    input_v  = tmp_v;
    mul_all();
    answer = max(answer, abs(string_to_int(tmp_v[0])));

    input_v = origin_v;
    tmp_v = origin_v;
    
    sub_all();
    input_v  = tmp_v;
    add_all();
    input_v  = tmp_v;
    mul_all();
    answer = max(answer, abs(string_to_int(tmp_v[0])));
    

    input_v = origin_v;
    tmp_v = origin_v;
    
    sub_all();
    input_v  = tmp_v;
    mul_all();
    input_v  = tmp_v;
    add_all();
    answer = max(answer, abs(string_to_int(tmp_v[0])));

    input_v = origin_v;
    tmp_v = origin_v;
    
    mul_all();
    input_v  = tmp_v;
    sub_all();
    input_v  = tmp_v;
    add_all();
    answer = max(answer, abs(string_to_int(tmp_v[0])));

    input_v = origin_v;
    tmp_v = origin_v;
    
    mul_all();
    input_v  = tmp_v;
    add_all();
    input_v  = tmp_v;
    sub_all();
    answer = max(answer, abs(string_to_int(tmp_v[0])));

    
    return answer;
}