#include <iostream>
using namespace std;
int PrimeNumber(long long int x)
{
    for (long long int i = 2; i < x - 1; i++)
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}
int Reverse(int x)
{
    int y = 0;
    while (x)
    {
        y = y * 10 + x % 10;
        x /= 10;
    }
    return y;
}
int zadanie1(int m)
{
    int x = 0;
    for (int i = 0; i < m; i++)
    {
        if (i % 3 == 0 or i % 5 == 0)
            x += i;
    }
    return x;
}
int zadanie2(int m)
{
    int f1 = 0;
    int f2 = 1;
    int f3 = f1 + f2;
    int x = 0;
    while (f1 < m)
    {
        if (f1 % 2 == 0)
            x += f1;
        f1 = f2;
        f2 = f3;
        f3 = f1 + f2;
    }
    return x;
}
long long int zadanie3(long long int m)
{
    int max = 0;
    for (long long int i = 2; i <= m; i++)
    {
        if (m % i == 0)
        {
            if (PrimeNumber(i))
                max = i;
            m /= i;
        }
    }
    return max;
}
int zadanie4()
{
    int n = 0;
    for (int i = 100; i < 1000; i++)
    {
        for (int j = 100; j < 1000; j++)
        {
            if (i * j == Reverse(i * j))
            {
                if (i * j > n)
                    n = i * j;
            }
        }
    }
    return n;
}
int zadanie5()
{
    bool flag = true;
    int x = 20;
    while (flag)
    {
        for (int i = 1; i <= 20; i++)
        {
            if (x % i == 0)
                flag = false;
            else
            {
                flag = true;
                x += 20;
                break;
            }
        }
    }
    return x;
}
int main()
{
    printf("1) %d\n", zadanie1(1000));
    printf("2) %d\n", zadanie2(4000000));
    printf("3) %d\n", zadanie3(600851475143));
    printf("4) %d\n", zadanie4());
    printf("5) %d\n", zadanie5());
}
