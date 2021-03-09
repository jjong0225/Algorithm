/*
String class
Strings are objects that represent sequences of characters.

The standard string class provides support for such objects with an interface similar to that of a standard container of bytes, but adding features specifically designed to operate with strings of single-byte characters.

The string class is an instantiation of the basic_string class template that uses char (i.e., bytes) as its character type, with its default char_traits and allocator types (see basic_string for more info on the template).

Note that this class handles bytes independently of the encoding used: If used to handle sequences of multi-byte or variable-length characters (such as UTF-8), all members of this class (such as length or size), as well as its iterators, will still operate in terms of bytes (not actual encoded characters).

1. incoding ��Ŀ� ���� ���ڸ� �߸����� �� �ִ�. (�� input�� ������, ���� ��ü�� ���ڵ� �����̹Ƿ� const string�� ����)
2. string�� ��� �Լ��� char�� �����̹Ƿ� multi-byte�� ��� length, at �� �پ��� �Լ����� ������ �� �� �ִ�.
  // ���� ��� length�� ��� multi-byte�� Ư�� �� �� �ѱ۴� 2�� �νĵ�
  // at()�� ���� ���ٵ� �ϳ��� �ϸ� ���������� �ΰ��� �ϳ��� ���ڷ� �ν��ϰ� �Բ� �ٿ�����Ѵ�. (�Ҵ絵 ��������)

*/

#include<iostream>
#include<string>

using namespace std;

int main ()
{
    string str = "�ȳ��ϼ���";
    cout << str.size() << endl;
    cout << str.at(0) << str.at(1) << endl;
    cout << str.at(0) << endl;

    string new_str;
    new_str += str.at(0);
    new_str += str.at(1);
    cout << new_str << endl;



    return 0;
}