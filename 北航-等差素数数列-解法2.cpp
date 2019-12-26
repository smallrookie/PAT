/*
* 题目描述：输入为两个数a，b。求出区间[a,b]之间所有相邻素数组成的等差数列。其中a>=2,b<100000
*
**/

#include <iostream>
#include<math.h>

using namespace std;

bool isPrime(int n)
{

    if (n == 1)
        return false;

    int k = sqrt(n);
    for (int i = 2; i <= k; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int getNextPrime(int n)
{
    while(1)
    {
        if(isPrime(n + 1))
            return n + 1;
        else
            n++;
    }
}

int main()
{

    int a,b;
    while (cin >> a >> b)
    {

        int first, second, third, dif;
        int x = a - 1;
        while (x <= b)
        {

            first = getNextPrime(x);
            x = first;
            if(x > b)
                break;

            second = getNextPrime(x);
            x = second;
            if(x > b)
                break;

            third = getNextPrime(x);
            x = third;
            if(x > b)
                break;

            dif = second - first;
            if(third - second == dif)
            {
                cout << first << " " << second << " " << third << " ";

                int tmp = second;
                while(third - tmp == dif)
                {

                    tmp = third;

                    tmp = getNextPrime(x);
                    x = tmp;
                    if (x > b)
                        break;

                    if(tmp - third == dif)
                        cout << tmp << " ";
                }
                cout << endl;
            }
            else
                x = first;
        }
    }
    return 0;
}
