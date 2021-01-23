#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int main ()
{
    int a,b = 0;
    cin >> a >> b;
    int now_pow = 10;
    for(int i=0; i<3; i++)
    {
        cout << a * ((b % now_pow) / (now_pow / 10)) << endl;
        now_pow *= 10;
    }
    cout << a * b;
}