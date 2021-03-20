#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<string>
#include<list>
#include<vector>
#include<stack>
#include<queue> // priority_queue 포함
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>

#include<algorithm>
#include<math.h>
#include<climits> // 자료형 limit포함

using namespace std;

typedef long long int lld;
typedef unsigned long long int uld;
typedef unsigned int ui;

const int MY_INT_MAX = 2000000000;

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

// template <typename T>
// vector<T> get_data(vector<char> byte_vector, T param_data)
// {
//     int byte_size = sizeof(param_data);
//     vector<T> return_v;
//     for(int i=0; i<byte_vector.size()/byte_size; i++)
//     {   
//         T tmp_data = 0;
//         tmp_data = tmp_data | byte_vector[(i+1)*byte_size -1];
//         cout << "asdf:" << tmp_data << "\n";
//         for(int j=byte_size-2; j>=0; j--)
//         {
//             tmp_data = tmp_data << 8;
//             tmp_data = tmp_data | byte_vector[i*byte_size + j];
//         }
//         return_v.push_back(tmp_data);
//     }
//     return return_v;
// }


template <typename T>
T bit_operator(T original_data, string byte_string)
{
    T return_data = original_data;
    for(int i=0; i<8; i++)
    {
        return_data = return_data << 1;
        return_data = return_data | (byte_string[i]);
        // printf("read %d\n", (byte_string[i]));
    }
    return return_data;
}



template <typename T>
vector<T> get_data(vector<string> byte_vector, T param_data)
{
    int byte_size = sizeof(param_data);
    vector<T> return_v;
    for(int i=0; i<byte_vector.size()/byte_size; i++)
    { 
        T tmp_data = 0;
        for(int j=0; j<byte_size; j++)
            tmp_data = bit_operator(tmp_data, byte_vector[i*byte_size + j]);
        return_v.push_back(tmp_data);
    }
    cout << "-------------\n";
    return return_v;
}



void solution()
{
    // code
    string input_str;
    cin >> input_str;

    vector<string> byte_vector;
    for(int i=0; i < input_str.size()/8; i++)
    {
        string tmp_char;
        tmp_char.push_back((input_str[i*8 + 0] - '0'));
        for(int j=1; j<8; j++)
            tmp_char.push_back(input_str[i*8 + j] - '0');
        byte_vector.push_back(tmp_char);
    }


    char param_char = 1;
    vector<char> char_v = get_data(byte_vector, param_char);
    for(int i=0; i<char_v.size(); i++)
    {
        printf("%d ", char_v[i]);
    }
    cout << endl;


    int param_int = 1;
    vector<int> int_v = get_data(byte_vector, param_int);
    for(int i=0; i<int_v.size(); i++)
    {
        printf("%d ", int_v[i]);
    }
    cout << endl;


}

int main ()
{
    // iostream::sync_with_stdio(0); // 이제 C stdio의 입출력 사용 불가
    // cin.tie(NULL);
    // cout.tie(NULL); // 개행도 \n로 하도록 하자.
    solution();
    return 0;
}