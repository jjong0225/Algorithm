#include<iostream>
#include<algorithm>
#include<stack>
#include <cstring>

using namespace std;

long long int charged_money_set[300003] = {0};
long long int b_0 =0;
long long int a_1 =0;
long long int b_1 =0;
long long int max_b_1 =0;

int main ()
{
    memset(charged_money_set, 0, sizeof(charged_money_set));
    
    int n = 0;
    int charged_count = 0;
    int no_charge_flag = 0;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a_1 >> b_1;
        if(a_1 > 0)
        {
            if(b_1 != a_1 + b_0)
            {
                cout << "-1";
                return 0;
            }
        }
        if(a_1 < 0)
        {
            a_1 = a_1 * - 1;
            if( b_0 < a_1 )
            {
                charged_money_set[charged_count] = (a_1 + b_1 - b_0);
                charged_count++;
                if(max_b_1 < b_1)
                    max_b_1 = b_1;
            }
            else
            {
                if(b_1 != b_0 - a_1)
                {
                    cout << "-1";
                    return 0;
                }
            }
        }
        b_0 = b_1;
    }
    if(charged_count == 0)
        no_charge_flag = 1;

    int gcd = 1;
    while(charged_count > 0) // O(logN)
    {
        long long int x_1 = charged_money_set[charged_count--];
        long long int x_2 = charged_money_set[charged_count--];

        int no_gcd_flag = 0;
        long long int tmp_gcd = __gcd(x_1, x_2); // gcd complexity is O(log(a+b)), which is O(10^9)
        if(tmp_gcd <= max_b_1)
        {
            no_gcd_flag = 1;
        }
        charged_money_set[++charged_count] = tmp_gcd;
        if(no_gcd_flag == 1)
        {
            gcd = -1;
            break;
        }
    }
    if(gcd == -1)
    {
        cout << "-1";
    }
    else if (no_charge_flag == 1)
    {
        cout << "1";
    }
    else
    {
        cout << charged_money_set[0];
    }

    return 0;
}

/*
입출금에 따른 자동 충전 금액 산출 프로그램

양의 수 : 입금
음의 수 : 출금 (이때 잔액 부족 시 계좌에서 자동 충전 금액 M만큼 가져온다)

처음 금액은 0원 고정


입출금이 다음과 같이 두 쌍으로 나타남
(입출금액, 연산 이후 잔액)

범위는 다음과 같다
1. 쌍의 개수 N의 범위
	 (1 ≤ N ≤ 300,000)

2. 입출금액과 잔액의 범위
	두 개의 정수 ai 와 bi(-10^18 ≤ ai ≤ 10^18, ai ≠ 0 //  0 ≤ bi ≤ 10^18)

3. 최소 충전 단위 M
	M(1 ≤ M ≤ 9 * 1018)

1. 범위의 문제
10^18은 너무 큼 (int는 10^9 언저리)
데이터 타입 : long long으로!
long long? : -9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807 (약 2 * (0.9 * 10^19)의 범위)
+ int : -2,147,483,648 ~ 2,147,483,647

ㅇㅋ good


2. 어떻게 M을 산출할 것인가?
우선 가능한 M의 수는 다양하다!  (EX: -5 0 일때 M = 1혹은 5일 수도 있다. 즉, M은 출금 시 부족한 돈들의 공약수 들의 교집합)
"공약수"를 키워드로 생각해보자.

총 충전 금액 = 출금 금액 + 출금 후 잔액 - 과거 잔액
X = a(i+1) + b(i+1) - b(i)
	// 단, 과거 잔액이 출금 금액보다 높을 경우에는 그냥 진행

예시 1 : 
5
1500 1500
-17000 4500 (부족한 금액 : x = 20000)
1200 5700
-5600 100 (부족한 금액 : 0원, 즉 그냥 빠져나감)
-200 9900 (부족한 금액 : 10000원)



20000과 10000의 최대공약수는? 10000원 (good)



예시 2 :
2
-5 0 (부족 금액 : 5)
-6 1 (부족 금액 : 7)

7과 5의 최대공약수? 존재 x -> -1 출력
그리고 반드시 그 충전금액 M은 잔액 b_1보다 커야한다
즉, 구해진 M은 충전 시의 잔액인 b_1의 집합보다 반드시 커야한다.



그럼 최소공약수는 어떻게 구할까?
gcd 라이브러리 이용


근데 어떻게 모든 원소들의 gcd를 구할까?
하나의 수가 모두의 divisor가 되어야 하는데
/2 /2 /2 /2 /2 /2
log N번 하게 된다.

*/
