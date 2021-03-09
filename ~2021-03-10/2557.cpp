/*
String class
Strings are objects that represent sequences of characters.

The standard string class provides support for such objects with an interface similar to that of a standard container of bytes, but adding features specifically designed to operate with strings of single-byte characters.

The string class is an instantiation of the basic_string class template that uses char (i.e., bytes) as its character type, with its default char_traits and allocator types (see basic_string for more info on the template).

Note that this class handles bytes independently of the encoding used: If used to handle sequences of multi-byte or variable-length characters (such as UTF-8), all members of this class (such as length or size), as well as its iterators, will still operate in terms of bytes (not actual encoded characters).

1. incoding 방식에 따라서 문자를 잘못읽을 수 있다. (단 input은 괜찮고, 파일 자체의 인코딩 문제이므로 const string의 문제)
2. string의 모든 함수는 char의 연장이므로 multi-byte의 경우 length, at 등 다양한 함수에서 오류가 날 수 있다.
  // 예를 들어 length의 경우 multi-byte의 특성 상 한 한글당 2로 인식됨
  // at()을 통한 접근도 하나만 하면 오류가나고 두개를 하나의 글자로 인식하고 함께 붙여줘야한다. (할당도 마찬가지)

*/

#include<iostream>
#include<string>

using namespace std;

int main ()
{
    string str = "안녕하세여";
    cout << str.size() << endl;
    cout << str.at(0) << str.at(1) << endl;
    cout << str.at(0) << endl;

    string new_str;
    new_str += str.at(0);
    new_str += str.at(1);
    cout << new_str << endl;



    return 0;
}