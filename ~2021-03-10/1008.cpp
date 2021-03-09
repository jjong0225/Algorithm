#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;

int main ()
{
    int a,b = 0;
    cin >> a >> b;
    printf("%.10lf", (double)a/(double)b);
}