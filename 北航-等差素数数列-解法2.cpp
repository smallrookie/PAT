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

        int first, second, third, diff;
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

            diff = second - first;
            if(third - second == diff)
            {
                cout << first << " " << second << " " << third << " ";

                int tmp = second;
                while(third - tmp == diff)
                {
                    tmp = third;
                    third = getNextPrime(x);
                    x = third;
                    if (x > b)
                        break;

                    if(third - tmp == diff)
                        cout << third << " ";
                }
                cout << endl;
            }
            else
                x = first;
        }
    }
    return 0;
}
